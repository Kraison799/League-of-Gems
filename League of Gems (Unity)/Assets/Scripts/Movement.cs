using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour {
	public Color color;
	// Use this for initialization
	void Start () {
		GetComponent<Renderer>().material.color = color;
	}
	
	// Update is called once per frame
	void Update () {
		Move(new Vector3(4f, 0f, 0f) );
	}
    
	public void Move(Vector3 new_position){
		transform.Translate(new_position* Time.deltaTime);	
	}
}
