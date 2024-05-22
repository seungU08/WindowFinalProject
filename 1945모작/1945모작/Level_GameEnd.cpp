#include "pch.h"
#include "Level_GameEnd.h"
#include "Bmp_Manager.h"
#include "Level_Manager.h"

CLevel_GameEnd::CLevel_GameEnd()
{
}

CLevel_GameEnd::~CLevel_GameEnd()
{
	Release();
}

void CLevel_GameEnd::Initialize()
{

}

int CLevel_GameEnd::Update()
{
	return 0;
}

void CLevel_GameEnd::Late_Update()
{
}

void CLevel_GameEnd::Render(HDC hDC)
{

	HDC	hMemDC = CBmp_Manager::Get_Instance()->Find_Img(L"Logo");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CLevel_GameEnd::Release(void)
{
}
