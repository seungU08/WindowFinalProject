#pragma once
#include "GameObject.h"

template<typename T>
class CAbstractFactory
{
public:
	CAbstractFactory() {}
	~CAbstractFactory() {}

public:
	static CGameObject* Create()
	{
		CGameObject* pGameObject = new T;
		pGameObject->Initialize();

		return pGameObject;
	}

	static CGameObject* Create(float fX, float fY)
	{
		CGameObject* pGameObject = new T;
		pGameObject->Set_Pos(fX, fY);
		pGameObject->Initialize();

		return pGameObject;
	}

	static CGameObject* Create(float fX, float fY, DIRECTION eDir)
	{
		CGameObject* pGameObject = new T;

		pGameObject->Set_Pos(fX, fY);
		pGameObject->Initialize();


		pGameObject->Set_Direction(eDir);
		return pGameObject;
	}


	static CGameObject* Create_UI(float fX, float fY, float fCX, float fCY,int Frames,DWORD FrameSpeed)
	{
		CGameObject* pGameObject = new T;
		pGameObject->Set_Pos(fX, fY);
		pGameObject->Set_Size(fCX, fCY);
		pGameObject->Set_Frame(Frames, FrameSpeed);
		pGameObject->Initialize();

		return pGameObject;
	}

	static CGameObject* Create_UI(float fX, float fY, float fCX, float fCY)
	{
		CGameObject* pGameObject = new T;
		pGameObject->Set_Pos(fX, fY);
		pGameObject->Set_Size(fCX, fCY);
		pGameObject->Initialize();

		return pGameObject;
	}

	static CGameObject* CreateBullet(float fX, float fY, PLAYER_BULLET eBullet)
	{
		CGameObject* pGameObject = new T;
		pGameObject->Set_Pos(fX, fY);
		dynamic_cast<CPlayer_Bullet*>(pGameObject)->Set_BulletKind(eBullet);
		pGameObject->Initialize();
	

		return pGameObject;
	}


	static CGameObject* Create(float fX, float fY, float fAngle)
	{
		CGameObject* pGameObject = new T;
		pGameObject->Initialize();
		pGameObject->Set_Pos(fX, fY);
		pGameObject->Set_Angle(fAngle);

		return pGameObject;
	}


};

