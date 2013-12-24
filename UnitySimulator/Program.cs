using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Reflection;

namespace UnitySimulator
{
  unsafe class Object
  {
    [DllImport("ModelProxy.dll",
      EntryPoint = "?GetDouble@@YANHH@Z",
      CharSet = CharSet.Ansi,
      CallingConvention = CallingConvention.Cdecl)]
    private static extern double GetDouble(int h, int id);

    [DllImport("ModelProxy.dll",
      EntryPoint = "?GetDouble@@YANHPBD@Z",
      CharSet = CharSet.Ansi,
      CallingConvention = CallingConvention.Cdecl)]
    private static extern double GetDouble(int h, char[] str);

   [DllImport("ModelProxy.dll",
      EntryPoint = "?DestructObject@@YAXH@Z",
      CharSet = CharSet.Ansi,
      CallingConvention = CallingConvention.Cdecl)]
    private static extern void Destruct(int h);

    public Object(int _handle)
    {
      handle = _handle;
    }

    ~Object()
    {
      Destruct(handle);
    }

    public double GetDouble( int param = 0 )
    {
      return GetDouble(handle, param);
    }


    private int handle;
  }

  unsafe class Program
  {
    public static char[] ToASCII(string str)
    {
      char[] ret = new char[str.Length + 1];
      int i;
      for (i = 0; i < str.Length; i++)
        ret[i] = str[i];
      ret[str.Length] = '\0';
      return ret;
    }

    static void Main(string[] args)
    {
      Program p = new Program();
     // int a = p.GetID("421415rfdgtrg");
      Object obj = p.Get("Z-15");
      double test = obj.GetDouble();
    }

    [DllImport("ModelProxy.dll",
      EntryPoint="?Construct@@YAHXZ")]
    private static extern int Constructor();

    [DllImport("ModelProxy.dll",
      EntryPoint = "?Destruct@@YAXH@Z",
      CharSet = CharSet.Ansi,
      CallingConvention = CallingConvention.Cdecl)]
    private static extern void Destructor(int a);

    [DllImport("ModelProxy.dll",
      EntryPoint = "?Get@@YAHHPBD@Z",
      CharSet = CharSet.Ansi,
      CallingConvention = CallingConvention.Cdecl)]
    private static extern int Get(int h, char []a);

    [DllImport("ModelProxy.dll",
      EntryPoint = "?Get@@YAHHH@Z",
      CharSet = CharSet.Ansi,
      CallingConvention = CallingConvention.Cdecl)]
    private static extern int Get(int h, int id);

    [DllImport("ModelProxy.dll",
      EntryPoint = "?GetID@@YAHHPBD@Z",
      CharSet = CharSet.Ansi,
      CallingConvention = CallingConvention.Cdecl)]
    private static extern int GetID(int h, char []str);

    Program()
    {
      handle = Constructor();
    }

    ~Program()
    {
      Destructor(handle);
    }

    public int GetID(string name)
    {
      return GetID(handle, ToASCII(name));
    }

    public Object Get(string name)
    {
      return new Object(Get(handle, ToASCII(name)));//name.ToCharArray()));
    }

    public Object Get(int id)
    {
      return new Object(Get(handle, id));
    }

  private int handle;
  }
}
