#include "BSWinlineLoader.h"
#include <GTLog\GTLogManager.h>
#include "GTGameObject.h"
#include "..\UI\UIDef.h"
#include "..\..\GreenTeaSource\GTGameObjectManager.h"


#define PROPERTY_TAG_WINLINELOADER				CTEXT("WinlineLoader")

#define PROPERTY_TAG_WINLINE				CTEXT("Winline")		//winline keyword
#define PROPERTY_TAG_PAYTABLE				CTEXT("PayTable")		//Pay table keyword
#define PROPERTY_TAG_WINLINE_SPRITE_KEY		CTEXT("WinlineSprite")		//winline sprite keyword

GTBEHAVIOUR_IMP(BSWinlineLoader, GTBehaviour);

BSWinlineLoader::BSWinlineLoader()
{	
	m_winlineSprite = NULL;
}


BSWinlineLoader::~BSWinlineLoader()
{
}


// This method is called when GTBehaviour object is created.
int32 BSWinlineLoader::OnCreate(void)
{
	GTBehaviour::OnCreate();
	
	return 1;
}


// This method is called when GTBehaviour object is initialized.
int32 BSWinlineLoader::OnInitialize(GTBehaviourInitParam* param)
{
	GTBehaviour::OnInitialize(param);

	if(NULL == param || NULL == param->pParam2)
	{
		return 0;
	}

	return CreateFromPropertyTreeNode((GTTreeNode*)param->pParam2) ? 1 : 0;
}


// This method is called before first OnUpdate
int32 BSWinlineLoader::OnStart(void)
{
	GTBehaviour::OnStart();
	
	bool res = false;
	GTString errorCode("");

	GTString winlineSpriteKey = PROPERTY_TAG_WINLINE_SPRITE_KEY;
	GTGameObject * childGO = m_pGameObject->FindChild(winlineSpriteKey.ToCharString(), true);
	if(childGO != NULL)
	{	
		m_winlineSprite = (BSSprite*)(childGO->GetBehaviour(CTEXT("BSSprite")));
		if(m_winlineSprite == NULL)
		{
			res = false;
			errorCode = winlineSpriteKey;
		}
		else
			res = true;
	}

	if(!res)
		GTLogManager::SLogFormatError(CTEXT("Error!!! BSWinlineLoader can not find BSSprite: %s "), errorCode.ToCharString());

	m_winlineSprite->SetZOrder(UI_ZOrder::WINLINE);
	return 1;
}


// This method is called when GTBehaviour object is updated.
int32 BSWinlineLoader::OnUpdate(void)
{
	GTBehaviour::OnUpdate();
	
	return 1;
}


// This method is called when GTBehaviour object is destroyed.
int32 BSWinlineLoader::OnDestroy(void)
{
	GTBehaviour::OnDestroy();
	
	return 1;
}


// Create the sprite from the property tree node
bool BSWinlineLoader::CreateFromPropertyTreeNode(GTTreeNode *pTreeNode)
{
	if(NULL == pTreeNode)
	{
		return false;
	}


	bool res = false;
	GTString errorCode("");

	//load all winlines;  Note: from winline 1 -> n 
	int winlineID = 1;
	do 
	{
		//set reel name
		GTString winlineTag = PROPERTY_TAG_WINLINE;
		winlineTag.Append(GTString::From(winlineID));// + GTString::FormatFrom(id);
		GTTreeNode* pWinline = pTreeNode->GetChild(winlineTag.ToCharString());

		if(pWinline == NULL)
			break;

		GTArray<int> winlineSlotArray;	//winline slot define;
		pWinline->ValueToArrayInt(winlineSlotArray);

		if(m_winlineDict.KeyExists(winlineID))
		{
			m_winlineDict.Remove(winlineID);
			GTLogManager::SLogFormatWarning("Warning! new winline[%d] will replace old one!!", winlineID);
		}
		m_winlineDict.Add(winlineID, winlineSlotArray);
		winlineID++;		
	} while (true);


	//load paytable; from 1 -> n
	int wintableID = 1;
	do 
	{
		//set reel name
		GTString PayTableTag = PROPERTY_TAG_PAYTABLE;
		PayTableTag.Append(GTString::From(wintableID));// + GTString::FormatFrom(id);
		GTTreeNode* pPaytable = pTreeNode->GetChild(PayTableTag.ToCharString());

		if(pPaytable == NULL)
			break;

		GTArray<int> payTableValue;	//winline slot define;
		pPaytable->ValueToArrayInt(payTableValue);

		if(payTableValue.Length() < 2)
		{
			GTLogManager::SLogFormatError("Error! Paytable[%d] does not have 2 values!", wintableID);
		}
		else
		{
			int paytableID = payTableValue[0];
			int ptValue = payTableValue[1];
			if(m_paytableDict.KeyExists(paytableID))
			{
				m_paytableDict.Remove(paytableID);
				GTLogManager::SLogFormatWarning("Warning! new paytable[%d] will replace old one!!", wintableID);
			}
			m_paytableDict.Add(paytableID, ptValue);
		}
		wintableID++;		
	} while (true);


	return res;
}

void BSWinlineLoader::ShowWinlineSprite(int winlineID, bool visibility)
{
	if(m_winlineSprite == NULL)
		return;
	m_winlineSprite->m_pSprite->SetVisible(visibility);

	if(visibility)
		m_winlineSprite->SetDisplayFrameByIndex(0, winlineID - 1);	//because our winlines are from 1 to N, but function is from 0 to N-1;
}

	
//GetWinlineLoad;
BSWinlineLoader* BSWinlineLoader::GetInstance()
{
	GTGameObject* pWinlineLoaderObj = NULL;	
	BSWinlineLoader* winlineLoader = NULL;

	pWinlineLoaderObj = GTGameObjectManager::FindGameObject(PROPERTY_TAG_WINLINELOADER);
	if(pWinlineLoaderObj)
		winlineLoader = (BSWinlineLoader*)pWinlineLoaderObj->GetBehaviour("BSWinlineLoader");

	if(NULL == winlineLoader)
	{
		GTLogManager::SLogError("Error! Can't find IconLoader!");
		return NULL;
	}
	return winlineLoader;
}