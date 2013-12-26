using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class Model
{
	public static char[] ToASCII(string str)
	{
	  char[] ret = new char[str.Length + 1];
	  int i;
		/*
	  for (i = 0; i < str.Length / 2; i+=2)
	    ret[i/2] = (char)(str[i + 1] + str[i] << 8);
	  if ((str.Length & 1) == 1)
		ret[i/2] = (char)(str[i] << 8);
		*/
		for (i = 0; i < str.Length; i++)
			ret[i] = str[i];
	  return ret;	  
	}
	
	void Start()
	{
//	  Model p = new Model();
	 // int a = p.GetID("421415rfdgtrg");
//	  Object obj = p.Get("Z-15");
	 // double test = obj.GetDouble();
		

	}
	
	[DllImport("ExceptionSafeModel.dll",
	  EntryPoint="?NEConstruct@@YAHXZ")]
	private static extern int Constructor();
	
	[DllImport("ExceptionSafeModel.dll",
	  EntryPoint = "?NEDestruct@@YAXH@Z",
	  CharSet = CharSet.Ansi,
	  CallingConvention = CallingConvention.Cdecl)]
	private static extern void Destructor(int a);
	
	[DllImport("ExceptionSafeModel.dll",
	  EntryPoint = "?NEGet@@YAHHPB_W@Z",
	  CharSet = CharSet.Unicode,
	  CallingConvention = CallingConvention.Cdecl)]
	private static extern int Get(int h, char []a);
	
	[DllImport("ExceptionSafeModel.dll",
	  EntryPoint = "?NEGet@@YAHHH@Z",
	  CharSet = CharSet.Ansi,
	  CallingConvention = CallingConvention.Cdecl)]
	private static extern int Get(int h, int id);
	
	[DllImport("ExceptionSafeModel.dll",
	  EntryPoint = "?NEGetID@@YAHHPBD@Z",
	  CharSet = CharSet.Ansi,
	  CallingConvention = CallingConvention.Cdecl)]
	private static extern int GetID(int h, char []str);
	
	[DllImport("ExceptionSafeModel.dll",
	  EntryPoint = "?Status@@YAHXZ",
	  CharSet = CharSet.Ansi,
	  CallingConvention = CallingConvention.Cdecl)]
	public static extern int Status();
	
	[DllImport("ExceptionSafeModel.dll",
	  EntryPoint = "?GetLastExceptionString@@YA_NPA_WH@Z", //YAPBDXZ",
	  CharSet = CharSet.Ansi,
	  CallingConvention = CallingConvention.Cdecl)]
	private static extern bool _GetLastExceptionString([In, Out] char [] str, int len);	
	
	public static string GetLastExceptionString()
	{
		char []arr = new char[100];
		_GetLastExceptionString(arr, 100);
		return new string(arr);
		//return Marshal.PtrToStringAnsi(_GetLastExceptionString());
	}
	
	public Model()
	{
	  handle = Constructor();
	  Debug.Log(Status());
	}
	
	~Model()
	{
	  Destructor(handle);
	}
	
	public int GetID(string name)
	{
	  return GetID(handle, ToASCII(name));
	}
	
	public MObject Get(string name)
	{
		char []n = ToASCII(name);
	  int id = Get (handle, n);
		return new MObject(id);
	}
	
	public MObject Get(int id)
	{
	  return new MObject(Get(handle, id));
	}

  private int handle;
}
