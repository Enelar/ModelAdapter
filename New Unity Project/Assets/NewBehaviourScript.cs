using UnityEngine;
using System.Collections;

public class NewBehaviourScript : MonoBehaviour {
	Model mod;
	MObject obj;
	
	// Use this for initialization
	void Start () {
//		bool a = UnityEditorInternal.InternalEditorUtility.HasPro();
		mod = new Model();
		Debug.Log(Model.Status());
		Debug.Log(Model.GetLastExceptionString());
		if (Model.Status() != 0)
			return;		
		obj = mod.Get("Z-15");		
		Debug.Log(Model.Status());
		Debug.Log(Model.GetLastExceptionString());
		
	}
	
	// Update is called once per frame
	void Update () {
		if (Model.Status() != 0)
			return;
		float val = (float)obj.GetDouble(0);
		Debug.Log(val);
		Quaternion q = transform.rotation;
		Vector3 v = q.eulerAngles;
		v.z = 360f * val + Time.time;
		q.eulerAngles = v;
		transform.rotation = q;
	}
}
