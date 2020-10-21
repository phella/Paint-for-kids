#ifndef ADD_Tri_ACTION_H
#define ADD_Tri_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddTriAction: public Action
{
private:
	Point P1, P2,P3; //triangle Corners
	GfxInfo TriGfxInfo;
public:
	AddTriAction(ApplicationManager *pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();
	
	//Add circle to the ApplicationManager
	virtual void Execute() ;
	
};

#endif