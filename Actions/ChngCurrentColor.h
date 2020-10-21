

#ifndef ChngDrawClr_ACTION_H
#define ChngDrawClr_ACTION_H

#include "Action.h"
#include"..\Figures\CFigure.h"

//Add select Action class
class chngcurrentclrAction: public Action 
{
private:
	const color currcolor ;
	CFigure * cfig ;
	
public:
	chngcurrentclrAction(ApplicationManager *pAp,color c);
	chngcurrentclrAction();
	//Reads circle parameters
	virtual void ReadActionParameters();
	
	//Add circle to the ApplicationManager
	virtual void Execute() ;
	color getcurrclr()const;
};
#endif