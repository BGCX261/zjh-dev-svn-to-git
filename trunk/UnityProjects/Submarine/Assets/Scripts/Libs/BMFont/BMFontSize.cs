using UnityEngine;
using System.Collections;

public struct BMFontSize
{
    //
    // Summary:
    //     Initializes a new instance of the System.Drawing.Size structure from the
    //     specified dimensions.
    //
    // Parameters:
    //   width:
    //     The width component of the new System.Drawing.Size.
    //
    //   height:
    //     The height component of the new System.Drawing.Size.
    public BMFontSize(int width, int height)
        : this()
    {
        Width = width;
        Height = height;
    }
    // Summary:
    //     Gets or sets the vertical component of this System.Drawing.Size structure.
    //
    // Returns:
    //     The vertical component of this System.Drawing.Size structure, typically measured
    //     in pixels.
    public int Height { get; set; }
    //
    // Summary:
    //     Tests whether this System.Drawing.Size structure has width and height of
    //     0.
    //
    // Returns:
    //     This property returns true when this System.Drawing.Size structure has both
    //     a width and height of 0; otherwise, false.
    //public bool IsEmpty { get; }
    //
    // Summary:
    //     Gets or sets the horizontal component of this System.Drawing.Size structure.
    //
    // Returns:
    //     The horizontal component of this System.Drawing.Size structure, typically
    //     measured in pixels.
    public int Width { get; set; }
}

