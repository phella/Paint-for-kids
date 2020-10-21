#include "changefigcolors.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CRectangle.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CFigure.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

changefigcolors::changefigcolors(ApplicationManager * pApp,color c):Action(pApp),currcolor(c)
{
	selectedfigure=NULL;
	
}

void changefigcolors::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	
	selectedfigure=pManager->getSelectedFig();
	pOut->ClearStatusBar();
	
	
	
}
//Execute the action

void changefigcolors::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	

	if (selectedfigure!=NULL){
		if(selectedfigure->IsSelected()){
			if(pOut->choice()){ 
				selectedfigure->ChngFillClr(currcolor);
				selectedfigure->SetSelected(false);
				pManager->setSelectedFig(NULL);
			}else{
         	selectedfigure->ChngDrawClr(currcolor);
		    selectedfigure->SetSelected(false);
			pManager->setSelectedFig(NULL);
		         }  
		}
	}
}


	


	

	

	
	
	
	
