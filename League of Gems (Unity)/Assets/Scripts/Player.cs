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
        if(Area != null)
        {
            Area.transform.localScale += new Vector3(1, 0, 1);
        }
    }
   public IEnumerator Vanish()
    {
        Debug.Log("Vanishing...");
        foreach (GameObject h in hordes){
            foreach(GameObject min in h.GetComponent<Horde>().minionList)
            {
                min.GetComponent<Renderer>().enabled = false;
            }            
        }
        yield return new WaitForSeconds(5);
        foreach (GameObject h in hordes)
        {
            foreach (GameObject min in h.GetComponent<Horde>().minionList)
            {
                min.GetComponent<Renderer>().enabled = true;
            }
        }
    }
    public IEnumerator Split()
    {
        Debug.Log("Splitting...");
        yield return new WaitUntil(() => Input.GetMouseButtonDown(0) == true);
        selectedhorde.GetComponent<Horde>().Split();
        horde.GetComponent<Horde>().minionsCap /= 2;
        GameObject newhorde = Instantiate(horde, mousePos(), transform.rotation);
        hordes.Add(newhorde);
        selectedhorde = hordes[hordes.Count - 1];
        yield return new WaitForSeconds(10);
    }
    
    public IEnumerator HealHorde()
    {
        Debug.Log("Healing...");
        yield return new WaitUntil(() => Input.GetMouseButtonDown(0) == true);
        Area = Instantiate(healArea, mousePos(), transform.rotation);
        Destroy(Area,3f);
    }
    public IEnumerator Freeze()
    {
        yield return new WaitUntil(() => Input.GetMouseButtonDown(0) == true);
        //Crea zona

        
        
        //Destruye

    }
    public IEnumerator Fury()
    {
        //Marshalling de Furia
        yield return new WaitForSeconds(10);
    }

    public IEnumerator MeteorMash()
    {
        Debug.Log("Damaging...");
        yield return new WaitUntil(() => Input.GetMouseButtonDown(0) == true);
        Area = Instantiate(meteorArea, mousePos(), transform.rotation);
        meteor = Instantiate(meteor, Area.transform.position + Vector3.up*50, transform.rotation);
        
        Destroy(Area, 3f);
        Destroy(meteor, 3f);

    }
    public IEnumerator Spark()
    {
        Debug.Log("Slowing...");
        yield return new WaitUntil(() => Input.GetMouseButtonDown(0) == true);
        Area = Instantiate(sparkArea, mousePos(), transform.rotation);
        Destroy(Area, 3f);
    }
    public IEnumerator CreateTower()
    {
        yield return new WaitUntil(() => Input.GetMouseButtonDown(0) == true);
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
        return new Vector3(50f, 50f, 50f);
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