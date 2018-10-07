using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spawn : MonoBehaviour {
	public float speed = 10f;
	public GameObject minions;
	public List<GameObject> minionList = new List<GameObject>(); 
	// Use this for initialization
	void Start () {
		for (int i = 0; i < 15; i++){
			GameObject minion = Instantiate(minions, new Vector3(i % 5, 0.25f, i % 3) * 3f, transform.rotation,transform);
			//minion.transform.Translate();
			minionList.Add(minion);
		}
	}
	
	// Update is called once per frame
	void Update () {
		/*if (Input.GetKey(KeyCode.W)){
			transform.Translate(Vector3.forward);
		}*/
    }
	public void Move(Vector3 new_position)
    {
		//Jump
		/*foreach (GameObject min in minionList)
        {
            min.GetComponent<Rigidbody>().AddForce(Vector3.up * 0.5f, ForceMode.Impulse);

        }*/
		//Tranlate position
		GetComponent<Rigidbody>().MovePosition(new_position*speed);

    }
}