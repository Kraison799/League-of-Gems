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
    // Update para físicas
	void FixedUpdate(){
		if (Input.GetMouseButtonDown(1)){
            Vector3 mouse_pos = mousePos();
			Vector3 player_pos = playerPos();
			AddtoList(mouse_pos,player_pos);
        }
		if (positions.Count > 0){
			setPlayerPos(positions[0]);
			positions.RemoveAt(0);
		}
	}
    //Adjunta los valores a la Lista de Vectores del PathFinding
	void AddtoList(Vector3 init, Vector3 finit){
		//Editar con Path Finding
		for (int i = 0; i < 10; i++)
        {
            positions.Add(new Vector3(10f * i, 0f, 10f * i));
        }
	}
    //Consigue la posición del Mouse
	Vector3 mousePos(){
		RaycastHit hit;
        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);

        if (Physics.Raycast(ray, out hit) && hit.transform.tag == "Ground")
        {
            return hit.point;
        }
		return new Vector3(0f,0f,0f);
	}
    //Consigue la posición del jugador
	Vector3 playerPos(){
		return player.transform.position;
	}
    //Posiciona al jugador en la posición de la lista
	void setPlayerPos(Vector3 newPos){
		player.GetComponent<Spawn>().Move(newPos);
        
	}
}
