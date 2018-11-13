using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Button : MonoBehaviour
{
    Player player;
    private void Awake()
    {
        player = GameObject.FindWithTag("Player").GetComponent<Player>();
    }
    private void Update()
    {
        if (Input.GetKeyDown(KeyCode.Alpha1))
        {
            StartCoroutine(player.Split());

        }
        if (Input.GetKeyDown(KeyCode.Alpha2))
        {
            StartCoroutine(player.Vanish());
        }
        if (Input.GetKeyDown(KeyCode.Alpha3))
        {
            StartCoroutine(player.MeteorMash());

        }
        if (Input.GetKeyDown(KeyCode.Alpha4))
        {
            StartCoroutine(player.Spark());
        }
        if (Input.GetKeyDown(KeyCode.Alpha5))
        {
            StartCoroutine(player.Freeze());
        }
        if (Input.GetKeyDown(KeyCode.Alpha6))
        {
            StartCoroutine(player.Fury());
        }
        if (Input.GetKeyDown(KeyCode.Alpha7))
        {
            StartCoroutine(player.HealHorde());
        }
        if (Input.GetKeyDown(KeyCode.Alpha8))
        {
            StartCoroutine(player.CreateTower());
        }
    }
    public void Event (int btn){
        if (btn==1)
        {
            StartCoroutine(player.Split());
            
        }
        if (btn == 2)
        {
            StartCoroutine(player.Vanish());
        }
        if (btn == 3)
        {
            StartCoroutine(player.MeteorMash());
            
        }
        if (btn == 4)
        {
            StartCoroutine(player.Spark());
        }
        if (btn == 5)
        {
            StartCoroutine(player.Freeze());
        }
        if (btn == 6)
        {
            StartCoroutine(player.Fury());
        }
        if (btn == 7)
        {
            StartCoroutine(player.HealHorde());
        }
        if (btn == 8)
        {
            StartCoroutine(player.CreateTower());
        }
    }
    
}
