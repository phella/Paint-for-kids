#ifndef ADD_Circ_ACTION_H
#define ADD_Circ_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddCircAction: public Action
{
private:
	Point P1, P2; //circle Corners
	GfxInfo CircGfxInfo;
public:
	AddCircAction(ApplicationManager *pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();
	
	//Add circle to the ApplicationManager
	virtual void Execute() ;
	
};

#endif