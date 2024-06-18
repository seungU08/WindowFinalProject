#pragma once
#include "Level.h"
class CLevel_GamePlay : public CLevel
{
public:
	CLevel_GamePlay();
	virtual ~CLevel_GamePlay();

public:

	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	int m_iMap_Update = 0;
	int m_iScore;

	DWORD					Enemy1_Delay;
	DWORD					Enemy2_Delay;
	DWORD					Enemy_Count;
};

