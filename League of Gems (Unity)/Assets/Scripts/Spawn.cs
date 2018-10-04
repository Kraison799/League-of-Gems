using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spawn : MonoBehaviour {
	public GameObject minions;
	// Use this for initialization
	void Start () {
		for (int i = 0; i < 15; i++){
			GameObject minion = Instantiate(minions, transform.position, transform.rotation);
		}
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
