using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using AssemblyCSharp.Assets.Scripts;

public class Enemy : MonoBehaviour {

    GameObject Area;
    GameObject Meteor;
    public GameObject selectedhorde;
    public float speed = 0.1f;
    public GameObject horde;
    List<GameObject> hordes = new List<GameObject>();
    public Vector3 position;
    public Formation formation;
    public GameObject healArea;
    public GameObject meteorArea;
    public GameObject meteor;
    public GameObject sparkArea;
    public GameObject tower;
    string Htag = "Enemy Horde";

    // Use this for initialization
    void Start () {
        horde.tag = Htag;
        horde.GetComponent<EnemyHorde>().minionsCap = 64;
        horde.GetComponent<EnemyHorde>().formation = this.formation;
        GameObject newhorde = Instantiate(horde, position, transform.rotation);
        hordes.Add(newhorde);
        selectedhorde = hordes[0];
    }
	
	// Update is called once per frame
	void Update () {
		
	}
}
