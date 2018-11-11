using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraMovement : MonoBehaviour {
	public bool cameraLocked = false;
	GameObject player;
	// Use this for initialization
	void Start () {
		player = GameObject.FindGameObjectWithTag("Player");
		cameraLocked = true;
	}

	// Update is called once per frame
	void Update () {
		changeCameraLock();
		movement();
    
    }
    /// <summary>
    /// Changes the camera lock.
    /// </summary>
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
    /// <summary>
    /// Movement this instance.
    /// </summary>
	void movement(){
		
		if (cameraLocked){
			transform.position = (playerPos() + new Vector3(-20f, 20f, 3));
		}else{
			if (Input.mousePosition.x <= 1f){
				transform.position = (transform.position + new Vector3(0f, 0f, 1f));
			}
			if (Input.mousePosition.y <= 1f){
				transform.position = (transform.position - new Vector3(1f, 0f, 0f));
			}
			if (Input.mousePosition.x >= Screen.width-1)
            {
                transform.position = (transform.position - new Vector3(0f, 0f, 1f));
            }
			if (Input.mousePosition.y >= Screen.height-1)
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
			return player.GetComponent<Player>().Selectedhorde.transform.position;
    }
}