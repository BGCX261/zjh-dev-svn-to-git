This program will allow you to generate bitmap fonts from TrueType fonts.
The application generates both image files and character descriptions that can be read by a game for easy rendering of fonts. 

http://www.angelcode.com/products/bmfont/

Features

    Support for complete Unicode 5.1 character set, as well as 8 bit OEM character sets
    Optimal use of texture space, i.e. as little unused area as possible
    Support for kerning pairs
    Easy to use file format, either normal text file or xml files. Binary format is available for those that prefer that
    8bit or 32bit texture output (TGA, PNG, and DDS files)
    Option for packing 4 layers of font images into 1 32bit texture. Needs special shader to render with, but saves a lot of memory
    Anti-aliasing, both through Windows native font smoothing and super sampling
    Configurable padding and spacing between characters
    Select characters from text file, supports both UTF8 and UTF16 encoded files
    Generate bitmap font from command line
    Import colored images as characters, supports: bmp, jpg, tga, dds, png
    Optional outline to font characters
    Optional packing of characters with outline into 1 channel. Needs special shader to unpack during rendering, but saves a lot of memory.
	