#include "pch.h"
#include "Player.h"
#include "Bmp_Manager.h"
#include "Key_Manager.h"
#include "Object_Manager.h"
#include "AbstractFactory.h"
#include "Player_Bullet.h"

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
	CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Bullet/PlayerBullet/MainBullet/MainBullet(24X72X4).bmp", L"MAINBULLET_IMAGE");
	CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Bullet/PlayerBullet/SubBullet/SubBullet(24X63X4).bmp", L"SUBBULLET_IMAGE");
	CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Bullet/PlayerBullet/SideBullet/SideBullet_LEFT(24X42X4).bmp", L"SIDELBULLET_IMAGE");
	CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Bullet/PlayerBullet/SideBullet/SideBullet_RIGHT(24X42X4).bmp", L"SIDERBULLET_IMAGE");

	m_dwShotDelay = 100;
	m_pFrameKey = L"PLAYER_IMAGE";
	m_tInfo.fX = 300.f;
	m_tInfo.fY = 800.f;
	m_tInfo.fCX = 62.f;
	m_tInfo.fCY = 64.f;
	m_fSpeed = 3.f;
	m_iFrameCnt = 3;
	m_dwShotCount = GetTickCount64();
	m_dwShotDelay = 150;
	m_ePlayerShotState = PLAYER_FINAL;
	m_iLife = 4;

}

int CPlayer::Update()
{
	++m_iScore;
	Key_Input();
	__super::Update_Rect();
	Player_X = m_tInfo.fX;
	Player_Y = m_tInfo.fY;
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
	//�ǰ� ������ Rect => ���� �ʿ�

	GdiTransparentBlt(hDC,
		(int)m_tInfo.fX - m_tInfo.fCX / 2,	//���� ���� X ��ġ
		(int)m_tInfo.fY - m_tInfo.fCY / 2,	//���� ���� Y ��ġ
		62,									//���� ���� ���� ����
		64,									//���� ���� ���� ����
		PlayerDC,							//������ ��Ʈ�� DC
		62 * m_iFrameCnt,					//��Ʈ�� �̹����� ���� X ��ǥ
		0,									//��Ʈ�� �̹����� ���� Y ��ǥ
		m_tInfo.fCX,						//������ �̹����� ���� ������ 
		m_tInfo.fCY,						//������ �̹����� ���� ������
		RGB(255, 255, 255));

}

void CPlayer::Release(void)
{
}

void CPlayer::Key_Input()
{
	if (CKey_Manager::Get_Instance()->Key_Pressing(VK_LEFT)) {
		if (m_tInfo.fX > 0.f + m_tInfo.fCX / 2.f) {
			m_tInfo.fX -= m_fSpeed;
			m_eDir = DIR_LEFT;
			if (m_iFrameCnt > 0)
				m_iFrameCnt--;
		}
	}
	else if (CKey_Manager::Get_Instance()->Key_Pressing(VK_RIGHT)) {
		if (m_tInfo.fX < WINCX - m_tInfo.fCX / 2.f) {
			m_tInfo.fX += m_fSpeed;
			m_eDir = DIR_RIGHT;
			if (m_iFrameCnt < 6)
				m_iFrameCnt++;
		}
	}
	else {
		if (m_iFrameCnt < 3)
			m_iFrameCnt++;
		else if (m_iFrameCnt > 3)
			m_iFrameCnt--;
	}

	if (CKey_Manager::Get_Instance()->Key_Pressing(VK_UP)) {
		if (m_tInfo.fY > 0.f + m_tInfo.fCY / 2.f) {
			m_tInfo.fY -= m_fSpeed;
			m_eDir = DIR_UP;
		}
	}

	if (CKey_Manager::Get_Instance()->Key_Pressing(VK_DOWN)) {
		if (m_tInfo.fY < WINCY - m_tInfo.fCY / 2.f) {
			m_tInfo.fY += m_fSpeed;
			m_eDir = DIR_DOWN;
		
		}
	}

	if (GetTickCount64() - m_dwShotCount > m_dwShotDelay) {
		Shot();
		m_dwShotCount = GetTickCount64();
		
	}
}

void CPlayer::Shot()
{
	CObject_Manager::Get_Instance()->Add_Object(OBJ_PLAYERBULLET,CAbstractFactory<CPlayer_Bullet>::CreateBullet(m_tInfo.fX,m_tInfo.fY-30.f, PB_NORMAL));
	if (m_ePlayerShotState == PLAYER_UPGRADE) {

		CObject_Manager::Get_Instance()->Add_Object(OBJ_PLAYERBULLET, CAbstractFactory<CPlayer_Bullet>::CreateBullet(m_tInfo.fX - 10.f, m_tInfo.fY - 20.f, PB_LSUB));
		CObject_Manager::Get_Instance()->Add_Object(OBJ_PLAYERBULLET, CAbstractFactory<CPlayer_Bullet>::CreateBullet(m_tInfo.fX + 10.f, m_tInfo.fY - 20.f, PB_RSUB));

	}
	if (m_ePlayerShotState == PLAYER_FINAL) {
		CObject_Manager::Get_Instance()->Add_Object(OBJ_PLAYERBULLET, CAbstractFactory<CPlayer_Bullet>::CreateBullet(m_tInfo.fX - 10.f, m_tInfo.fY - 20.f, PB_LSUB));
		CObject_Manager::Get_Instance()->Add_Object(OBJ_PLAYERBULLET, CAbstractFactory<CPlayer_Bullet>::CreateBullet(m_tInfo.fX + 10.f, m_tInfo.fY - 20.f, PB_RSUB));
		CObject_Manager::Get_Instance()->Add_Object(OBJ_PLAYERBULLET, CAbstractFactory<CPlayer_Bullet>::CreateBullet(m_tInfo.fX + 22.f, m_tInfo.fY, PB_RSIDE));
		CObject_Manager::Get_Instance()->Add_Object(OBJ_PLAYERBULLET, CAbstractFactory<CPlayer_Bullet>::CreateBullet(m_tInfo.fX - 22.f, m_tInfo.fY, PB_LSIDE));
	}

}

void CPlayer::Motion_Change()
{
	
}
