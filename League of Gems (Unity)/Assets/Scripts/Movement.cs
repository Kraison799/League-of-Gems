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
    public SimpleHealthBar healthBar;
    // Use this for initialization
    void Start () {
		//MaxHp = getMaxHp();
		//Hp = getHp();
		fireSpawn = transform.GetChild(0).GetChild(0).transform;
        healthBar.UpdateBar(Hp, MaxHp);
    }
	
	// Update is called once per frame
	void Update () {
        //MaxHp = getMaxHp();
        //Hp = getHp();
        //evaluateHp();

        
        if (Hp == 0)
        {
            Destroy(gameObject);
        }        
        
	}
	void OnCollisionEnter(Collision collision){
        if (collision.gameObject.tag.Equals("EnemyFire"))
        {
            Destroy(collision.gameObject);
            
            healthBar.UpdateBar(--Hp, MaxHp);
        }
        if (collision.gameObject.tag.Equals("FriendlyFire"))
        {
            Physics.IgnoreCollision(GetComponent<Collider>(), collision.gameObject.GetComponent<Collider>());
            Destroy(collision.gameObject);
        }
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
