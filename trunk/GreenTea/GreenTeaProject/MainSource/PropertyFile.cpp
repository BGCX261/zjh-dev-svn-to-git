#include "PropertyFile.h"
#include <GTCommon/FileUtil.h>
#include <GTGreenTea.h>
#include <GTLog/GTLogManager.h>

// Property node names
// A
PROPERTYFILE_TAG_IMP(AnchorPoint);
PROPERTYFILE_TAG_IMP(Animation);
// B
PROPERTYFILE_TAG_IMP(Behaviour);
// C
PROPERTYFILE_TAG_IMP(Children);
PROPERTYFILE_TAG_IMP(Clip);
PROPERTYFILE_TAG_IMP(Collision);
PROPERTYFILE_TAG_IMP(CustomizedValue);
// D
PROPERTYFILE_TAG_IMP(Default);
PROPERTYFILE_TAG_IMP(DefaultAnimation);
PROPERTYFILE_TAG_IMP(DefaultAnimationPlayMode);
PROPERTYFILE_TAG_IMP(DefaultBehaviourClass);
PROPERTYFILE_TAG_IMP(DelayTime);
// E
PROPERTYFILE_TAG_IMP(EndFrame);
PROPERTYFILE_TAG_IMP(EventType);
// F
PROPERTYFILE_TAG_IMP(Font);
// G
PROPERTYFILE_TAG_IMP(GameObject);
// H
const tchar* PropertyFile::TagHeight = CTEXT("height");
// I
PROPERTYFILE_TAG_IMP(Image);
// N
const tchar* PropertyFile::TagNameV1 = CTEXT("name");
const tchar* PropertyFile::TagNameV2 = CTEXT("Name");
// P
PROPERTYFILE_TAG_IMP(PairValue);
PROPERTYFILE_TAG_IMP(Piece);
PROPERTYFILE_TAG_IMP(PieceEnabled);
PROPERTYFILE_TAG_IMP(PieceDisabled);
PROPERTYFILE_TAG_IMP(PiecePressed);
PROPERTYFILE_TAG_IMP(Plist);
PROPERTYFILE_TAG_IMP(Position);
PROPERTYFILE_TAG_IMP(Prefix);
PROPERTYFILE_TAG_IMP(Property);
PROPERTYFILE_TAG_IMP(PropertyName);
// S
PROPERTYFILE_TAG_IMP(Script);
PROPERTYFILE_TAG_IMP(Size);
PROPERTYFILE_TAG_IMP(Skin);
PROPERTYFILE_TAG_IMP(Sprite);
PROPERTYFILE_TAG_IMP(SpriteBehaviourClass);
PROPERTYFILE_TAG_IMP(StartFrame);
// T
PROPERTYFILE_TAG_IMP(Text);
PROPERTYFILE_TAG_IMP(Texture);
const tchar* PropertyFile::TagType = CTEXT("type");
// V
PROPERTYFILE_TAG_IMP(Visible);
// U
PROPERTYFILE_TAG_IMP(UILayout);
PROPERTYFILE_TAG_IMP(UISkin);
// W
const tchar* PropertyFile::TagWidth = CTEXT("width");
// X
const tchar* PropertyFile::TagX = CTEXT("x");
// Y
const tchar* PropertyFile::TagY = CTEXT("y");

PropertyFile::PropertyFile()
{
}


PropertyFile::~PropertyFile()
{
}


// Load property file and return GTTreeNode object
GTTreeNode* PropertyFile::Load(const tchar* szFileName)
{
	if(szFileName == NULL)
	{
		return NULL;
	}

	GTTreeNode* pTreeNode = NULL;
	unsigned long size = 0;
	// Load property file
	char* pContent = (char*)FileUtil::ReadTextFileData(szFileName, &size);
	if(pContent)
	{
		// Format the string
		pTreeNode = GTTreeNode::FromString(pContent);
		// Release pContent
		delete[] pContent;
		pContent = NULL;
	}

	return pTreeNode;
}


// Apply all behaviour scripts under TagBehaviour to a game object
bool PropertyFile::ApplyBehaviourForGameObject(
	 GTTreeNode *pBehaviourNode,
	 GTGameObject *pGameObject,
	 void* param
	)
{
	if(NULL == pBehaviourNode || NULL == pGameObject)
	{
		return false;
	}

	GTBehaviourInitParam initParam;
	// Get the count of behaviour scripts attached to this object
	const int32 nNodeCount = pBehaviourNode->GetChildCount();
	for(int count=0; count<nNodeCount; count++)
	{
		// Get a node of behaviour script
		GTTreeNode* pChild = pBehaviourNode->GetChild(count);
		if(pChild)
		{
			if(pChild->Tag() == PropertyFile::TagScript)
			{
				// Prepare the paramters for behaviour initialization
				initParam.pParam1 = param;
				initParam.pParam2 = pChild;

				GTBehaviour *pBehaviour = pGameObject->AddComponent(pChild->GetValue().ToCharString(), &initParam);
				if(NULL == pBehaviour)
				{
					GTLogManager::GetInstance()->LogFormatError(CTEXT("Failed to AddComponent '%s' for the game object '%s'"), pChild->GetValue().ToCharString(), pGameObject->GetName());
				}
			}
		}
	}

	return true;
}
