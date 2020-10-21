#ifndef ADD_Delete_ACTION_H
#define ADD_Delete_ACTION_H

#include "Action.h"
#include"..\Figures\CFigure.h"

//Add select Action class
class DeleteAction: public Action 
{
private:

	GfxInfo figGfxInfo ;
	 CFigure* selectedfigure ;
public:
	DeleteAction(ApplicationManager *pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();
	
	//Add circle to the ApplicationManager
	virtual void Execute() ;
	
};

#endif

