#pragma once
#include "actions\action.h"
#include "Figures\CFigure.h"
#include "CopyAction.h"

class PasteAction :public Action
	
{
	CFigure*ptr;
	Point P1 ; 
	GfxInfo figGfxInfo ;
	CFigure* Clip;
	CFigure* selected;

public:
	PasteAction(ApplicationManager * pApp);

	virtual void ReadActionParameters() ;
	
	//Execute action (code depends on action type)
	virtual void Execute();


	~PasteAction(void);
};
