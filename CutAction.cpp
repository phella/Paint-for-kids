#include "CutAction.h"
#include "ApplicationManager.h"

CutAction::CutAction(ApplicationManager * pApp):Action(pApp)
{
	selected=NULL;
}

void CutAction::ReadActionParameters()
{

	
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
selected=pManager->getSelectedFig();

	pOut->ClearStatusBar();
	
}

/*

CutAction::~CutAction()
{
}
*/

void CutAction::Execute() {


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
pOut->ClearDrawArea();
selected->SetSelected(false);

pManager->DeleteFigure(selected);

pOut->PrintMessage("CUT");
}

  
};
  
