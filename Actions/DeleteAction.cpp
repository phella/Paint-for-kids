#include "DeleteAction.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CRectangle.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CFigure.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager * pApp):Action(pApp)
{
	selectedfigure=NULL ;
	
}

void DeleteAction::ReadActionParameters() 
{	
		Output* pOut = pManager->GetOutput();
		figGfxInfo.DrawClr = pOut->getCrntDrawColor();
	figGfxInfo.FillClr = pOut->getCrntFillColor();
	selectedfigure=pManager->getSelectedFig();
}

//Execute the action

void DeleteAction::Execute() {
	ReadActionParameters();
	
	Output* pOut = pManager->GetOutput();
	
	//This action needs to read some parameters first

	if (selectedfigure!=NULL)
	{
		   if(selectedfigure->IsSelected())
		   {
	       pOut->ClearDrawArea();
	       pManager->DeleteFigure(selectedfigure);	
	       }
	}
	else 
	{
	pOut->PrintMessage("select figure first :) ");
	}	
}
		
	
	
	

	
	
		
	