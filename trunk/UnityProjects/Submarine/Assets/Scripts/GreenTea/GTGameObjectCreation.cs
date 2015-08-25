using UnityEngine;
using System;
using System.Collections;

public class GTGameObjectCreation
{    
    /// <summary>
    /// Craete a sprite from *.sprite.txt
    /// </summary>
    /// <param name="spriteFileName"></param>
    /// <param name="sortingOrder"></param>
    /// <param name="gameObjectName"></param>
    /// <returns></returns>
    static public GameObject CreateSprite(string spriteFileName, int sortingOrder, string gameObjectName)
    {
        if (null == spriteFileName)
            return null;

        // Load sprite file
        TextAsset txtSprite = Resources.Load(spriteFileName, typeof(TextAsset)) as TextAsset;
        if (null == txtSprite)
        {
            Debug.LogError("CreateSprite: Failed to load sprite file: " + spriteFileName);
            return null;
        }
        GTTreeNode tnSprite = GTTreeNode.FromString(txtSprite.text);
        if (null == tnSprite)
        {
            Debug.LogError("CreateSprite: Failed to load sprite file: " + spriteFileName);
            return null;
        }

        GTTreeNode tnAssetName = tnSprite.GetChild(GTPropertyFile.TagAssetName);
        if (null == tnAssetName)
        {
            Debug.LogError("CreateSprite: Failed to find AssetName GTTreeNode in " + spriteFileName);
            return null;
        }

        // Create the atlas
        GTSpriteAtlasCocos2D spriteAtlas = GTSpriteAtlasCocos2D.Create(tnAssetName.AsString());
        if (null == spriteAtlas)
        {
            Debug.LogError("CreateSprite: Failed to create GTSpriteAtlasCocos2D: " + tnAssetName.AsString());
            return null;
        }
        // Create GameObject
        string finalGameObjectName = (gameObjectName != null) ? gameObjectName : "spriteNoName";
        GameObject spriteGameObject = new GameObject(finalGameObjectName);
        SpriteRenderer spriteRenderer = spriteGameObject.AddComponent<SpriteRenderer>();
        if (null == spriteRenderer)
        {
            Debug.LogError("CreateSprite: Failed to add SpriteRenderer: " + tnAssetName.AsString());
            return null;
        }
        spriteRenderer.sortingOrder = sortingOrder;
        spriteRenderer.sprite = null;
        // Add GTSpriteScript
        GTSpriteScript spriteComponent = spriteGameObject.AddComponent<GTSpriteScript>();
        spriteComponent.Create(spriteAtlas, tnSprite);

        return spriteGameObject;
    }

    /// <summary>
    /// Create a game object from a *.property file
    /// </summary>
    /// <param name="spriteFileName"></param>
    /// <param name="sortingOrder"></param>
    /// <param name="gameObjectName"></param>
    /// <returns></returns>
    static public GameObject CreateFromProperty(string propertyFileName, string gameObjectName)
    {
        if (null == propertyFileName)
            return null;

        // Load property file
        TextAsset txtProperty = Resources.Load(propertyFileName, typeof(TextAsset)) as TextAsset;
        if (null == txtProperty)
        {
            Debug.LogError("Failed to load sprite file: " + propertyFileName);
            return null;
        }
        // Parse the contents
        GTTreeNode tnProperty = GTTreeNode.FromString(txtProperty.text);
        if (null == tnProperty)
        {
            Debug.LogError("Failed to load sprite file: " + propertyFileName);
            return null;
        }

        GTTreeNode tnSprite = tnProperty.GetChild(GTPropertyFile.TagSprite);
        GTTreeNode tnScale = tnProperty.GetChild(GTPropertyFile.TagScale);
        GTTreeNode tnSortingOrder = tnProperty.GetChild(GTPropertyFile.TagSortingOrder);
        GTTreeNode tnLayer = tnProperty.GetChild(GTPropertyFile.TagLayer);
        GTTreeNode tnScript = tnProperty.GetChild(GTPropertyFile.TagScript);
        GTTreeNode tnChildren = tnProperty.GetChild(GTPropertyFile.TagChildren);

        GameObject newGameObject = null;
        if (tnSprite != null)
        {
            // Create a sprite
            newGameObject = GTGameObjectCreation.CreateSprite(
                tnSprite.AsString(),
                (tnSortingOrder != null) ? tnSortingOrder.AsInt() : GTSystemSetting.SortingOrder,
                gameObjectName
                );

            if (newGameObject != null && tnScript != null)
            {
                for (int i = 0; i < tnScript.childCount; i++)
                {
                    GTTreeNode tn = tnScript.GetChild(i);
                    if (tn != null &&
                        tn.tag == GTPropertyFile.TagScript && // Make sure tag = Script
                        tn.AsString().Length != 0) // Make sure script name is valid
                    {
                        // Attach this script to game object
                        string scriptName = tn.AsString();
                        Type typeScript = Type.GetType(scriptName);
                        if (typeScript != null && typeScript.IsSubclassOf(typeof(GTScript)))
                        {
                            GTScript script = newGameObject.AddComponent(typeScript) as GTScript;
                            if (script != null)
                                script.Parse(tn);
                            else
                                Debug.LogError("CreateFromProperty: Failed to attach the script: " + scriptName);
                        }
                        else
                        {
                            Debug.LogError("CreateFromProperty: The script trying to attach is not subclass of GTScript: " + scriptName);
                        }
                    }
                }
            }
        }

        return newGameObject;
    }    
}
