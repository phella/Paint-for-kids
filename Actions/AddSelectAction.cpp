#include "AddSelectAction.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CRectangle.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CFigure.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSelectAction::AddSelectAction(ApplicationManager * pApp):Action(pApp)
{
	selectedfigure=pManager->getSelectedFig();
}

void AddSelectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();	
	
	pIn->GetPointClicked(P1.x, P1.y);
	fig=pManager->GetFigure(P1.x,P1.y)	;
		//default is not filled
	//get drawing, filling colors and pen width from the interface
	
	figGfxInfo.DrawClr = pOut->getCrntDrawColor();
	figGfxInfo.FillClr = pOut->getCrntFillColor();
	pOut->ClearStatusBar();
}

void AddSelectAction::Execute() 
{
		ReadActionParameters();
	if(fig)
	{
		if(selectedfigure )
		{selectedfigure->SetSelected(false);}
		if(fig!=selectedfigure)
		{
		selectedfigure=fig;
		selectedfigure->SetSelected(true);
		pManager->setSelectedFig(selectedfigure);
		Output* pOut = pManager->GetOutput();
	    selectedfigure->PrintInfo(pOut);
		}
		else
		{
		selectedfigure->SetSelected(false );
		selectedfigure=NULL;
		pManager->setSelectedFig(selectedfigure);
		}
		
	}
}