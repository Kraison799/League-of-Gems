using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Move : MonoBehaviour {
    //Caso de Prueba
    int Hp = 100;
    int MaxHp = 100;
    //Variables reales
    Rigidbody player;
    public float speed;
    public GameObject fire;
    Transform fireSpawn;
    private void Awake()
    {
        player = GetComponent<Rigidbody>();
    }
    // Use this for initialization
    void Start() {
        fireSpawn = transform.GetChild(0).GetChild(0).transform;
    }
    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag.Equals("Fire"))
        {
            Hp--;
        }
    }
    // Update is called once per frame
    void FixedUpdate() {
        Keyboard();
        Attack();
    }
    private void Keyboard()
    {
        //Forward
        if (Input.GetKey(KeyCode.W))
        {
            player.MovePosition(player.position + Vector3.forward * speed);
        }
        //Back
        if (Input.GetKey(KeyCode.S))
        {
            player.MovePosition(player.position + Vector3.back * speed);
        }
        //Left
        if (Input.GetKey(KeyCode.A))
        {
            player.MovePosition(player.position + Vector3.left * speed);
        }
        //Right
        if (Input.GetKey(KeyCode.D))
        {
            player.MovePosition(player.position + Vector3.right * speed);
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
}