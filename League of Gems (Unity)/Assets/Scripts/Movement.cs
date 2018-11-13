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
    public string EnemyTag;
    public GameObject EnemyFire;
    public GameObject fire;
    Transform fireSpawn;
	int MaxHp = 100;
	int Hp = 100;
    public SimpleHealthBar healthBar;
    // Use this for initialization
    void Start () {
        //MaxHp = getMaxHp();
        //Hp = getHp();
        gameObject.layer = LayerMask.NameToLayer("Ignore Raycast");
        fireSpawn = transform.GetChild(0).GetChild(0).transform;
        healthBar.UpdateBar(Hp, MaxHp);
    }
	
	// Update is called once per frame
	void Update () {
        //MaxHp = getMaxHp();
        //Hp = getHp();
        //evaluateHp();

        
        
        if (Hp <= 0)
        {
            Destroy(gameObject);
        }        
        
	}
	void OnCollisionEnter(Collision collision){
        if (collision.gameObject.tag.Equals(EnemyFire.tag))
        {
            Destroy(collision.gameObject);
            
            healthBar.UpdateBar(Hp-=10, MaxHp);
            Debug.Log(Hp);
        }
        if (collision.gameObject.tag.Equals(fire.tag))
        {
            Physics.IgnoreCollision(GetComponent<Collider>(), collision.gameObject.GetComponent<Collider>());
        }
    }
    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == EnemyTag)
        {
            StartCoroutine(Attack());
        }
    }
    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.tag == EnemyTag)
        {
            StopCoroutine(Attack());
        }
    }
    IEnumerator Attack()
    {
        while (true)
        {
            // Create the Bullet from the Bullet Prefab
            var bullet = (GameObject)Instantiate(
                fire,
                fireSpawn.position,
                fireSpawn.rotation);
            
            // Add velocity to the bullet
            bullet.GetComponent<Rigidbody>().velocity = bullet.transform.forward * 10;

            Destroy(bullet, 10f);
            yield return new WaitForSeconds(0.5f);
        }
        
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
