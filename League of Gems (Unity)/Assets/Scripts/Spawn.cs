using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spawn : MonoBehaviour {
	public GameObject minions;
	public List<GameObject> minionList = new List<GameObject>(); 
	// Use this for initialization
	void Start () {
		for (int i = 0; i < 15; i++){
			GameObject minion = Instantiate(minions, transform.position, transform.rotation,transform);
			minion.transform.Translate(new Vector3(i%5,0.25f,i%3)*3f);
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
		transform.Translate((new_position - transform.position)*Time.deltaTime);

    }
}