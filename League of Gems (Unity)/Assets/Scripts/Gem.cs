using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gem : MonoBehaviour {
	bool up = true  ;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void FixedUpdate () {
		transform.Rotate(new Vector3(0f,5f,0f));
		changeBool();
		translateGem();
        
	}
    /// <summary>
    /// Changes the bool.
    /// </summary>
	void changeBool(){
		if (transform.position.y < 10)
        {
            up = true;
        }
        else if (transform.position.y > 13)
        {
            up = false;
        }
	}
	void translateGem(){
		if (up)
        {
			transform.position = transform.position + Vector3.up*0.1f;
        }
        else
        {
			transform.position = transform.position + Vector3.down*0.1f;
        }
	}
}
