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
    public void Event (int btn){
        if (btn==1 || Input.GetKeyDown(KeyCode.Alpha1))
        {
            player.Split();
        }
        if (btn == 2 || Input.GetKeyDown(KeyCode.Alpha2))
        {
            player.Vanish();
        }
        if (btn == 3 || Input.GetKeyDown(KeyCode.Alpha3))
        {
            player.MeteorMash();
        }
        if (btn == 4 || Input.GetKeyDown(KeyCode.Alpha4))
        {
            player.Spark();
        }
        if (btn == 5 || Input.GetKeyDown(KeyCode.Alpha5))
        {
            //Hacer Freeze
        }
        if (btn == 6 || Input.GetKeyDown(KeyCode.Alpha6))
        {
            //Llamar Furía
        }
        if (btn == 7 || Input.GetKeyDown(KeyCode.Alpha7))
        {
            player.HealHorde();
        }
        if (btn == 8 || Input.GetKeyDown(KeyCode.Alpha8))
        {
            player.CreateTower();
        }
    }
    
}
