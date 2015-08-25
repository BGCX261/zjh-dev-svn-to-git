using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class GTUICanvas : GTUIWidget
{
    public Canvas mCanvas = null;
    public GraphicRaycaster mGraphicRaycaster = null;
    public GTUISkin mSkin = null;

    public GTUICanvas()
    {
    }

    /// <summary>
    /// Create a Canvas object
    /// </summary>
    /// <param name="name"></param>
    /// <returns></returns>
    public static GTUICanvas Create(string name)
    {
        GTUICanvas newCanvas = new GTUICanvas();
        newCanvas.mGameObject = new GameObject(name);
        newCanvas.mCanvas = newCanvas.mGameObject.AddComponent<Canvas>();
        newCanvas.mGraphicRaycaster = newCanvas.mGameObject.AddComponent<GraphicRaycaster>();
        if (newCanvas.mCanvas != null)
            newCanvas.mCanvas.renderMode = RenderMode.Overlay;
        else
        {
            Debug.LogError("CreateCanvasGameObject: Failed to add Canvas component for " + name);
            return null;
        }
        if (newCanvas.mGraphicRaycaster != null)
        {
            //graphicRaycaster.priority = 3;
        }
        else
        {
            Debug.LogError("CreateCanvasGameObject: Failed to add GraphicRaycaster component for " + name);
            return null;
        }

        return newCanvas;
    }
}
