using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using AssemblyCSharp.Assets.Scripts;
using System;

public class EnemyHorde : MonoBehaviour {

    //C++ Libraries
    /*[DllImport("liblib.so")]
    static extern void createMinions(int min);
    [DllImport("liblib.so")]
    static extern IntPtr getMinion(int pos);*/
    //Methods
    public float y;
    public int minionsCap;
    public float speed = 10f;
    public GameObject minions;
    public Formation formation;
    public List<GameObject> minionList = new List<GameObject>();
    // Use this for initialization
    void Start()
    {
        //createMinions(64);
        for (int i = 0; i < minionsCap; i++)
        {
            Vector3 position = arrange(i, minionsCap);
            minions.tag = "Enemy Minion";
            GameObject minion = Instantiate(minions, position + transform.position, transform.rotation, transform);
            //minion.GetComponent<Movement>().setMinionC(getMinion(i));
            minionList.Add(minion);
        }
    }

    // Update is called once per frame
    void Update()
    {
        if (GameObject.FindGameObjectsWithTag("Enemy Minion").Length == 0)
        {
            Destroy(gameObject);
        }
    }
    /// <summary>
    /// Move the specified new_position.
    /// </summary>
    /// <param name="new_position">New position.</param>
    public void Move(Vector3 new_position)
    {
        //Tranlate position
        transform.position = new_position;
    }
    /// <summary>
    /// Arrange the specified minion.
    /// </summary>
    /// <returns>The arrange.</returns>
    /// <param name="minion">Minion.</param>
    /// <param name="minionMax">Minion max.</param>
    Vector3 arrange(int minion, int minionMax)
    {
        if (formation == Formation.Circle)
        {
            return arrangeCircle(minion, minionMax);
        }
        else if (formation == Formation.Row)
        {
            return arrangeRow(minion, minionMax);
        }
        else if (formation == Formation.Square)
        {
            return arrangeSquare(minion);
        }
        else
        {
            return new Vector3(0f, 0f, 0f);
        }
    }/// <summary>
     /// Arrange the specified minion in a Square formation.
     /// </summary>
     /// <param name="i"></param>
     /// <returns></returns>
    Vector3 arrangeSquare(int i)
    {
        float z = 0;
        if (i < 8)
        {
            z = 0f;
        }
        else if (i < 16)
        {
            z = 1f;
        }
        else if (i < 24)
        {
            z = 2f;
        }
        else if (i < 32)
        {
            z = 3f;
        }
        else if (i < 40)
        {
            z = 4f;
        }
        else if (i < 48)
        {
            z = 5f;
        }
        else if (i < 56)
        {
            z = 6f;
        }
        else if (i < 64)
        {
            z = 7f;
        }
        return new Vector3(i % 8, y, z) * 3;
    }

    private Vector3 arrangeRow(int minion, int minionMax)
    {
        return new Vector3(minion, y, 0f) * 3f;
    }

    /// <summary>
    /// Arrange the specified minion in a Circle formation.
    /// </summary>
    /// <returns>The position in Vector3.</returns>
    /// <param name="minion">The index.</param>
    Vector3 arrangeCircle(int minion, int minionMax)
    {
        float angle = Mathf.PI * 2 * minion / minionMax;
        return new Vector3(Mathf.Cos(angle), y, Mathf.Sin(angle)) * minionMax / 4;
    }
    public void Split()
    {
        minionsCap /= 2;
        foreach (GameObject minion in minionList)
            Destroy(minion);


        minionList.Clear();

        for (int i = 0; i < minionsCap; i++)
        {
            Vector3 position = arrange(i, minionsCap);
            GameObject minion = Instantiate(minions, position + transform.position, transform.rotation, transform);
            //minion.GetComponent<Movement>().setMinionC(getMinion(i));
            minionList.Add(minion);
        }
    }
}
