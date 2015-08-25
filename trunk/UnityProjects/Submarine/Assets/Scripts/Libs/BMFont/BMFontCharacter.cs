
public struct BMFontCharacter
{
    #region  Public Methods

    public override string ToString()
    {
        return this.Char.ToString();
    }

    #endregion  Public Methods

    #region  Public Properties

    public int Channel { get; set; }

    public BMFontRectangle Bounds { get; set; }

    public BMFontPoint Offset { get; set; }

    public char Char { get; set; }

    public int TexturePage { get; set; }

    public int XAdvance { get; set; }

    #endregion  Public Properties
}
