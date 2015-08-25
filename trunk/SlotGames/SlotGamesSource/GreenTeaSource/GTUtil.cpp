#include "GTUtil.h"
#include "GTStringUtil.h"

GTUtil::GTUtil()
{
}


GTUtil::~GTUtil()
{
}


// Convert a GTString to GTArray<int32>
void GTUtil::StringToArrayInt(GTArray<int32>& gtArray, GTString& src)
{
	GTArray<GTString> parts;
	GTStringUtil::Split(src, CTEXT(","), parts, GTStringUtil::RemoveEmptyEntries);
	if(0 == parts.Length())
	{
		return;
	}
	for(int32 i=0; i<parts.Length(); i++)
	{
		gtArray.Add(parts[i].Trim().ToInt());
	}
}


// Convert a GTString to GTArray<float>
void GTUtil::StringToArrayFloat(GTArray<float>& gtArray, GTString& src)
{
	GTArray<GTString> parts;
	GTStringUtil::Split(src, CTEXT(","), parts, GTStringUtil::RemoveEmptyEntries);
	if(0 == parts.Length())
	{
		return;
	}
	for(int32 i=0; i<parts.Length(); i++)
	{
		gtArray.Add(parts[i].Trim().ToFloat());
	}
}
