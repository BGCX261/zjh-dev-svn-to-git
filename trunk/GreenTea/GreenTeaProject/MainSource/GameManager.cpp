#include "GameManager.h"
#include "SceneManager.h"
#include <GTLog/GTLogManager.h>
#include "UI/FontManager.h"
#include "SystemManager.h"
#include "MapManager.h"
#include <stdio.h>

GTSINGLETON_IMP(GameManager);

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}


// When the object is initialized, this method is called.
int32 GameManager::OnInitialize(void)
{
	//pTexture = GameObjectCreation::CreateTexture2D(CTEXT("./textures/bg.png"));
	//pTexture = GameObjectCreation::CreateTexture2D("./textures/tmw_desert_spacing.png");
	//pTexture = GameObjectCreation::CreateTexture2D("./textures/blocks.png");

	//pTexture = GameObjectCreation::CreateTexture2D(CTEXT("./textures/pathfind_grid_32x32.png"));

	// Load the scene
	//SceneManager::GetInstance()->LoadScene(CTEXT("./scenes/blocks_v2_1.tmx.xml"));
	//SceneManager::GetInstance()->LoadScene(CTEXT("./scenes/blocks_v2_2.tmx.xml"));
	//SceneManager::GetInstance()->LoadScene(CTEXT("./scenes/blocks_40x40.tmx.xml"));
	//SceneManager::GetInstance()->LoadScene(CTEXT("./scenes/blocks_40x40.tmx.xml.map"));

	//SceneManager::GetInstance()->LoadScene(CTEXT("./scenes/stage_01_20x20_32x32.tmx.map"));
	//SceneManager::GetInstance()->LoadScene(CTEXT("./scenes/stage_01_20x20_40x40.tmx.map"));
	//SceneManager::GetInstance()->LoadScene(CTEXT("./scenes/stage_test_01_40x30_32x32.tmx.map"));

	//GameObjectCreation::LoadMap(CTEXT("maps/ground_01_512x512_32x32.tmx"));
	
	//GameObjectCreation::LoadMap(CTEXT("maps/blocks_32x32.tmx"));
	
	//GameObjectCreation::LoadMap(CTEXT("maps/Stage01_map_editor.tmx"));
	//GameObjectCreation::LoadMap(CTEXT("maps/Stage05_map_editor.tmx"));
	SceneManager::GetInstance()->LoadScene(CTEXT("maps/Stage06_map_editor.tmx"));
	//GameObjectCreation::LoadMap(CTEXT("maps/Stage08_map_editor.tmx"));
	SceneManager::GetInstance()->SetScreenPositionInMap(0, 0);

	return 1;
}


// When the system is updated, this method is called for each frame.
int32 GameManager::OnUpdate(void)
{
	return 1;
}


// This method is called for rendering each frame.
int32 GameManager::OnRender(void)
{
	/*
	if(pTexture)
	{
		//pTexture->Render(10, 50);
		//pTexture->RenderRect(10, 10, 32, 32, 32, 32);
		//pTexture->RenderStretch(10, 120, 10+128, 120+128);
		//pTexture->RenderEx(300, 120, 3.1415926f/4.0f, 2.0f, 1.5f);
		//pTexture->Render4V(110, 10, 150, 20, 170, 100, 80, 80);
		//pTexture->Render4V(110, 10, 170, 10, 170, 80, 110, 80);
		if(m_ScenePathFindingResult.nLength)
		{
			SceneLayer* pLayer = SceneManager::GetInstance()->GetObstacleLayer();
			if(pLayer)
			{
				const int32 nTileW = pLayer->GetTileWidth();
				const int32 nTileH = pLayer->GetTileHeight();
				for(int32 len=0; len<m_ScenePathFindingResult.nLength; len++)
				{
					pTexture->Render(
						(float)(m_ScenePathFindingResult.pos[len].x*nTileW),
						(float)(m_ScenePathFindingResult.pos[len].y*nTileH)
						);
				}
			}
		}
	}
	*/

	/*
	float fRot = 0.0f;
	float fScale = 2.0f;
	FontManager* pFontMgr = FontManager::GetInstance();
	if(pFontMgr->m_pFont1)
	{
		pFontMgr->m_pFont1->DrawString(10.0f, 10.0f, GTEXT_LEFT, CTEXT("TankBattle"), 0xFFFFFFFF);
		pFontMgr->m_pFont1->DrawString(10.0f, 50.0f, GTEXT_LEFT, CTEXT("TankBattle"), 0xFF00FF00, fRot, fScale, fScale);
	}
		
	GTPoint2 pos = SceneManager::GetInstance()->GetPosition();	
	if(pFontMgr->m_pFont2)
	{
		tsprintf(buf, CTEXT("Map Pos=(%d,%d)"), pos.x, pos.y);
		pFontMgr->m_pFont2->DrawString(10.0f, 90.0f, GTEXT_LEFT, buf, 0xFF0000FF);
		tsprintf(buf, CTEXT("Touch Pos=(%d,%d)"), (int32)m_vTouchPosition.x, (int32)m_vTouchPosition.y);
		pFontMgr->m_pFont2->DrawString(10.0f, 110.0f, GTEXT_LEFT, buf, 0xFF0000FF);
	}

	// Render PlayerManager object
	PlayerManager::GetInstance()->OnRender();
	// Render EnemyManager object
	EnemyManager::GetInstance()->OnRender();
	*/

	return 1;
}


// Before the system is shut down, this method is called.
int32 GameManager::OnDestroy(void)
{
	// Release SceneManager object
	SceneManager::GetInstance()->ReleaseScene();

	return 1;
}
