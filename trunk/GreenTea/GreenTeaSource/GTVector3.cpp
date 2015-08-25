#include "GTVector3.h"
#include "GTArray.h"
#include "GTStringUtil.h"

GTVector3 GTVector3::Zero = GTVector3(0.0f, 0.0f, 0.0f);

//----------------------------------------------
// Format from a string: X Y Z
// Sample: 120 345 789
//----------------------------------------------
GTVector3 GTVector3::Parse(const GTString& source)
{
	GTArray<GTString> parts;
	GTStringUtil::Split(source, CTEXT(" "), parts, GTStringUtil::RemoveEmptyEntries);
	if(3 == parts.Length())
	{
		return GTVector3(parts[0].ToFloat(), parts[1].ToFloat(), parts[2].ToFloat());
	}

	return GTVector3::Zero;
}
