#include "pch.h"
#include "Player.h"
#include "Bmp_Manager.h"
#include "Key_Manager.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{

	CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Player/FinalPlayer(62X64X7ea).bmp", L"PLAYER_IMAGE");
	m_dwShotDelay = 100;
	m_pFrameKey = L"PLAYER_IMAGE";
	m_tInfo.fX = 300.f;
	m_tInfo.fY = 800.f;
	m_tInfo.fCX = 62.f;
	m_tInfo.fCY = 64.f;
	m_fSpeed = 3.f;
	m_eCurState = STATE_IDLE;
}

int CPlayer::Update()
{
	Key_Input();
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	__super::Move_Frame();
}

void CPlayer::Render(HDC hDC)
{
	HDC PlayerDC = CBmp_Manager::Get_Instance()->Find_Img(m_pFrameKey);

	//Rectangle(hDC, m_tInfo.fX - m_tInfo.fCX / 2, m_tInfo.fY - m_tInfo.fCY / 2, m_tInfo.fX + m_tInfo.fCX / 2, m_tInfo.fY + m_tInfo.fCY / 2);
	//피격 범위용 Rect => 조절 필요

	//switch (m_eCurState) {
	//case STATE_LEFT:

	//	GdiTransparentBlt(hDC,
	//		(int)m_tInfo.fX - m_tInfo.fCX / 2,	//복사 받을 X 위치
	//		(int)m_tInfo.fY - m_tInfo.fCY / 2,	//복사 받을 Y 위치
	//		62,									//복사 받을 가로 길이
	//		64,									//복사 받을 세로 길이
	//		PlayerDC,							//복사할 비트맵 DC
	//		62 * 3,								//비트맵 이미지의 왼쪽 X 좌표
	//		0,									//비트맵 이미지의 위쪽 Y 좌표
	//		m_tInfo.fCX,						//복사할 이미지의 가로 사이즈 
	//		m_tInfo.fCY,						//복사할 이미지의 세로 사이즈
	//		RGB(255, 255, 255));

	//	break;
	//case STATE_RIGHT:
	//	break;
	//case STATE_DASH:
	//	break;

	//case STATE_BACK:
	//	break;

	//case STATE_IDLE:
	//	GdiTransparentBlt(hDC,
	//		(int)m_tInfo.fX - m_tInfo.fCX / 2,	//복사 받을 X 위치
	//		(int)m_tInfo.fY - m_tInfo.fCY / 2,	//복사 받을 Y 위치
	//		62,									//복사 받을 가로 길이
	//		64,									//복사 받을 세로 길이
	//		PlayerDC,							//복사할 비트맵 DC
	//		62 * 3,								//비트맵 이미지의 왼쪽 X 좌표
	//		0,									//비트맵 이미지의 위쪽 Y 좌표
	//		m_tInfo.fCX,						//복사할 이미지의 가로 사이즈 
	//		m_tInfo.fCY,						//복사할 이미지의 세로 사이즈
	//		RGB(255, 255, 255));
	//	break;

	//default:
	//	GdiTransparentBlt(hDC,
	//		(int)m_tInfo.fX - m_tInfo.fCX / 2,	//복사 받을 X 위치
	//		(int)m_tInfo.fY - m_tInfo.fCY / 2,	//복사 받을 Y 위치
	//		62,									//복사 받을 가로 길이
	//		64,									//복사 받을 세로 길이
	//		PlayerDC,							//복사할 비트맵 DC
	//		62 * 3,								//비트맵 이미지의 왼쪽 X 좌표
	//		0,									//비트맵 이미지의 위쪽 Y 좌표
	//		m_tInfo.fCX,						//복사할 이미지의 가로 사이즈 
	//		m_tInfo.fCY,						//복사할 이미지의 세로 사이즈
	//		RGB(255, 255, 255));
	//	break;

	//}
	GdiTransparentBlt(hDC,
		(int)m_tInfo.fX - m_tInfo.fCX / 2,	//복사 받을 X 위치
		(int)m_tInfo.fY - m_tInfo.fCY / 2,	//복사 받을 Y 위치
		62,									//복사 받을 가로 길이
		64,									//복사 받을 세로 길이
		PlayerDC,							//복사할 비트맵 DC
		62 * 3,								//비트맵 이미지의 왼쪽 X 좌표
		0,									//비트맵 이미지의 위쪽 Y 좌표
		m_tInfo.fCX,						//복사할 이미지의 가로 사이즈 
		m_tInfo.fCY,						//복사할 이미지의 세로 사이즈
		RGB(255, 255, 255));

}

void CPlayer::Release(void)
{
}

void CPlayer::Key_Input()
{
	if (CKey_Manager::Get_Instance()->Key_Pressing(VK_LEFT)) {
		if (m_tInfo.fX > 0.f + m_tInfo.fCX/2.f) {
			m_tInfo.fX -= m_fSpeed;
			m_eDir = DIR_LEFT;
			m_eCurState = STATE_LEFT;
		}
		++m_iLeftCnt;
	}
	else if(CKey_Manager::Get_Instance()->Key_Pressing(VK_RIGHT)) {
		if (m_tInfo.fX < WINCX - m_tInfo.fCX / 2.f) {
			m_tInfo.fX += m_fSpeed;
			m_eDir = DIR_RIGHT;
			m_eCurState = STATE_RIGHT;
		}
		++m_iRightCnt;
	}
	else if (CKey_Manager::Get_Instance()->Key_Pressing(VK_UP)) {
		if (m_tInfo.fY > 0.f + m_tInfo.fCY / 2.f) {
			m_tInfo.fY -= m_fSpeed;
			m_eDir = DIR_UP;
			m_eCurState = STATE_DASH;
		}
	}
	else if (CKey_Manager::Get_Instance()->Key_Pressing(VK_DOWN)) {
		if (m_tInfo.fY < WINCY-m_tInfo.fCY / 2.f) {
			m_tInfo.fY += m_fSpeed;
			m_eDir = DIR_DOWN;
			m_eCurState = STATE_BACK;
		}
	}
	else if (CKey_Manager::Get_Instance()->Key_Down('a')) {

		Shot();
	}
	else {
		if (m_iLeftCnt > 0) {
			--m_iLeftCnt;
		}
		if (m_iRightCnt > 0) {
			--m_iRightCnt;
		}
	}



}

void CPlayer::Shot()
{
}

void CPlayer::Motion_Change()
{
	if (m_ePreState != m_eCurState)
	{
		switch (m_eCurState)
		{
		case STATE_IDLE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iMotion = 0;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount64();

			break;

		case STATE_LEFT:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 5;
			m_tFrame.iMotion = 1;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount64();
			break;

		case STATE_RIGHT:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 5;
			m_tFrame.iMotion = 2;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount64();
			break;

		case STATE_DASH:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 1;
			m_tFrame.iMotion = 3;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount64();
			break;

		case STATE_BACK:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iMotion = 4;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount64();
			break;
		}

		m_ePreState = m_eCurState;
	}
}
