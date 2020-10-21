#include "ChngCurrentColor.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CRectangle.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CFigure.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

chngcurrentclrAction::chngcurrentclrAction(ApplicationManager * pApp,color c):Action(pApp),currcolor(c)
{
	
	
}



void chngcurrentclrAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	
	pOut->ClearStatusBar();
	
	
}
//Execute the action

void chngcurrentclrAction::Execute() {
	Output* pOut = pManager->GetOutput();

	if(pOut->choice())
		{UI.FillColor=currcolor;}
	else
		{UI.DrawColor=currcolor ;

 }//This action needs to read some parameters first
	}
color chngcurrentclrAction::getcurrclr() const
{
	return currcolor; 
}
	


	

	
	
	
	
