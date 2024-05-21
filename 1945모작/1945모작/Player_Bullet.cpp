#include "pch.h"
#include "Player_Bullet.h"


CPlayer_Bullet::CPlayer_Bullet()
{
	
}

CPlayer_Bullet::~CPlayer_Bullet()
{
}

void CPlayer_Bullet::Initialize()
{

	m_fSpeed = 15.f;
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 25.f;


	switch (m_eBulletKind) {
	case PB_NORMAL:
		

		break;

	case PB_UPGRADE:
		break;

	case PB_LSIDE:
		break;

	case PB_RSIDE:
		break;

	default:
		break;

	}


}

int CPlayer_Bullet::Update()
{
	switch (m_eBulletKind) {
	case PB_NORMAL:
		m_tInfo.fY -= m_fSpeed;
		break;

	case PB_UPGRADE:
		break;

	case PB_LSIDE:
		break;

	case PB_RSIDE:
		break;

	default:
		break;

	}

	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CPlayer_Bullet::Late_Update()
{
}

void CPlayer_Bullet::Render(HDC hDC)
{
	Rectangle(hDC, m_tInfo.fX - m_tInfo.fCX / 2, m_tInfo.fY - m_tInfo.fCY / 2, m_tInfo.fX + m_tInfo.fCX / 2, m_tInfo.fY + m_tInfo.fCY / 2);

}

void CPlayer_Bullet::Release(void)
{
}

void CPlayer_Bullet::Motion_Change()
{
}

void CPlayer_Bullet::Move_Player_Frame()
{
}
