using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMinions : MonoBehaviour
{
    Transform randomMinion;
	// Use this for initialization
	void Start () {
        StartCoroutine(randomChoice());
    }
	
	// Update is called once per frame
	void Update () {
        transform.LookAt(randomMinion);
    }
    IEnumerator randomChoice()
    {
        while (true)
        {
            var possibleTargets = GameObject.FindGameObjectsWithTag("Enemy Minion");
            randomMinion = possibleTargets[Random.Range(0, possibleTargets.Length-1)].transform;
            yield return new WaitForSeconds(10);
        }
        
    }
}
