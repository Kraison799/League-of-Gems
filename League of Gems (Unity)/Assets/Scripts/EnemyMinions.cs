using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyMinions : MonoBehaviour
{
    
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		transform.LookAt(GameObject.FindWithTag("Horde").transform);
	}

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag.Equals("MeteorMash"))
        {
            foreach (GameObject minion in GetComponent<Enemy>().selectedhorde.GetComponent<EnemyHorde>().minionList)
            {
                minion.GetComponent<Movement>().Hp -= 50;
            }
        }
    }
}
