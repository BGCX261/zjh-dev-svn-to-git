using UnityEngine;
using System.Collections;

public struct BMFontPoint
{
    public BMFontPoint(int tx, int ty)
        : this()
    {
        X = tx;
        Y = ty;
    }
    //
    // Summary:
    //     Gets or sets the x-coordinate of this System.Drawing.Point.
    //
    // Returns:
    //     The x-coordinate of this System.Drawing.Point.
    public int X { get; set; }
    //
    // Summary:
    //     Gets or sets the y-coordinate of this System.Drawing.Point.
    //
    // Returns:
    //     The y-coordinate of this System.Drawing.Point.
    public int Y { get; set; }    
}
