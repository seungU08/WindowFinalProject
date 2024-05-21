#include "pch.h"
#include "Level_Logo.h"
#include "Bmp_Manager.h"
#include "Level_Manager.h"

CLevel_Logo::CLevel_Logo()
{
}

CLevel_Logo::~CLevel_Logo()
{
	Release();
}

void CLevel_Logo::Initialize()
{

}

int CLevel_Logo::Update()
{
	return 0;
}

void CLevel_Logo::Late_Update()
{
}

void CLevel_Logo::Render(HDC hDC)
{

	HDC	hMemDC = CBmp_Manager::Get_Instance()->Find_Img(L"Logo");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CLevel_Logo::Release(void)
{
}
