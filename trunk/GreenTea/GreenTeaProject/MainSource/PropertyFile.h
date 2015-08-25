#ifndef _PROPERTY_FILE_H_
#define _PROPERTY_FILE_H_

#include <GTBaseDef.h>
#include <GTTreeNode.h>

class GTTreeNode;
class GTGameObject;

#define PROPERTYFILE_TAG_DEF(tagName) static const tchar* Tag##tagName;
#define PROPERTYFILE_TAG_IMP(tagName) const tchar* PropertyFile::Tag##tagName = CTEXT(#tagName);

class PropertyFile
{
public:
	PropertyFile();
	~PropertyFile();

public:
	// Load property file and return GTTreeNode object
	static GTTreeNode* Load(const tchar* szFileName);
	// Apply all behaviour scripts under TagBehaviour to a game object
	static bool ApplyBehaviourForGameObject(GTTreeNode *pBehaviourNode, GTGameObject *pGameObject, void* param);

public:
	// Property node names
	// A
	PROPERTYFILE_TAG_DEF(AnchorPoint);
	PROPERTYFILE_TAG_DEF(Animation);
	// B
	PROPERTYFILE_TAG_DEF(Behaviour);
	// C
	PROPERTYFILE_TAG_DEF(Children);
	PROPERTYFILE_TAG_DEF(Clip);
	PROPERTYFILE_TAG_DEF(Collision);
	PROPERTYFILE_TAG_DEF(CustomizedValue);
	// D
	PROPERTYFILE_TAG_DEF(Default);
	PROPERTYFILE_TAG_DEF(DefaultAnimation);
	PROPERTYFILE_TAG_DEF(DefaultAnimationPlayMode);
	PROPERTYFILE_TAG_DEF(DefaultBehaviourClass);
	PROPERTYFILE_TAG_DEF(DelayTime);
	// E
	PROPERTYFILE_TAG_DEF(EndFrame);
	PROPERTYFILE_TAG_DEF(EventType);
	// F
	PROPERTYFILE_TAG_DEF(Font);
	// G
	PROPERTYFILE_TAG_DEF(GameObject);
	// H
	static const tchar* TagHeight;
	// I
	PROPERTYFILE_TAG_DEF(Image);
	// N
	static const tchar* TagNameV1;
	static const tchar* TagNameV2;
	// P
	PROPERTYFILE_TAG_DEF(PairValue);
	PROPERTYFILE_TAG_DEF(Piece);
	PROPERTYFILE_TAG_DEF(PieceEnabled);
	PROPERTYFILE_TAG_DEF(PieceDisabled);
	PROPERTYFILE_TAG_DEF(PiecePressed);
	PROPERTYFILE_TAG_DEF(Plist);
	PROPERTYFILE_TAG_DEF(Position);
	PROPERTYFILE_TAG_DEF(Prefix);
	PROPERTYFILE_TAG_DEF(Property);
	PROPERTYFILE_TAG_DEF(PropertyName);
	// S	
	PROPERTYFILE_TAG_DEF(Script);
	PROPERTYFILE_TAG_DEF(Size);
	PROPERTYFILE_TAG_DEF(Skin);
	PROPERTYFILE_TAG_DEF(Sprite);
	PROPERTYFILE_TAG_DEF(SpriteBehaviourClass);
	PROPERTYFILE_TAG_DEF(StartFrame);
	// T
	PROPERTYFILE_TAG_DEF(Text);
	PROPERTYFILE_TAG_DEF(Texture);
	static const tchar* TagType;
	// U
	PROPERTYFILE_TAG_DEF(UILayout);
	PROPERTYFILE_TAG_DEF(UISkin);
	// V
	PROPERTYFILE_TAG_DEF(Visible);
	// W
	static const tchar* TagWidth;
	// X
	static const tchar* TagX;
	// Y
	static const tchar* TagY;
};

#endif /* _PROPERTY_FILE_H_ */
