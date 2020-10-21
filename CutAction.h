#pragma once
#include "actions\action.h"
#include "Figures\CFigure.h"

class CutAction :
	public Action
{
	Point P1 ; 
	GfxInfo figGfxInfo ;
	CFigure* selected;


public:

	CutAction(ApplicationManager * pApp);

	virtual void ReadActionParameters();
	virtual void Execute();
	~CutAction();
};
