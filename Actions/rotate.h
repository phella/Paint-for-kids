#pragma once
#include"Action.h"
#include"../Figures/CFigure.h"
#include"../Figures/CLine.h"
#include"../ApplicationManager.h"
class rotatee:public Action
{
	Point p1,p2,p3,p4;
	CFigure* selectedfigure;
	GfxInfo gfxinfo;
	int type;
public:
	rotatee(ApplicationManager *pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();
	
	//Add circle to the ApplicationManager
	virtual void Execute() ;
};

