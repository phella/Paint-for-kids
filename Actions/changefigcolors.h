#ifndef ChngfigClr_ACTION_H
#define ChngfigClr_ACTION_H

#include "Action.h"
#include"..\Figures\CFigure.h"

//Add select Action class
class changefigcolors: public Action 
{
private:

	CFigure* selectedfigure ;
	color currcolor;
	GfxInfo figGfxInfo ;
	
public:
	changefigcolors(ApplicationManager *pAp,color c);

	//Reads circle parameters
	virtual void ReadActionParameters();
	
	//Add circle to the ApplicationManager
	virtual void Execute() ;
	
};
#endif