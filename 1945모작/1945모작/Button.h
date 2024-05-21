#pragma once
#include "GameObject.h"

class CButton : public CGameObject
{
public:
	CButton();
	virtual ~CButton();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	int			m_iDrawID;
	bool		m_Choice;
	DWORD		dwtime;
};

