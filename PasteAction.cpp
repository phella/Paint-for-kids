#include "PasteAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "CopyAction.h"

PasteAction::PasteAction(ApplicationManager * pApp):Action(pApp)
{
selected=NULL;
}


void PasteAction::ReadActionParameters()
{

	
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pIn->GetPointClicked(P1.x, P1.y);

	pOut->ClearStatusBar();
	selected=pManager->getSelectedFig();
    
}

void PasteAction::Execute()
{
	
Output* pOut = pManager->GetOutput();
Input* pIn = pManager->GetInput();
ReadActionParameters();
Clip=pManager->getClipboard();

if(Clip==NULL)
{

pOut->PrintMessage("please cut or copy a figure");
}

else
{

 ptr= Clip->TransferFigure(P1);
 pManager->AddFigure(ptr);
pOut->PrintMessage("FIgure is PASTED");

}
	
}
/*
PasteAction::~PasteAction(void)
{
}
*/