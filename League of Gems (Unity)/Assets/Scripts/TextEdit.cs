using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.Runtime.InteropServices;

public class TextEdit : MonoBehaviour {
	[DllImport("liblib.so")]
	static extern int Add(int a, int b);
	Text text;
	// Use this for initialization
	void Start () {
		text = GetComponent<Text>();
	}
	
	// Update is called once per frame
	void Update () {
		text.text = Add(4, 2).ToString();
	}
}
