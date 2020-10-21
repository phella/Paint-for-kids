#include "AddTriAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriAction::AddTriAction(ApplicationManager * pApp):Action(pApp)
{}

void AddTriAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New triangle: Click at first point");
	
	//Read 1st corner and store in point P1
	do{pIn->GetPointClicked(P1.x, P1.y);}
	while(P1.y<70);

	pOut->PrintMessage("New triangle: Click at second point");

	//Read 2nd corner and store in point P2
do{pIn->GetPointClicked(P2.x, P2.y);}
	while(P2.y<70);
	pOut->PrintMessage("New triangle: Click at third point");
	do{pIn->GetPointClicked(P3.x, P3.y);}
	while(P3.y<70);

	TriGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();
	TriGfxInfo.isFilled=pOut->getFilled();
	pOut->ClearStatusBar();

}

//Execute the action
void AddTriAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CTriangle *R=new CTriangle(P1, P2,P3, TriGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}