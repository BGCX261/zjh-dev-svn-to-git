using UnityEngine;
using System.Collections;

public class GTScript : MonoBehaviour
{
    public virtual void Awake()
    {
    }

    public virtual void Start()
    {
    }

    public virtual void Update()
    {
    }

    /// <summary>
    /// This method is called after Awake.
    /// If there are some perperties defined, they can be parsed here.
    /// </summary>
    /// <param name="treeNode"></param>
    public virtual void Parse(GTTreeNode treeNode)
    {
    }
}
