#include "pch.h"
#include "UI.h"
#include "Bmp_Manager.h"

CUI::CUI()
{
}

CUI::~CUI()
{
}

void CUI::Initialize()
{
}

int CUI::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CUI::Late_Update()
{

	if(m_eUIState == UI_ANIM)
		__super::Move_Frame();
}

void CUI::Render(HDC hDC)
{
	HDC	hMemDC = CBmp_Manager::Get_Instance()->Find_Img(m_pFrameKey);
	if (m_eUIState == UI_NONANIM) {
		

		GdiTransparentBlt(
			hDC,
			m_tRect.left,
			m_tRect.top,
			(int)m_tInfo.fCX,
			(int)m_tInfo.fCY,
			hMemDC,
			0,
			0,
			(int)m_tInfo.fCX,
			(int)m_tInfo.fCY,
			RGB(255, 255, 255));
	}
	else if(m_eUIState == UI_ANIM){

		GdiTransparentBlt(
			hDC,
			m_tRect.left,										// 복사받을 X위치
			m_tRect.top,										// 복사받을 Y위치
			(int)m_tInfo.fCX,									// 복사 받을 가로 길이
			(int)m_tInfo.fCY,									// 복사 받을 세로 길이
			hMemDC,											// 복사할 비트맵 DC
			m_tFrame.iFrameStart * (int)m_tInfo.fCX,			// 비트맵 출력 X좌표
			0,													// 비트맵 출력 Y좌표
			(int)m_tInfo.fCX,									// 복사할 비트맵의 가로 길이
			(int)m_tInfo.fCY,									// 복사할 비트맵의 세로 길이
			RGB(255, 255, 255));

	}

}

void CUI::Release(void)
{
}


void CUI::Set_State(UISTATE eState)
{
	m_eUIState = eState;
}