using UnityEngine;

/// <summary>
/// Stores texture data of a specific container frame.
/// </summary>
public struct FrameData
{
    /// <summary>
    /// This frame's name
    /// </summary>
    public string name;
    /// <summary>
    /// This frame's image scale modifier
    /// </summary>
    public Vector2 size;
    /// <summary>
    /// This frame's original image size
    /// </summary>
    public Vector2 imageSize;
    /// <summary>
    /// This frame's world position offset modifier
    /// </summary>
    public Vector2 offset;
    /// <summary>
    /// This frame's world rotation modifier
    /// </summary>
    public float rotation;
    /// <summary>
    /// Texture UV coordinates (x/y).
    /// </summary>
    public Vector2[] uv;
    /// <summary>
    /// Mesh vertices used when OffsetSizing = false (Atlas)
    /// </summary>
    public Vector3[] vertices;
    /// <summary>
    /// The index of the frame
    /// </summary>
    public int index;

    public override string ToString()
    {
        string uvstr = Tools.UVToString(uv);
        string str = name + " " + size + " " + imageSize + " " + offset + " " + rotation + " " + uvstr;
        return str;
    }
}
