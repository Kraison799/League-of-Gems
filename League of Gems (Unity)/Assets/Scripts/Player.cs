using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using AssemblyCSharp.Assets.Scripts;

public class Player : MonoBehaviour
{
    GameObject selectedhorde;
    public GameObject horde;
    List<GameObject> hordes = new List<GameObject>();
    public Vector3 position;
    public Formation formation;
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
}