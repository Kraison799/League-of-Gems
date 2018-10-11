using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using AssemblyCSharp.Assets.Scripts;
using System;

public class Horde : MonoBehaviour {
	//C++ Libraries
    /*[DllImport("liblib.so")]
    static extern void createMinions(int min);
    [DllImport("liblib.so")]
    static extern IntPtr getMinion(int pos);*/
    //Methods
    public int minionsCap;
    public float speed = 10f;
    public GameObject minions;
	public Formation formation;
    //public List<GameObject> minionList = new List<GameObject>(); 
    // Use this for initialization
    void Start()
    {
        //createMinions(64);
        for (int i = 0; i < minionsCap; i++)
        {
            Vector3 position = arrange(i, minionsCap);
            GameObject minion = Instantiate(minions, position, transform.rotation, transform);
            //minion.GetComponent<Movement>().setMinionC(getMinion(i));
            //minionList.Add(minion);
        }
    }

    // Update is called once per frame
    void Update()
    {
        /*if (Input.GetKey(KeyCode.W)){
            transform.Translate(Vector3.forward);
        }*/
    }
    /// <summary>
    /// Move the specified new_position.
    /// </summary>
    /// <param name="new_position">New position.</param>
    public void Move(Vector3 new_position)
    {
        //Tranlate position
        GetComponent<Rigidbody>().MovePosition(new_position * speed);
    }
	/// <summary>
	/// Arrange the specified minion.
	/// </summary>
	/// <returns>The arrange.</returns>
	/// <param name="minion">Minion.</param>
	/// <param name="minionMax">Minion max.</param>
	Vector3 arrange(int minion, int minionMax)
	{ 
		if (formation == Formation.Circle){
			return arrangeCircle(minion, minionMax);
		}
		else if (formation == Formation.Row){
			return arrangeRow(minion, minionMax);
		}
		else if (formation == Formation.Square){
			return arrangeCircle(minion, minionMax);
		}
		else{
			return new Vector3(0f,0f,0f);
		}
    }

	private Vector3 arrangeRow(int minion, int minionMax)
	{
		return new Vector3(minion, 0.25f, 0f) * 3f;
	}

	/// <summary>
	/// Arrange the specified minion in a Circle formation.
	/// </summary>
	/// <returns>The position in Vector3.</returns>
	/// <param name="minion">The index.</param>
	Vector3 arrangeCircle(int minion, int minionMax)
    {
        float angle = Mathf.PI * 2 * minion / minionMax;
        return new Vector3(Mathf.Cos(angle), 0.25f, Mathf.Sin(angle)) * minionMax / 4;
    }
}
