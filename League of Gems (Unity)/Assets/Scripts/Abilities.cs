using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Abilities : MonoBehaviour {

    public GameObject HealCircle;
    public GameObject HealArea;
    public GameObject MeteorCircle;
    private float _currentScale = InitScale;
    private const float TargetScale = 1.1f;
    private const float InitScale = 1f;
    private const int FramesCount = 100;
    private const float AnimationTimeSeconds = 2;
    private float _deltaTime = AnimationTimeSeconds / FramesCount;
    private float _dx = (TargetScale - InitScale) / FramesCount;
    private bool _upScale = true;
    int ctr = 1;
    private bool crecer = false;

    // Use this for initialization
    void Start () {
		
	}

    // Update is called once per frame
    void Update() {

        if (Input.GetMouseButtonDown(0))
        {
            Heal();

        }
        try
        {

            HealArea.transform.localScale += new Vector3(0.1f, 0, 0.1f);
        }
        catch (System.Exception e)
        {
            
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

    void Heal()
    {
        //crecer = true;
        Vector3 sphereCenter = mousePos();
        HealArea = Instantiate(HealCircle, sphereCenter, transform.rotation);



        
        Destroy(HealArea,3f);
    }
}
