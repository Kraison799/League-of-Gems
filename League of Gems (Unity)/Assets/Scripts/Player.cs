using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using AssemblyCSharp.Assets.Scripts;

public class Player : MonoBehaviour
{
    GameObject Area;
    GameObject Meteor;
    GameObject selectedhorde;
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

   

    // Use this for initialization
    void Start()
    {
        horde.GetComponent<Horde>().minionsCap = 64;
        horde.GetComponent<Horde>().formation = this.formation;
        GameObject newhorde = Instantiate(horde, position, transform.rotation);
        hordes.Add(newhorde);
        selectedhorde = hordes[0];
    }

    // Update is called once per frame
    void Update()
    {
        
        if (Input.GetKeyDown(KeyCode.Q))
        {
            selectedhorde.GetComponent<Horde>().Split();
            horde.GetComponent<Horde>().minionsCap /= 2;
            GameObject newhorde = Instantiate(horde, mousePos(), transform.rotation);
            hordes.Add(newhorde);
            selectedhorde = hordes[hordes.Count-1];

        }
        if (Input.GetKeyDown(KeyCode.W))
        {
            HealHorde();

        }
        if (Input.GetKeyDown(KeyCode.E))
        {
            MeteorMash();

        }
        if (Input.GetKeyDown(KeyCode.R))
        {
            SlowHorde();

        }
        if (Input.GetKeyDown(KeyCode.T))
        {
            CreateTower();

        }
        if(Area != null)
        {
            Area.transform.localScale += new Vector3(1, 0, 1);
        }
        

    }
   

    
    void HealHorde()
    {
        Area = Instantiate(healArea, mousePos(), transform.rotation);
        Destroy(Area,3f);
    }

    void MeteorMash()
    {
        Area = Instantiate(meteorArea, mousePos(), transform.rotation);
        meteor = Instantiate(meteor, Area.transform.position + Vector3.up*50, transform.rotation);
        
        Destroy(Area, 3f);
        Destroy(meteor, 3f);

    }
    void SlowHorde()
    {
        Area = Instantiate(sparkArea, mousePos(), transform.rotation);
        Destroy(Area, 3f);
    }
    void CreateTower()
    {
        Instantiate(tower, mousePos(), transform.rotation);
    }

    Vector3 mousePos()
    {
        RaycastHit hit;
        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);

        if (Physics.Raycast(ray, out hit) && hit.transform.tag == "Ground")
        {
            return hit.point;
        }
        return new Vector3(0f, 0f, 0f);
    }
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