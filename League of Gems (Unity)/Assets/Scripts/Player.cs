using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using AssemblyCSharp.Assets.Scripts;

public class Player : MonoBehaviour {
	GameObject selectedhorde;
	public GameObject horde;
	List<GameObject> hordes = new List<GameObject>();
	public Vector3 position;
	public Formation formation;
	// Use this for initialization
	void Start () {
		horde.GetComponent<Horde>().minionsCap = 64;
		horde.GetComponent<Horde>().formation = this.formation;
		GameObject newhorde = Instantiate(horde, position, transform.rotation);
		hordes.Add(newhorde);
		selectedhorde = hordes[0];
	}
	
	// Update is called once per frame
	void Update () {
		
	}
    //Getters and Setters
	public GameObject Selectedhorde
    {
        get
        {
            return selectedhorde;
        }

        set
        {
            selectedhorde = value;
        }
    }
}
