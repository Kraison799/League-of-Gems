using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tower : MonoBehaviour {

    public GameObject fire;
    Transform fireSpawn;
    private void Awake()
    {
        fireSpawn = transform.GetChild(0).transform;

    }
    // Use this for initialization
    void Start () {
        
    }
	
	// Update is called once per frame
	void Update () {
        Attack();
	}
    private void Attack()
    {
        // Create the Bullet from the Bullet Prefab
        var bullet = (GameObject)Instantiate(
            fire,
            fireSpawn.position,
            fireSpawn.rotation);

        // Add velocity to the bullet
        bullet.GetComponent<Rigidbody>().velocity = bullet.transform.forward * 20;

        Destroy(bullet, 5f);
    }
}
