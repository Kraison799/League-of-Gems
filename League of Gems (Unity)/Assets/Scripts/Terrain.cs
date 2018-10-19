using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class Terrain : MonoBehaviour {
	/*[DllImport("liblib.so")]
	static extern void SendListAdder(Action<int,int> action);
	[DllImport("liblib.so")]
    static extern void SendPositions(float xi,float yi,float xf, float yf);*/
	List<Vector3> positions = new List<Vector3>();

	GameObject player;
	GameObject cpu;
	public GameObject click;
	// Use this for initialization
	void Start () {
		player = GameObject.FindGameObjectWithTag("Player");
		cpu = GameObject.FindGameObjectWithTag("cpu");
	}
	
	// Update is called once per frame
	void Update () {
		  
	}
    // Update
	void FixedUpdate(){
		if (Input.GetMouseButtonDown(1)){
            Vector3 mouse_pos = mousePos();
			Vector3 player_pos = playerPos();
			AddToList(player_pos, mouse_pos);
			GameObject particle = Instantiate(click, mouse_pos, transform.rotation);
			Destroy(particle, 3f);
        }
		if (positions.Count > 0){
			setPlayerPos(positions[0]);
			positions.RemoveAt(0);
		}
	}
    /// <summary>
    /// Sends the mouse and the player's position to c++ code and recieves the pathfinding list.
    /// </summary>
    /// <param name="init">Init.</param>
    /// <param name="finit">Finit.</param>
	void AddToList(Vector3 init, Vector3 finit){
		SendPositions(init.x/4, init.z/4, finit.x/4, finit.z/4);
		SendListAdder(iWasCalled);    
	}
    /// <summary>
    /// Gets the position of the mouse throwing a ray that collides with the ground.
    /// </summary>
    /// <returns>The position.</returns>
	Vector3 mousePos(){
		RaycastHit hit;
        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);

		if (Physics.Raycast(ray, out hit) && hit.transform.tag.Equals("Ground"))
        {
            return hit.point;
        }
		return new Vector3(0f,0f,0f);
	}
    /// <summary>
    /// Gets the player position from his attributtes.
    /// </summary>
    /// <returns>The position.</returns>
	Vector3 playerPos(){
		return player.GetComponent<Player>().Selectedhorde.GetComponent<Rigidbody>().position;
	}
    /// <summary>
    /// Sets the player position to the first on the list
    /// </summary>
    /// <param name="newPos">New position.</param>
	void setPlayerPos(Vector3 newPos){
		player.GetComponent<Player>().Selectedhorde.GetComponent<Horde>().Move(newPos);
        
	}
	void iWasCalled(int x, int y){
		positions.Add(new Vector3(x*4,0.25f,y*4));
	}
}
