#ifndef _GREENTEA_TREE_NODE_H_
#define _GREENTEA_TREE_NODE_H_

#include "GTBaseDef.h"
#include "GTString.h"
#include "GTList.h"
#include "GTArray.h"
#include "GTPoint2.h"
#include "GTVector2.h"
#include "GTVector3.h"
#include "GTSize.h"

// GTPairValue class
class GTPairValue
{
public:
	GTPairValue(GTString n, GTString v)
	{
		m_sName = n;
		m_sValue = v;
	}
	GTPairValue(const tchar* n, const tchar* v)
	{
		m_sName = n;
		m_sValue = v;
	}
	~GTPairValue()
	{
	}

public:
	GTString m_sName;
	GTString m_sValue;
};

// GTTreeNode class
class GTTreeNode
{
public:
	GTTreeNode();
	virtual ~GTTreeNode();
	
	// Whether the GTTreeNode has a valid value.
	bool HasValue()
	{
		return (!m_sValue.IsEmpty());
	}

	// Whether the node has children.
	bool HasChildren()
	{
		return (m_Children.Count() ? true : false);
	}

	// Set the tag
	void SetTag(const tchar* szTag)
	{
		m_sTag = szTag;
	}

	// Set the value
	void SetValue(const tchar* szValue)
	{
		m_sValue = szValue;
	}

	// Get the tag
	const GTString& GetTag() const
	{
		return m_sTag;
	}

	const GTString Tag() const
	{
		return m_sTag;
	}

	// Get the value
	const GTString& GetValue() const
	{
		return m_sValue;
	}

	const GTString& Value() const
	{
		return m_sValue;
	}

	// Translate the value to integer 
	int32 ValueToInt(void) const
	{
		return m_sValue.ToInt();
	}
	// Translate the value to unsigned integer 
	uint32 ValueToUInt(void) const
	{
		return m_sValue.ToUInt();
	}
	// Translate the value to float
	float ValueToFloat(void) const
	{
		return m_sValue.ToFloat();
	}
	// Translate the value to bool
	bool ValueToBool(void) const
	{
		return m_sValue.ToBool();
	}
	// Translate the value to GTVector2
	GTVector2 ValueToVector2(void) const;
	// Translate the value to GTVector3
	GTVector3 ValueToVector3(void) const;
	// Translate the value to GTSize
	GTSize ValueToSize(void) const;
	// Translate the value to GTPairValue
	GTPairValue ValueToPairValue(void) const;
	// Translate the value to GTArray<int32>, separated by space
	void ValueToArrayInt(GTArray<int32>& gtArray);
	// Translate the value to GTArray<float>, separated by space
	void ValueToArrayFloat(GTArray<float>& gtArray);
	// Translate the value to GTArray<GTString>, separated by space
	void ValueToArrayString(GTArray<GTString>& gtArray);

	// Helper comparison function.
	bool TagIs(const tchar* sTagText) const
	{
		return m_sTag.IsEqual(sTagText);
	}

	// Helper comparison function.
	bool ValueIs(const tchar* sValueText) const
	{
		return m_sValue.IsEqual(sValueText);
	}

	// Get the count of children
	int32 GetChildCount() const
	{
		return m_Children.Count();
	}

	// Helper function that converts a hex digit to its decimal representation
	int16 ReadHex(tchar ch);
	// Adds a new child to this node.
	GTTreeNode* AddChild();
	// Adds an existing tree node as a child of this one.
	GTTreeNode* AddChild(GTTreeNode* child);
	// Adds a new child node to this node.
	GTTreeNode* AddChild(const tchar* tag);
	// Retrieves a child node by its tag. This method does not recurse into children.
	GTTreeNode* GetChild(const tchar* szTag, bool bVerifyCase);
	// Retrieves a child node by its tag. This method does not recurse into children.
	GTTreeNode* GetChild(const tchar* szTag);
	// Retrieves a child node by its index. This method does not recurse into children.
	GTTreeNode* GetChild(const int32 nIndex);
	// Recursive search for a child with the specified tag.
	GTTreeNode* FindChild(const tchar* szTag, bool bVerifyCase);
	// Recursive search for a child with the specified tag.
	GTTreeNode* FindChild(const tchar* szTag);
	// Finds a node that contains a child with the requested tag.
	GTTreeNode* FindParentOf(const tchar* szTag);

	// Release
	void Release();

	// Build up this tree node from a string stream
	static GTTreeNode* FromString(const tchar* szText);

private:
	// Proces lines
	int32 ProcessLines(GTArray<GTString>& lines, int32 offset);	

public:
	// The tag of this tree node
	GTString m_sTag;
	// The value of this tree node
	GTString m_sValue;
	// The children of this tree node
	GTList<GTTreeNode*> m_Children;

	//private static string mDecimalSeparator = System.Globalization.NumberFormatInfo.CurrentInfo.CurrencyDecimalSeparator;
};

// The helper macro to release a GTTreeNode object
#define GTTREENODE_RELEASE(_ptr) {if(_ptr){_ptr->Release();_ptr = NULL;}}

#endif /* _GREENTEA_TREE_NODE_H_ */
