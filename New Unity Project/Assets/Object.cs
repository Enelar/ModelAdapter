using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class MObject
{
    [DllImport("ExceptionSafeModel.dll",
      EntryPoint = "?NEGetDouble@@YANHH@Z",
      CharSet = CharSet.Ansi,
      CallingConvention = CallingConvention.Cdecl)]
    private static extern double GetDouble(int h, int id);

    [DllImport("ExceptionSafeModel.dll",
      EntryPoint = "?NEGetDouble@@YANHPBD@Z",
      CharSet = CharSet.Ansi,
      CallingConvention = CallingConvention.Cdecl)]
    private static extern double GetDouble(int h, char[] str);

   [DllImport("ExceptionSafeModel.dll",
      EntryPoint = "?NEDestructObject@@YAXH@Z",
      CharSet = CharSet.Ansi,
      CallingConvention = CallingConvention.Cdecl)]
    private static extern void Destruct(int h);

    public MObject(int _handle)
    {
      handle = _handle;
    }

    ~MObject()
    {
      Destruct(handle);
    }

    public double GetDouble( int param )
    {
      return GetDouble(handle, param);
    }


    private int handle;
}