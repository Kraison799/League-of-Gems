using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class Terrain : MonoBehaviour {
	[DllImport("liblib.dll")]
	static extern IntPtr getMap(int level);
	[DllImport("liblib.dll")]
	static extern void SendPositions(IntPtr map,int xi, int yi, int xf, int yf);
    [DllImport("liblib.dll")]
	static extern int GetListLenght(IntPtr map);
	[DllImport("liblib.dll")]
	static extern int GetListPosition(IntPtr map);

	public List<Vector3> positions = new List<Vector3>();
	private IntPtr map;
    bool moving = true;
	GameObject player;
	public GameObject click;
	// Use this for initialization
	void Start () {
		Debug.Log("Created");
		player = GameObject.FindGameObjectWithTag("Player");
		map = getMap(5);
	}
	
	// Update is called once per frame
	void Update () {
        if (Input.GetMouseButtonDown(1))
        {
            if (moving)
            {
                moving = false;
                Vector3 mouse_pos = mousePos();
                Vector3 player_pos = playerPos();
                AddToList(mouse_pos, player_pos);
                GameObject particle = Instantiate(click, mouse_pos, transform.rotation);
                Destroy(particle, 3f);
                moving = true;
            }

        }
    }
    // FixedUpdate
	void FixedUpdate(){
		
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
        Debug.Log("Posición de Minions:"+init);
        Debug.Log("Posición de Mouse:"+finit);

		SendPositions(map, (int) finit.x / 10, (int) finit.z / 10, (int)init.x / 10, (int)init.z / 10);
		int lenght = GetListLenght(map)/2;
		for (int i = 0; i < lenght;i++){
            if (i == 0)
            {
                Vector3 pos = new Vector3(GetListPosition(map) * 10, 0.25f, GetListPosition(map) * 10);
                //Debug.Log(pos);
                positions.Add(pos);
            }
            else
            {
                Vector3 old = positions[positions.Count - 1];
                Vector3 pos = new Vector3(GetListPosition(map) * 10, 0.25f, GetListPosition(map) * 10);
                for(int l = 0; l < 10; l++)
                {
                    //Debug.Log(pos);
                    positions.Add(Vector3.Slerp(old,pos,player.GetComponent<Player>().speed * l));
                }
                
            }
			
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
        return player.GetComponent<Player>().Selectedhorde.transform.position;
    }
    /// <summary>
    /// Sets the player position to the first on the list
    /// </summary>
    /// <param name="newPos">New position.</param>
	void setPlayerPos(Vector3 newPos){
        player.GetComponent<Player>().Selectedhorde.GetComponent<Horde>().Move(newPos);
    }
}
