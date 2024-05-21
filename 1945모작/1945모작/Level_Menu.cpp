#include "pch.h"
#include "Button.h"
#include "Level_Menu.h"
#include "Bmp_Manager.h"
#include "Object_Manager.h"
#include "Level_GamePlay.h"
#include "AbstractFactory.h"

CLevel_Menu::CLevel_Menu()
{
}

CLevel_Menu::~CLevel_Menu()
{
}

void CLevel_Menu::Initialize()
{
	CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Menu/MenuBackGround(600X900).bmp", L"BACKGROUND");
	CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Menu/StartButton(201X51X2).bmp", L"START_BUTTON");
	CGameObject* pButton = CAbstractFactory<CButton>::Create(300.f, 600.f);
	pButton->Set_FrameKey(L"START_BUTTON");
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BUTTON,pButton);

}

int CLevel_Menu::Update()
{
	CObject_Manager::Get_Instance()->Update();
	return 0;
}

void CLevel_Menu::Late_Update()
{
	CObject_Manager::Get_Instance()->Late_Update();
}

void CLevel_Menu::Render(HDC hDC)
{
	HDC	hMemDC = CBmp_Manager::Get_Instance()->Find_Img(L"BACKGROUND");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0,0, SRCCOPY);
	CObject_Manager::Get_Instance()->Render(hDC);
}

void CLevel_Menu::Release(void)
{
	CObject_Manager::Get_Instance()->DeleteID(OBJ_BUTTON);
}
