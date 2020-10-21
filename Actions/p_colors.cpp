#include "p_colors.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include<time.h>

p_colors::p_colors (ApplicationManager* pApp):Action(pApp) 
{
	
}

void p_colors::ReadActionParameters()
{
	bool isfilled = false ;
	Rpick = 0; Wpick=0 ;
	pManager->SetClrs(no_Clr[0],no_Clr[1],no_Clr[2],no_Clr[3],no_Clr[4]);
	for(int i=0;i<5;i++)
	{if(no_Clr[i] != 0)
	{	isfilled=true;}
	}
	
	do
	{	srand( time( NULL ) );
	SelClr=rand()% 5;
	}while(no_Clr[SelClr]==0 && isfilled);
	switch(SelClr) 
	{case (0): c = BLUE; break;
   	case(1):  c = GREEN;break;
	case (2): c= RED;break;
	case (3): c = BLACK;break;
	case(4): c = WHITE;break;
	}
	}



void p_colors::Execute() 
{
	Point P1 ; 
		Input* pIn=pManager->GetInput() ;
		Output* pOut=pManager->GetOutput();
	pManager->UpdateInterface();
	ReadActionParameters();
	switch (SelClr) 
		    {  case(0):pOut->PrintMessage("select all blue figures, click to start"); break;
		       case(1):pOut->PrintMessage("select all green figures , click to start");break;
		       case(2):pOut->PrintMessage("select all red figures , click to start ");break;
		       case(3):pOut->PrintMessage("select all black figures , click to start");break;
			   case(4):pOut->PrintMessage("select all white figures , click to strat ");break;}
	CFigure* fig;
	color c1;
	while(no_Clr[SelClr]!=0) 
	{
	pIn->GetPointClicked(P1.x, P1.y);
	if(P1.y<70)
	{break;}
	fig=pManager->GetFigure(P1.x,P1.y);
	if(fig){
	if(fig->GetClr(c1)) 
	{if(c==c1)
	{Rpick++;
	pOut->PrintMessage("rigth pick "+ to_string(Rpick) + " ,wrong picks " +to_string(Wpick));
	no_Clr[SelClr]--;}
	else 
	{Wpick++;}
	}
	else {Wpick++;}
	 
	
	pOut->PrintMessage("rigth pick "+ to_string(Rpick) + " ,wrong picks " +to_string(Wpick));}
	pManager->setSelectedFig(fig);
	pManager->DeleteFigure(fig);
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
	}
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
	pOut->PrintMessage(" game ends , your rigth picks " + to_string(Rpick) + " ,wrong picks " + to_string(Wpick));
}
