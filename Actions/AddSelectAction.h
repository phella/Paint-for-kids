

#ifndef ADD_Select_ACTION_H
#define ADD_Select_ACTION_H

#include "Action.h"
#include"..\Figures\CFigure.h"

//Add select Action class
class AddSelectAction: public Action 
{
private:
	Point P1 ; 
	GfxInfo figGfxInfo ;
	 CFigure* selectedfigure ;
	 CFigure* fig;
public:
	AddSelectAction(ApplicationManager *pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();
	
	//Add circle to the ApplicationManager
	virtual void Execute() ;
	
};

#endif





