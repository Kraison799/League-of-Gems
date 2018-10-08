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
	//public List<GameObject> minionList = new List<GameObject>(); 
	// Use this for initialization
	void Start () {
		//createMinions(64);
		for (int i = 0; i < 64; i++){
			GameObject minion = Instantiate(minions, new Vector3(i, 0.25f, i) * 3f, transform.rotation,transform);
			//minion.GetComponent<Movement>().setMinionC(getMinion(i));
			//minionList.Add(minion);
		}
	}
	
	// Update is called once per frame
	void Update () {
		/*if (Input.GetKey(KeyCode.W)){
			transform.Translate(Vector3.forward);
		}*/
    }
    /// <summary>
    /// Move the specified new_position.
    /// </summary>
    /// <param name="new_position">New position.</param>
	public void Move(Vector3 new_position)
    {
		//Jump
		/*foreach (GameObject min in minionList)
        {
            min.GetComponent<Rigidbody>().AddForce(Vector3.up * 0.1f, ForceMode.Impulse);

        }*/
		//Tranlate position
		GetComponent<Rigidbody>().MovePosition(new_position*speed);

    }
}