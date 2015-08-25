using UnityEngine;
using System.Collections;

public class DrawCall : MonoBehaviour
{
	// Use this for initialization
	void Start()
    {
        Texture2D texture = Resources.Load("Sprites/yellow_submarine") as Texture2D;
        //Texture2D texture = Resources.Load("Sprites/uv_checker_large") as Texture2D;
        Material defaultMaterial = new Material(Shader.Find("Unlit/Transparent"));
        defaultMaterial.mainTexture = texture;
        
        Vector3[] verts = new Vector3[4]
        {
            new Vector3(0.0f, 0.0f, 0.0f),
            new Vector3(0.0f, 256.0f, 0.0f),
            new Vector3(256.0f, 256.0f, 0.0f),
            new Vector3(256.0f, 0.0f, 0.0f)
        };
        Vector2[] uvs = new Vector2[4]
        {
            new Vector2(0.0f, 0.0f),
            new Vector2(0.0f, 1.0f),
            new Vector2(1.0f, 1.0f),
            new Vector2(1.0f, 0.0f)
        };
        Color32[] clrs = new Color32[4]
        {
            new Color32(255, 255, 255, 0),
            new Color32(255, 255, 255, 0),
            new Color32(255, 255, 255, 0),
            new Color32(255, 255, 255, 0)
        };
        int[] tris = new int[] { 0, 1, 2, 2, 3, 0 };

        Mesh mesh = new Mesh();
        mesh.name = "nameMesh";
        mesh.vertices = verts;
        mesh.uv = uvs;
        mesh.colors32 = clrs;
        mesh.triangles = tris;
        mesh.RecalculateBounds();

        MeshFilter meshFilter = gameObject.GetComponent<MeshFilter>();
        meshFilter.mesh = mesh;

        MeshRenderer meshRender = gameObject.GetComponent<MeshRenderer>();
        meshRender.material = defaultMaterial;
        //meshRender.material.mainTexture = texture;
	}
	
	// Update is called once per frame
	void Update()
    {	
	}
}
