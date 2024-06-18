#include "pch.h"
#include "Enemy_1.h"
#include "Bmp_Manager.h"
#include "Object_Manager.h"
#include "AbstractFactory.h"
#include "Enemy_Bullet.h"

default_random_engine dre;
uniform_int_distribution<int> uid_x{ 1, 600 };

CEnemy_1::CEnemy_1()
{
}

CEnemy_1::~CEnemy_1()
{
	Release();
}

void CEnemy_1::Initialize()
{

	CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Enemy/Enemy_1(57X64X11ea).bmp", L"ENEMY_1_IMAGE");
	CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Bullet/EnemyBullet/Enemy_Bullet_1.bmp", L"E1_IMAGE");
	CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Bullet/EnemyBullet/Enemy_Bullet_2.bmp", L"E2_IMAGE");

	m_pFrameKey = L"ENEMY_1_IMAGE";
	m_tInfo.fCX = 57.f;
	m_tInfo.fCY = 64.f;
	m_fSpeed = 4.f;
	m_fSpeed_Y = -4.f;
	m_iFrameCnt = 5;
	m_dwShotCount = GetTickCount64();
	m_dwShotDelay = 1500;

}

int CEnemy_1::Update()
{
	
	if (m_tInfo.fX > m_fMAX_X) {
		m_fSpeed = -4.f;
		m_fSpeed_Y = -4.f;
	}
	else if (m_tInfo.fX < m_fMIN_X) {
		m_fSpeed = 4.f;
		m_fSpeed_Y = -4.f;
	}

	if (m_tInfo.fY < 0) {
		m_fSpeed_Y = 4.f;
	}
	m_tInfo.fX += m_fSpeed;
	m_tInfo.fY += m_fSpeed_Y;
	m_iFrameCnt = (m_iFrameCnt + 1) % 11;
	if (GetTickCount64() - m_dwShotCount > m_dwShotDelay) {
		Shot();
		m_dwShotCount = GetTickCount64();

	}
	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CEnemy_1::Late_Update()
{
	__super::Move_Frame();
}

void CEnemy_1::Render(HDC hDC)
{
	HDC EnemyDC = CBmp_Manager::Get_Instance()->Find_Img(m_pFrameKey);

	//Rectangle(hDC, m_tInfo.fX - m_tInfo.fCX / 2, m_tInfo.fY - m_tInfo.fCY / 2, m_tInfo.fX + m_tInfo.fCX / 2, m_tInfo.fY + m_tInfo.fCY / 2);
	//�ǰ� ������ Rect => ���� �ʿ�

	GdiTransparentBlt(hDC,
		(int)m_tInfo.fX - m_tInfo.fCX / 2,	//���� ���� X ��ġ
		(int)m_tInfo.fY - m_tInfo.fCY / 2,	//���� ���� Y ��ġ
		57,									//���� ���� ���� ����
		64,									//���� ���� ���� ����
		EnemyDC,							//������ ��Ʈ�� DC
		57 * m_iFrameCnt,					//��Ʈ�� �̹����� ���� X ��ǥ
		0,									//��Ʈ�� �̹����� ���� Y ��ǥ
		m_tInfo.fCX,						//������ �̹����� ���� ������
		m_tInfo.fCY,						//������ �̹����� ���� ������
		RGB(255, 255, 255));

}

void CEnemy_1::Release(void)
{
}


void CEnemy_1::Shot()
{
	CObject_Manager::Get_Instance()->Add_Object(OBJ_ENEMY_BULLET, CAbstractFactory<CEnemy_Bullet>::ECreateBullet(m_tInfo.fX, m_tInfo.fY - 30.f, E1));
	
}

void CEnemy_1::Motion_Change()
{

}
