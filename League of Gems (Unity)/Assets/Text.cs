using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using System.Runtime.InteropServices;

public class Text : MonoBehaviour {
	[DllImport("liblib.so")]
	static extern int Add (int a, int b);
	Text nel;
	// Use this for initialization
	void Start () {
		nel = GetComponent<Text>();
	}
	
	// Update is called once per frame
	void Update () {
		nel.text = Add(4,2).ToString;
	}
}
