using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class PlayerGem : Gem {

    int MaxHp = 500;
    int Hp = 500;
    public SimpleHealthBar healthBar;
    public GameObject EnemyFire;
    public GameObject fire;

    // Use this for initialization
    void Start () {
        healthBar.UpdateBar(Hp, MaxHp);
    }
	
	// Update is called once per frame
	void Update () {
        if (Hp <= 0)
        {
            Destroy(gameObject);
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);//reinicio lvl
        }
    }
    void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag.Equals(EnemyFire.tag))
        {
            healthBar.UpdateBar(Hp -= 10, MaxHp);
            Destroy(collision.gameObject);
        }
        if (collision.gameObject.tag.Equals(fire.tag))
        {
            Physics.IgnoreCollision(GetComponent<Collider>(), collision.gameObject.GetComponent<Collider>());
        }
    }
}
