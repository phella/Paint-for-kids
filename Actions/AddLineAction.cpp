#include "AddLineAction.h"
#include "..\Figures\CLine.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager * pApp):Action(pApp)
{}

void AddLineAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New LINE: Click at first point");
	
	//Read 1st corner and store in point P1
do{pIn->GetPointClicked(P1.x, P1.y);}
	while(P1.y<70);
	pOut->PrintMessage("New LINE: Click at second point");

	//Read 2nd corner and store in point P2
do{pIn->GetPointClicked(P2.x, P2.y);}
	while(P2.y<70);
	LineGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();
	
	pOut->ClearStatusBar();

}

//Execute the action
void AddLineAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CLine *R=new CLine(P1, P2, LineGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}