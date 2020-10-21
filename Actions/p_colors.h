#pragma once
#include "Action.h"

class p_colors:public Action
{
private : 
	int no_Clr[5];
	int SelClr ;
	int Rpick,Wpick ;
	color c ;
	public:
	p_colors(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();

};

