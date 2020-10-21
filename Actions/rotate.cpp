#include "rotate.h"
#include"../GUI/Output.h"
rotatee::rotatee(ApplicationManager* pApp):Action(pApp) 
{
	selectedfigure=pApp->getSelectedFig();
}

void rotatee::ReadActionParameters() 
{
	if(selectedfigure)
	{
		selectedfigure->rotate(p2,p1,p3,gfxinfo);
	    type=selectedfigure->gettype();
	}
}

void rotatee::Execute() 
{
	CLine* l;
	CTriangle*t;
	CRectangle*rect;
	ReadActionParameters();
	
	Output* Pout=pManager->GetOutput();
	Pout->ClearDrawArea();
	switch(type)
	{
	case(0):
		selectedfigure->SetSelected(false);
		pManager->setSelectedFig(NULL);
		break;
	case(1):
		rect= new CRectangle(p1,p2,gfxinfo);
		pManager->AddFigure(rect);
		pManager->DeleteFigure(selectedfigure);
		break;
	case (2):
		 l=new CLine(p1,p2,gfxinfo);
		pManager->AddFigure(l);
		pManager->DeleteFigure(selectedfigure);
		break;
	case(3):
		t=new CTriangle(p2,p3,p1,gfxinfo);
		pManager->AddFigure(t);
		pManager->DeleteFigure(selectedfigure);
		break;
	}
	Pout->ClearStatusBar();
}