#pragma once
#define WINCX 600
#define WINCY 900

#define PURE	= 0
#define PI		3.14f
#define VK_MAX	0xff

#define		OBJ_NOEVENT			0
#define		OBJ_DEAD			1

enum DIRECTION { DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN, DIR_LU, DIR_RU, DIR_LD, DIR_RD, DIR_END };
enum OBJ_ID { OBJ_PLAYER,OBJ_PLAYERBULLET, OBJ_ENEMY_1, OBJ_ENEMY_2, OBJ_ENEMY_BULLET, OBJ_BOSS, OBJ_BUTTON ,OBJ_UI ,OBJ_END };
enum LEVEL_ID { LEVEL_LOGO, LEVEL_MENU, LEVEL_GAMEPLAY, LEVEL_END };
enum PLAYER_BULLET { PB_NORMAL, PB_LSUB, PB_RSUB, PB_LSIDE, PB_RSIDE, PB_END };
enum ENEMY_BULLET {E1, E2R,E2L, E3};
enum UISTATE { UI_ANIM, UI_NONANIM, UI_SCORE,UI_LIFE ,UI_END };

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

typedef struct tagInfo
{
	float	fX;		// ���� X
	float	fY;		// ���� Y
	float	fCX;	// ���� ������
	float	fCY;	// ���� ������

}INFO;

typedef struct tagFrame
{
	int		iFrameStart;
	int		iFrameEnd;
	int		iMotion;
	DWORD	dwSpeed;
	DWORD	dwTime;

}FRAME;

class CDeleteObj
{
public:
	template<typename T>
	void operator()(T& Temp)
	{
		if (Temp)
		{
			delete Temp;
			Temp = nullptr;
		}
	}
};

class CDeleteMap
{
public:
	template<typename T>
	void operator()(T& MyPair)
	{
		if (MyPair.second)
		{
			delete MyPair.second;
			MyPair.second = nullptr;
		}
	}
};


class CTagFinder
{
public:
	CTagFinder(const TCHAR* pKey) : m_pKey(pKey) {}

public:
	template<typename T>
	bool	operator()(T& Pair)
	{
		if (!lstrcmp(m_pKey, Pair.first))
			return true;

		return false;
	}

private:
	const TCHAR* m_pKey;
};



extern HWND g_hWnd;