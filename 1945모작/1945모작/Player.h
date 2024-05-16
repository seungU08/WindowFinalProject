#pragma once
#include "GameObject.h"

class CPlayer : public CGameObject
{
public:
	enum STATE { STATE_IDLE, STATE_LEFT, STATE_RIGHT, STATE_DASH, STATE_BACK, STATE_END };

public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	void	Key_Input();
	void	Shot();
	void	Motion_Change();
	void	Move_Player_Frame();


private:

	DWORD					m_dwShotDelay;
	const TCHAR*			m_pFrameKey;

	float					m_fMIN_X = 30.f;
	float					m_fMIN_Y = 30.f;
	
	float					m_fMAX_X = 580.f;
	float					m_fMAX_Y = 850.f;


	STATE					m_ePreState;
	STATE					m_eCurState;

	int						m_iLeftCnt = 0;
	int						m_iRightCnt = 0;
};

