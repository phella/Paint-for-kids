#pragma once
#include"Action.h"
#include"../Figures/CFigure.h"
class p_CS:public Action
{
private : 
	int count,type,RPick,WPick;
	color SelClr;
public:
		p_CS(ApplicationManager *pApp);
		void ReadActionParameters();
	    void Execute();

};

