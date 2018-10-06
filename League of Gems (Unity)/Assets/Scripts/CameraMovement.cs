using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraMovement : MonoBehaviour {
	public bool cameraLocked;
	GameObject player;
	// Use this for initialization
	void Start () {
		player = GameObject.FindGameObjectWithTag("minions");
		cameraLocked = false;
	}

	// Update is called once per frame
	void Update () {
		changeCameraLock();
		movement();
    
    }
	void changeCameraLock(){
		if (Input.GetKeyDown(KeyCode.Y)){
			if (cameraLocked == true){
				cameraLocked = false;
			}
			else{
				cameraLocked = true;
			}
        }
	}
	void movement(){
		if (cameraLocked){
			transform.position = (playerPos() + new Vector3(-10f, 10f, 3));
		}else{
			if (Input.mousePosition.x <= 0f){
				transform.position = (transform.position + new Vector3(0f, 0f, 1f));
			}
			if (Input.mousePosition.y <= 0f){
				transform.position = (transform.position - new Vector3(1f, 0f, 0f));
			}
			if (Input.mousePosition.x >= Screen.width)
            {
                transform.position = (transform.position - new Vector3(0f, 0f, 1f));
            }
			if (Input.mousePosition.y >= Screen.height)
            {
                transform.position = (transform.position + new Vector3(1f, 0f, 0f));
            }
		}
	}
    /// <summary>
    /// Gets the player position from his attributtes.
    /// </summary>
    /// <returns>The position.</returns>
    Vector3 playerPos()
    {
			return player.transform.position;
    }
}