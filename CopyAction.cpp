#include "CopyAction.h"


#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

CopyAction::CopyAction(ApplicationManager * pApp):Action(pApp)
{
	selected=NULL;
}


void CopyAction::ReadActionParameters()
{

	
	Input* pIn = pManager->GetInput();
Output* pOut = pManager->GetOutput();

selected=pManager->getSelectedFig();

	pOut->ClearStatusBar();
	
}


void CopyAction::Execute() {


ReadActionParameters();
Output* pOut = pManager->GetOutput();



if(selected==NULL)
{
	pOut->PrintMessage("select a figure first");
}

else if (selected->IsSelected())

{
pManager->ClearClipboard();

CFigure* ptr=selected->copy();

pManager->setClipboard(ptr);

selected->SetSelected(false);
pOut->PrintMessage("copied");
pManager->setSelectedFig(NULL);
}

  
};


/*
CopyAction::~CopyAction()
{
	
}
*/
