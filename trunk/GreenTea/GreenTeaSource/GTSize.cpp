#include "GTSize.h"
#include "GTVector2.h"

GTSize GTSize::Zero = GTSize(0.0f, 0.0f);

//----------------------------------------------
// Format from a string: width height
// Sample: 120 345
//----------------------------------------------
GTSize GTSize::Parse(const GTString& source)
{
	GTVector2 v2 = GTVector2::Parse(source);
	return GTSize(v2.x, v2.y);
}