/*
// Summary:
//     Stores an ordered pair of integers, which specify a System.Drawing.Size.Height
//     and System.Drawing.Size.Width.
[Serializable]
[TypeConverter(typeof(SizeConverter))]
[ComVisible(true)]
public struct Size
{
    // Summary:
    //     Gets a System.Drawing.Size structure that has a System.Drawing.Size.Height
    //     and System.Drawing.Size.Width value of 0.
    //
    // Returns:
    //     A System.Drawing.Size that has a System.Drawing.Size.Height and System.Drawing.Size.Width
    //     value of 0.
    public static readonly Size Empty;

    //
    // Summary:
    //     Initializes a new instance of the System.Drawing.Size structure from the
    //     specified System.Drawing.Point structure.
    //
    // Parameters:
    //   pt:
    //     The System.Drawing.Point structure from which to initialize this System.Drawing.Size
    //     structure.
    public Size(Point pt);
    //
    // Summary:
    //     Initializes a new instance of the System.Drawing.Size structure from the
    //     specified dimensions.
    //
    // Parameters:
    //   width:
    //     The width component of the new System.Drawing.Size.
    //
    //   height:
    //     The height component of the new System.Drawing.Size.
    [TargetedPatchingOptOut("Performance critical to inline this type of method across NGen image boundaries")]
    public Size(int width, int height);

    // Summary:
    //     Subtracts the width and height of one System.Drawing.Size structure from
    //     the width and height of another System.Drawing.Size structure.
    //
    // Parameters:
    //   sz1:
    //     The System.Drawing.Size structure on the left side of the subtraction operator.
    //
    //   sz2:
    //     The System.Drawing.Size structure on the right side of the subtraction operator.
    //
    // Returns:
    //     A System.Drawing.Size structure that is the result of the subtraction operation.
    [TargetedPatchingOptOut("Performance critical to inline this type of method across NGen image boundaries")]
    public static Size operator -(Size sz1, Size sz2);
    //
    // Summary:
    //     Tests whether two System.Drawing.Size structures are different.
    //
    // Parameters:
    //   sz1:
    //     The System.Drawing.Size structure on the left of the inequality operator.
    //
    //   sz2:
    //     The System.Drawing.Size structure on the right of the inequality operator.
    //
    // Returns:
    //     true if sz1 and sz2 differ either in width or height; false if sz1 and sz2
    //     are equal.
    [TargetedPatchingOptOut("Performance critical to inline across NGen image boundaries")]
    public static bool operator !=(Size sz1, Size sz2);
    //
    // Summary:
    //     Adds the width and height of one System.Drawing.Size structure to the width
    //     and height of another System.Drawing.Size structure.
    //
    // Parameters:
    //   sz1:
    //     The first System.Drawing.Size to add.
    //
    //   sz2:
    //     The second System.Drawing.Size to add.
    //
    // Returns:
    //     A System.Drawing.Size structure that is the result of the addition operation.
    [TargetedPatchingOptOut("Performance critical to inline this type of method across NGen image boundaries")]
    public static Size operator +(Size sz1, Size sz2);
    //
    // Summary:
    //     Tests whether two System.Drawing.Size structures are equal.
    //
    // Parameters:
    //   sz1:
    //     The System.Drawing.Size structure on the left side of the equality operator.
    //
    //   sz2:
    //     The System.Drawing.Size structure on the right of the equality operator.
    //
    // Returns:
    //     true if sz1 and sz2 have equal width and height; otherwise, false.
    public static bool operator ==(Size sz1, Size sz2);
    //
    // Summary:
    //     Converts the specified System.Drawing.Size structure to a System.Drawing.Point
    //     structure.
    //
    // Parameters:
    //   size:
    //     The System.Drawing.Size structure to convert.
    //
    // Returns:
    //     The System.Drawing.Point structure to which this operator converts.
    public static explicit operator Point(Size size);
    //
    // Summary:
    //     Converts the specified System.Drawing.Size structure to a System.Drawing.SizeF
    //     structure.
    //
    // Parameters:
    //   p:
    //     The System.Drawing.Size structure to convert.
    //
    // Returns:
    //     The System.Drawing.SizeF structure to which this operator converts.
    public static implicit operator SizeF(Size p);

    // Summary:
    //     Gets or sets the vertical component of this System.Drawing.Size structure.
    //
    // Returns:
    //     The vertical component of this System.Drawing.Size structure, typically measured
    //     in pixels.
    public int Height { get; set; }
    //
    // Summary:
    //     Tests whether this System.Drawing.Size structure has width and height of
    //     0.
    //
    // Returns:
    //     This property returns true when this System.Drawing.Size structure has both
    //     a width and height of 0; otherwise, false.
    [Browsable(false)]
    public bool IsEmpty { get; }
    //
    // Summary:
    //     Gets or sets the horizontal component of this System.Drawing.Size structure.
    //
    // Returns:
    //     The horizontal component of this System.Drawing.Size structure, typically
    //     measured in pixels.
    public int Width { get; set; }

    // Summary:
    //     Adds the width and height of one System.Drawing.Size structure to the width
    //     and height of another System.Drawing.Size structure.
    //
    // Parameters:
    //   sz1:
    //     The first System.Drawing.Size structure to add.
    //
    //   sz2:
    //     The second System.Drawing.Size structure to add.
    //
    // Returns:
    //     A System.Drawing.Size structure that is the result of the addition operation.
    public static Size Add(Size sz1, Size sz2);
    //
    // Summary:
    //     Converts the specified System.Drawing.SizeF structure to a System.Drawing.Size
    //     structure by rounding the values of the System.Drawing.Size structure to
    //     the next higher integer values.
    //
    // Parameters:
    //   value:
    //     The System.Drawing.SizeF structure to convert.
    //
    // Returns:
    //     The System.Drawing.Size structure this method converts to.
    public static Size Ceiling(SizeF value);
    //
    // Summary:
    //     Tests to see whether the specified object is a System.Drawing.Size structure
    //     with the same dimensions as this System.Drawing.Size structure.
    //
    // Parameters:
    //   obj:
    //     The System.Object to test.
    //
    // Returns:
    //     true if obj is a System.Drawing.Size and has the same width and height as
    //     this System.Drawing.Size; otherwise, false.
    public override bool Equals(object obj);
    //
    // Summary:
    //     Returns a hash code for this System.Drawing.Size structure.
    //
    // Returns:
    //     An integer value that specifies a hash value for this System.Drawing.Size
    //     structure.
    public override int GetHashCode();
    //
    // Summary:
    //     Converts the specified System.Drawing.SizeF structure to a System.Drawing.Size
    //     structure by rounding the values of the System.Drawing.SizeF structure to
    //     the nearest integer values.
    //
    // Parameters:
    //   value:
    //     The System.Drawing.SizeF structure to convert.
    //
    // Returns:
    //     The System.Drawing.Size structure this method converts to.
    public static Size Round(SizeF value);
    //
    // Summary:
    //     Subtracts the width and height of one System.Drawing.Size structure from
    //     the width and height of another System.Drawing.Size structure.
    //
    // Parameters:
    //   sz1:
    //     The System.Drawing.Size structure on the left side of the subtraction operator.
    //
    //   sz2:
    //     The System.Drawing.Size structure on the right side of the subtraction operator.
    //
    // Returns:
    //     A System.Drawing.Size structure that is a result of the subtraction operation.
    public static Size Subtract(Size sz1, Size sz2);
    //
    // Summary:
    //     Creates a human-readable string that represents this System.Drawing.Size
    //     structure.
    //
    // Returns:
    //     A string that represents this System.Drawing.Size.
    public override string ToString();
    //
    // Summary:
    //     Converts the specified System.Drawing.SizeF structure to a System.Drawing.Size
    //     structure by truncating the values of the System.Drawing.SizeF structure
    //     to the next lower integer values.
    //
    // Parameters:
    //   value:
    //     The System.Drawing.SizeF structure to convert.
    //
    // Returns:
    //     The System.Drawing.Size structure this method converts to.
    public static Size Truncate(SizeF value);
}
*/
