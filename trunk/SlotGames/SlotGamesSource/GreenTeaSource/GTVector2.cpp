#include "GTVector2.h"
#include "GTStringUtil.h"

// Zero object
GTVector2 GTVector2::Zero = GTVector2(0.0f, 0.0f);

//----------------------------------------------
// Format from a string: X Y
// Sample: 120 345
//----------------------------------------------
GTVector2 GTVector2::Parse(const GTString& source)
{
	GTArray<GTString> parts;
	GTStringUtil::Split(source, CTEXT(" "), parts, GTStringUtil::RemoveEmptyEntries);
	if(2 == parts.Length())
	{
		return GTVector2(parts[0].ToFloat(), parts[1].ToFloat());
	}

	return GTVector2::Zero;
}
