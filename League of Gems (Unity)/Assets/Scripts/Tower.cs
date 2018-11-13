using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tower : MonoBehaviour {

    public string Enemytag;
    public GameObject fire;
    Transform fireSpawn;
    Transform randomMinion;

    private void Awake()
    {
        fireSpawn = transform.GetChild(0).transform;

    }
    // Use this for initialization
    void Start () {

    }
	
	// Update is called once per frame
	void Update () {
        transform.LookAt(GameObject.FindWithTag(Enemytag).transform);
    }
    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == Enemytag)
        {

            StartCoroutine(Attack());
        }
    }
    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.tag == Enemytag)
        {
            StopCoroutine(Attack());
        }
    }
    private IEnumerator Attack()
    {
        while (true)
        {
            // Create the Bullet from the Bullet Prefab
            var bullet = (GameObject)Instantiate(
                fire,
                fireSpawn.position,
                fireSpawn.rotation);

            // Add velocity to the bullet
            bullet.GetComponent<Rigidbody>().velocity = bullet.transform.forward * 20;

            Destroy(bullet, 5f);
            yield return new WaitForSeconds(2);
        }
        
    }
}
