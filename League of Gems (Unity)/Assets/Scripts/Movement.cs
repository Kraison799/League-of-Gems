using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.Runtime.InteropServices;

public class Movement : MonoBehaviour {
	/*[DllImport("liblib.so")]
    static extern int getHp();
	[DllImport("liblib.so")]
    static extern int getMaxHp();
	[DllImport("liblib.so")]
    static extern void OnDamage();
	//C++ methods
	IntPtr minionC;*/
    //Minion methods
	int MaxHp;
	int Hp;
	public Color color;
	// Use this for initialization
	void Start () {
		//MaxHp = getMaxHp();
		//Hp = getHp();
		GetComponent<Renderer>().material.color = color;
	}
	
	// Update is called once per frame
	void Update () {
		//MaxHp = getMaxHp();
		//Hp = getHp();
		//evaluateHp();
	}
	void OnCollide(Collision collision){
		
	}
	public void jump(){
		
	}
	/*private void evaluateHp(){
		if (Hp == 0){
			Destroy(this);
		}
	}
	public void setMinionC(IntPtr min){
		minionC = min;
	}*/
}
