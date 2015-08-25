#include "BSIconLoader.h"
#include "GameObjectCreation.h"
#include "GameGeneral.h"
#include "GTGameObjectManager.h"

GTBEHAVIOUR_IMP(BSIconLoader, GTBehaviour);

#define PROPERTY_TAG_ICONLOADER				CTEXT("IconLoader")

#define PROPERTY_TAG_WILDICON		CTEXT("Wild_Symbol_ID")
#define PROPERTY_TAG_BONUSICON		CTEXT("Bonus_Symbol_ID")
#define PROPERTY_TAG_REELICON		CTEXT("ReelIcon")

BSIconLoader::BSIconLoader()
{
}


BSIconLoader::~BSIconLoader()
{
}


// This method is called when GTBehaviour object is created.
int32 BSIconLoader::OnCreate(void)
{
	GTBehaviour::OnCreate();
	
	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSIconLoader::OnInitialize(GTBehaviourInitParam* param)
{
	GTBehaviour::OnInitialize(param);

	if(NULL == param || NULL == param->pParam2)
	{
		return 0;
	}

	return CreateFromPropertyTreeNode((GTTreeNode*)param->pParam2) ? 1 : 0;
}


// This method is called before first OnUpdate
int32 BSIconLoader::OnStart(void)
{
	GTBehaviour::OnStart();
	
	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSIconLoader::OnUpdate(void)
{
	GTBehaviour::OnUpdate();
	
	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSIconLoader::OnDestroy(void)
{
	GTBehaviour::OnDestroy();
	
	for(int i= 0; i<m_reelIcons.Count(); i++)
	{
		m_reelIcons[i]->sprite->Release();
		delete m_reelIcons[i];
	}

	return 1;
}

// Create the sprite from the property tree node
bool BSIconLoader::CreateFromPropertyTreeNode(GTTreeNode *pTreeNode)
{
	if(NULL == pTreeNode)
	{
		return false;
	}


	bool res = false;
	GTString errorCode("");
		
	//get wild symbol ID
	GTTreeNode* pWildIconNode = pTreeNode->GetChild(PROPERTY_TAG_WILDICON);
	if(NULL == pWildIconNode)
	{
		return false;
	}
	m_wildIconID = pWildIconNode->GetValue().ToInt();


	//get bonus symbol ID
	GTTreeNode* pBonusIconNode = pTreeNode->GetChild(PROPERTY_TAG_BONUSICON);
	if(NULL == pBonusIconNode)
	{
		return false;
	}
	m_bonusIconID = pBonusIconNode->GetValue().ToInt();
	

	//load all reel icons;
	int id = 0;
	do 
	{
		//set reel name
		GTString iconName = PROPERTY_TAG_REELICON;
		iconName.Append(GTString::From(id));// + GTString::FormatFrom(id);
		GTTreeNode* pReelIconFile = pTreeNode->GetChild(iconName.ToCharString());

		if(pReelIconFile == NULL)
			break;

		GTString filename = pReelIconFile->GetValue();

		GSprite* pSprite = GameObjectCreation::CreateAnimatedSprite(
			filename,
			GameGeneral::GetInstance()->GetZOrderIdSprite()
			);
		if(NULL == pSprite)
		{
			break;
		}
		else
		{
			ReelIcon* reelIcon = new ReelIcon(id++, pSprite);
			m_reelIcons.AddToTail(reelIcon);
		}
	} while (true);

	return res;
}

//get GSprite instance
GSprite* BSIconLoader::GetReelIcon(int id)
{
	if(m_reelIcons.Count() <= id)
	{
		GTLogManager::GetInstance()->LogFormatError("Error! Out of range of reel icons!  total = %d, but id = %d .", m_reelIcons.Count(), id);
		return NULL;
	}
	else
		return m_reelIcons[id]->sprite;
}

//get instance
BSIconLoader* BSIconLoader::GetInstance()
{
	GTGameObject* pIconLoaderObj = NULL;	
	BSIconLoader* pIconLoader = NULL;

	pIconLoaderObj = GTGameObjectManager::FindGameObject(PROPERTY_TAG_ICONLOADER);
	if(pIconLoaderObj)
		pIconLoader = (BSIconLoader*)pIconLoaderObj->GetBehaviour("BSIconLoader");

	if(NULL == pIconLoader)
	{
		GTLogManager::SLogError("Error! Can't find IconLoader!");
		return NULL;
	}

	return pIconLoader;
}

//get Icon counts
int BSIconLoader::GetIconsCount()
{
	BSIconLoader* pIconLoader = GetInstance();
	if(pIconLoader == NULL)
		return 0;
	else
		return pIconLoader->GetReelIconCount();
}

