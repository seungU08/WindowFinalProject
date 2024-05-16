#pragma once
#include "Level.h"

class CLevel_Logo : public CLevel
{
public:
	CLevel_Logo();
	virtual ~CLevel_Logo();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

};

