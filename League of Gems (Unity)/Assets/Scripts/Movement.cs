using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.Runtime.InteropServices;

public class Movement : MonoBehaviour {
	/*[DllImport("liblib.so")]
    static extern int getHp();
	[DllImport("liblib.so")]
    static extern int getMaxHp();
	[DllImport("liblib.so")]
    static extern void OnDamage();
	//C++ methods
	IntPtr minionC;*/
    //Minion methods
	public GameObject fire;
    Transform fireSpawn;
	int MaxHp = 100;
	int Hp = 100;
	// Use this for initialization
	void Start () {
		//MaxHp = getMaxHp();
		//Hp = getHp();
		fireSpawn = transform.GetChild(0).GetChild(0).transform;
	}
	
	// Update is called once per frame
	void Update () {
		//MaxHp = getMaxHp();
		//Hp = getHp();
		//evaluateHp();
		//Attack();
	}
	void OnCollide(Collision collision){
        
	}
	private void Attack()
    {
        // Create the Bullet from the Bullet Prefab
        var bullet = (GameObject)Instantiate(
            fire,
            fireSpawn.position,
            fireSpawn.rotation);

        // Add velocity to the bullet
        bullet.GetComponent<Rigidbody>().velocity = bullet.transform.forward * 6;

        Destroy(bullet, 3f);
    }
	/*private void evaluateHp(){
		if (Hp == 0){
			Destroy(this);
		}
	}
	public void setMinionC(IntPtr min){
		minionC = min;
	}*/
}
