#pragma once
#include "GameObject.h"

class CUI : public CGameObject
{
public:
	CUI();
	virtual ~CUI();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	void Set_State(UISTATE eState);


private:
	int			m_iDrawID;
	bool		m_Choice;
	
	UISTATE		m_eUIState;
	DWORD		m_dwtime;
};

