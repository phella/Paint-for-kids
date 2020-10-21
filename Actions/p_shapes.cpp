#include "p_shapes.h"
#include<time.h>
#include "../ApplicationManager.h"
#include"../Figures/CCircle.h"
#include "../Figures/CFigure.h"
#include "../Figures/CLine.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CTriangle.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
p_shapes::p_shapes(ApplicationManager * pApp):Action(pApp)
{}

void p_shapes::ReadActionParameters() 
{ 
	bool isdrawen = false ;
	RPick=0; WPick=0;
	pManager->SetShapes(no_shapes[0],no_shapes[1],no_shapes[2],no_shapes[3]);
	for(int i=0;i<4;i++)
	{
		if(no_shapes[i] != 0)
      	{isdrawen=true;} 
	}	
	
	do
	{	srand( time( NULL ) );
	SelShape=rand()% 4;
	}	while(no_shapes[SelShape]==0 && isdrawen);
	
}

void p_shapes::Execute() 
{       Point P1 ; 
		Input* pIn=pManager->GetInput() ;
		Output* pOut=pManager->GetOutput();
		CFigure* fig;
		pManager->UpdateInterface();
	    ReadActionParameters();
			switch (SelShape) 
		    {  case(0):pOut->PrintMessage("select all circles , click to start"); break;
		       case(1):pOut->PrintMessage("select all rectangles , click to start");break;
		       case(2):pOut->PrintMessage("select all lines , click to start ");break;
		       case(3):pOut->PrintMessage("select all triangles , click to start");break;}
			
	while(no_shapes[SelShape]!=0)
	{ 	
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
		pIn->GetPointClicked(P1.x, P1.y);
		if(P1.y<70)
		{break;}
		fig=pManager->GetFigure(P1.x,P1.y);
		if(fig)
			{
				if(SelShape==fig->gettype())
				{
				RPick++;
			    no_shapes[SelShape]--;
				}
				else
				{
				WPick++;
				}
	pManager->setSelectedFig(fig);
	pManager->DeleteFigure(fig);
	pOut->PrintMessage("rigth pick "+ to_string(RPick) + " ,wrong picks " +to_string(WPick));
		}
	}
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
	pOut->PrintMessage(" game ends , your rigth picks " + to_string(RPick) + " ,wrong picks " + to_string(WPick));
}

