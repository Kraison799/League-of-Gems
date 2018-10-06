using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Terrain : MonoBehaviour {

	List<Vector3> positions = new List<Vector3>();

	GameObject player;

	// Use this for initialization
	void Start () {
		player = GameObject.FindGameObjectWithTag("minions");
	}
	
	// Update is called once per frame
	void Update () {
		  
	}
    // Update
	void FixedUpdate(){
		if (Input.GetMouseButtonDown(1)){
            Vector3 mouse_pos = mousePos();
			Vector3 player_pos = playerPos();
			AddToList(mouse_pos, player_pos);
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
        //Lista para probar
		for (int i = 0; i < 10; i++)
        {
            positions.Add(new Vector3(10f * i, 0f, 10f * i));
        }
	}
    /// <summary>
    /// Gets the position of the mouse throwing a ray that collides with the ground.
    /// </summary>
    /// <returns>The position.</returns>
	Vector3 mousePos(){
		RaycastHit hit;
        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);

        if (Physics.Raycast(ray, out hit) && hit.transform.tag == "Ground")
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
		return player.transform.position;
	}
    /// <summary>
    /// Sets the player position to the first on the list
    /// </summary>
    /// <param name="newPos">New position.</param>
	void setPlayerPos(Vector3 newPos){
		player.GetComponent<Spawn>().Move(newPos);
        
	}
}
