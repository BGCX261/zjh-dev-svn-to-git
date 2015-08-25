using UnityEngine;
using System.Collections;

public struct BMFontRectangle
{
    public BMFontRectangle(int x, int y, int width, int height)
        : this()
    {
        Left = x;
        Top = y;
        Width = width;
        Height = height;
    }
    // Summary:
    //     Gets the y-coordinate that is the sum of the System.Drawing.Rectangle.Y and
    //     System.Drawing.Rectangle.Height property values of this System.Drawing.Rectangle
    //     structure.
    //
    // Returns:
    //     The y-coordinate that is the sum of System.Drawing.Rectangle.Y and System.Drawing.Rectangle.Height
    //     of this System.Drawing.Rectangle.
    public int Bottom { get; set; }
    //
    // Summary:
    //     Gets or sets the height of this System.Drawing.Rectangle structure.
    //
    // Returns:
    //     The height of this System.Drawing.Rectangle structure. The default is 0.
    public int Height { get; set; }
    //
    // Summary:
    //     Gets the x-coordinate of the left edge of this System.Drawing.Rectangle structure.
    //
    // Returns:
    //     The x-coordinate of the left edge of this System.Drawing.Rectangle structure.
    public int Left { get; set; }
    //
    // Summary:
    //     Gets the x-coordinate that is the sum of System.Drawing.Rectangle.X and System.Drawing.Rectangle.Width
    //     property values of this System.Drawing.Rectangle structure.
    //
    // Returns:
    //     The x-coordinate that is the sum of System.Drawing.Rectangle.X and System.Drawing.Rectangle.Width
    //     of this System.Drawing.Rectangle.
    public int Right { get; set; }
    //
    // Summary:
    //     Gets or sets the size of this System.Drawing.Rectangle.
    //
    // Returns:
    //     A System.Drawing.Size that represents the width and height of this System.Drawing.Rectangle
    //     structure.
     public BMFontSize Size { get; set; }
    //
    // Summary:
    //     Gets the y-coordinate of the top edge of this System.Drawing.Rectangle structure.
    //
    // Returns:
    //     The y-coordinate of the top edge of this System.Drawing.Rectangle structure.
     public int Top { get; set; }
    //
    // Summary:
    //     Gets or sets the width of this System.Drawing.Rectangle structure.
    //
    // Returns:
    //     The width of this System.Drawing.Rectangle structure. The default is 0.
    public int Width { get; set; }
    //
    // Summary:
    //     Gets or sets the x-coordinate of the upper-left corner of this System.Drawing.Rectangle
    //     structure.
    //
    // Returns:
    //     The x-coordinate of the upper-left corner of this System.Drawing.Rectangle
    //     structure. The default is 0.
    public int X { get; set; }
    //
    // Summary:
    //     Gets or sets the y-coordinate of the upper-left corner of this System.Drawing.Rectangle
    //     structure.
    //
    // Returns:
    //     The y-coordinate of the upper-left corner of this System.Drawing.Rectangle
    //     structure. The default is 0.
    public int Y { get; set; }
}
