using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class GTAsset
{
    public string assetName;

    public GTAsset()
    {
    }
}

/// <summary>
/// GTAssetManager caches some assets already loaded
/// </summary>
public class GTAssetManager
{
    // Singleton
    private static GTAssetManager mInst = new GTAssetManager();
    public static GTAssetManager Instance { get { return mInst; } }

    // Dictionary caching assets
    private Dictionary<string, object> mAssets = new Dictionary<string, object>();

    /// <summary>
    /// Check if an asset is already loaded
    /// </summary>
    /// <param name="name"></param>
    /// <returns></returns>
    public bool AssetExists(string keyName)
    {
        return mAssets.ContainsKey(keyName);
    }

    /// <summary>
    /// Add an asset
    /// </summary>
    /// <param name="keyName"></param>
    /// <param name="obj"></param>
    public void AddAsset(string keyName, GTAsset asset)
    {
        if (!AssetExists(keyName))
        {
            asset.assetName = keyName;
            mAssets.Add(keyName, asset);
        }
    }

    /// <summary>
    /// Get a cached asset by keyName
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="keyName"></param>
    /// <returns></returns>
    public T GetAsset<T>(string keyName) where T : GTAsset
    {
        return mAssets.ContainsKey(keyName) ? mAssets[keyName] as T : null;
    }
}
