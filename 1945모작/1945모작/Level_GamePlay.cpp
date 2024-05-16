#include "pch.h"
#include "Player.h"
#include "Bmp_Manager.h"
#include "Object_Manager.h"
#include "Level_GamePlay.h"
#include "AbstractFactory.h"

#define MAP_SizeY 5353
#define MAP_SizeX 600

CLevel_GamePlay::CLevel_GamePlay()
{
}

CLevel_GamePlay::~CLevel_GamePlay()
{
	Release();
}

void CLevel_GamePlay::Initialize()
{

	CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Map/Stage_A1.bmp", L"STAGE_A");
	CObject_Manager::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
}

int CLevel_GamePlay::Update()
{
	if(m_iMap_Update< MAP_SizeY)
		++m_iMap_Update;
	CObject_Manager::Get_Instance()->Update();
	return 0;
}

void CLevel_GamePlay::Late_Update()
{
	CObject_Manager::Get_Instance()->Late_Update();

}

void CLevel_GamePlay::Render(HDC hDC)
{
	HDC	hMemDC = CBmp_Manager::Get_Instance()->Find_Img(L"STAGE_A");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, MAP_SizeY-WINCY-m_iMap_Update, SRCCOPY);
	CObject_Manager::Get_Instance()->Render(hDC);
}

void CLevel_GamePlay::Release(void)
{
	CObject_Manager::Get_Instance()->DeleteID(OBJ_PLAYER);
}