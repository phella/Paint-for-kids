#include "p_CS.h"
#include"../ApplicationManager.h"
#include"../Figures/CLine.h"
#include"../Figures/CCircle.h"
#include"../Figures/CRectangle.h"
#include"../Figures/CTriangle.h"
p_CS::p_CS(ApplicationManager * pApp):Action(pApp)
{}

void p_CS::ReadActionParameters() 
{
	pManager->randfig(type,SelClr,count);
	RPick=0;
    WPick=0 ;
}

void p_CS::Execute() 
{
	 Point P1 ; string s1;
		Input* pIn=pManager->GetInput() ;
		Output* pOut=pManager->GetOutput();
		CFigure* fig;
		color temp;
		pManager->UpdateInterface();
		ReadActionParameters();
		switch(type)
		{
		case (0) : s1 = "circles";break ;
		case(1): s1 =" rectangles";break;
		case(2): s1= "lines";break;
		case(3) :s1= "triangles";break;
		}
		if(SelClr==RED)
		{pOut->PrintMessage("pick all red "+s1);}
		else if(SelClr==GREEN) 
		{pOut->PrintMessage("pick all green "+s1);}
		else if(SelClr==WHITE)
		{pOut->PrintMessage("pick all white "+s1);}
		else if(SelClr==BLACK) 
		{pOut->PrintMessage("pick all black "+s1);}
		else if (SelClr==BLUE) 
		{pOut->PrintMessage("pick all blue "+s1);}
		
		while(count!=0)
		{
		pIn->GetPointClicked(P1.x, P1.y);
		if(P1.y<70)
		{break;}
		fig=pManager->GetFigure(P1.x,P1.y);
		if(fig) 
		{
			temp=PURPLE;
			fig->GetClr(temp);
			if(fig->gettype()==type&&temp==SelClr)
			{
				 RPick++ ;
				  count--;
			}
			else
			{
				WPick++;
			}
			pManager->setSelectedFig(fig);
			pManager->DeleteFigure(fig);
			pOut->ClearDrawArea();
          	pManager->UpdateInterface();
			pOut->PrintMessage("rigth pick "+ to_string(RPick) + " ,wrong picks " +to_string(WPick));
		}}
			pOut->ClearDrawArea();
        	pManager->UpdateInterface();
			pOut->PrintMessage(" game ends , your rigth picks " + to_string(RPick) + " ,wrong picks " + to_string(WPick));
}
