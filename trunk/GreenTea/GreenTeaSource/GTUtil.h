#ifndef _GREENTEA_UTIL_H_
#define _GREENTEA_UTIL_H_

#include "GTBaseDef.h"
#include "GTString.h"
#include "GTArray.h"

class GTUtil
{
public:
	GTUtil();
	~GTUtil();

	// Convert a GTString to GTArray<int32>
	static void StringToArrayInt(GTArray<int32>& gtArray, GTString& src);
	// Convert a GTString to GTArray<float>
	static void StringToArrayFloat(GTArray<float>& gtArray, GTString& src);
};

#endif /* _GREENTEA_UTIL_H_ */
