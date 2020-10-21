#pragma once
#include"Action.h"
#include"../Figures/CFigure.h"

class p_shapes:public Action
{
private :
	int no_shapes[4];
	int SelShape;
	int RPick,WPick;
	

public:
	p_shapes(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
};

