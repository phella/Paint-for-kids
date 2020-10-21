#pragma once
#include "actions\action.h"
#include "Figures\CFigure.h"

class CopyAction :
	public Action
{
	Point P1 ; 
	GfxInfo figGfxInfo ;
	CFigure* selected;
	

public:

	CopyAction(ApplicationManager * pApp);

	virtual void ReadActionParameters();
	virtual void Execute();
	~CopyAction();
};