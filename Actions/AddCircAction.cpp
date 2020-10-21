#include "AddCircAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager * pApp):Action(pApp)
{}

void AddCircAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at first point");
	
	//Read 1st corner and store in point P1
	do{pIn->GetPointClicked(P1.x, P1.y);}
	while(P1.y<70);

	pOut->PrintMessage("New Circle: Click at second pont");

	//Read 2nd corner and store in point P2
do{pIn->GetPointClicked(P2.x, P2.y);}
	while(P1.y<70);
	CircGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	CircGfxInfo.isFilled=pOut->getFilled();
	pOut->ClearStatusBar();

}

//Execute the action
void AddCircAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CCircle *R=new CCircle(P1, P2, CircGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
