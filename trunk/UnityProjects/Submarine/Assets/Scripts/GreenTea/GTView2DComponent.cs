using UnityEngine;
using System.Collections;

public class GTView2DComponent : MonoBehaviour
{
    void Start()
    {
#if UNITY_EDITOR
        //Debug.Log("UNITY_EDITOR....");
#endif
        Debug.Log(string.Format("GTViewComponent: Screen Size = ({0}, {1})", Screen.width, Screen.height));
        // Move the camera positon to let bottom-left is (0, 0)
        gameObject.transform.position = new Vector3(
            (float)GTSystemSetting.ScreenWidth / (GTSystemSetting.PixelsToUnits * 2.0f),
            (float)GTSystemSetting.ScreenHeight / (GTSystemSetting.PixelsToUnits * 2.0f),
            -10.0f
            );
    }

    void Update()
    {
    }
}
