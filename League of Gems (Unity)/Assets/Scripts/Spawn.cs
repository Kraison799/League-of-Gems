using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;
using System;

public class Spawn : MonoBehaviour {
	//C++ Libraries
	/*[DllImport("liblib.so")]
	static extern void createMinions(int min);
	[DllImport("liblib.so")]
	static extern IntPtr getMinion(int pos);*/
    //Methods
	public float speed = 10f;
	public GameObject minions;


	// Use this for initialization
	void Start () {
		//createMinions(64);
		for (int i = 0; i < 64; i++){
			Vector3 position = setPosition(i);
			GameObject minion = Instantiate(minions, position+transform.position, transform.rotation,transform);
		}  
	}
	
	// Update is called once per frame
	void Update () {
		
    }
    /// <summary>
    /// Move the specified new_position.
    /// </summary>
    /// <param name="new_position">New position.</param>
	public void Move(Vector3 new_position)
    {
		GetComponent<Rigidbody>().MovePosition(new_position*speed);
    }
	Vector3 setPosition(int i){
		float z = 0;
		if (i < 8){
			z = 0f;
		}else if (i < 16)
        {
            z = 1f;
		}else if (i < 24)
        {
            z = 2f;
		}else if (i < 32)
        {
            z = 3f;
		}else if (i < 40)
        {
            z = 4f;
		}else if (i < 48)
        {
            z = 5f;
		}else if (i < 56)
        {
            z = 6f;
		}else if (i < 64)
        {
            z = 7f;
        }
		return new Vector3(i%8,0.25f,z) * 3;
	}
}