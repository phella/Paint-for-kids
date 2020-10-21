#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }


bool CFigure::IsSelected() const
{	return Selected; }


void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
void CFigure::setID(int id) {
	ID = id+1;

}
int CFigure::getID() {
	return ID ;
}

bool CFigure::GetClr(color& c) 
{      if(FigGfxInfo.isFilled)
    {    
		c = (FigGfxInfo.FillClr);
        return true;
    }
return false ;
}
void CFigure ::savefilling(ofstream &savefile){
	string fillingcolor;
	if (FigGfxInfo.isFilled)
	{
		
		if ((int)FigGfxInfo.FillClr.ucRed == 0 && FigGfxInfo.FillClr.ucGreen == 0 && (int)FigGfxInfo.FillClr.ucBlue == 255)
			fillingcolor = "blue";
		else if ((int)FigGfxInfo.FillClr.ucRed == 0 && FigGfxInfo.FillClr.ucGreen == 0 && (int)FigGfxInfo.FillClr.ucBlue == 0)
			fillingcolor = "black";
		else if ((int)FigGfxInfo.FillClr.ucRed == 255 && FigGfxInfo.FillClr.ucGreen == 255 && (int)FigGfxInfo.FillClr.ucBlue == 255)
			fillingcolor = "white";
		else if ((int)FigGfxInfo.FillClr.ucRed == 0 && FigGfxInfo.FillClr.ucGreen == 255 && (int)FigGfxInfo.FillClr.ucBlue == 0)
			fillingcolor = "green";
		else if ((int)FigGfxInfo.FillClr.ucRed == 255 && FigGfxInfo.FillClr.ucGreen == 0 && (int)FigGfxInfo.FillClr.ucBlue == 0)
			fillingcolor = "red";
		savefile << fillingcolor << endl;
	}
	
	else { savefile << "NO_FILL" << endl; }
}



void CFigure ::savedrawing(ofstream &savefile){
	string drawingcolor;
	if ((int)FigGfxInfo.DrawClr.ucRed == 0 && FigGfxInfo.DrawClr.ucGreen == 0 && (int)FigGfxInfo.DrawClr.ucBlue == 255)
		drawingcolor = "blue";
	else if ((int)FigGfxInfo.DrawClr.ucRed == 0 && FigGfxInfo.DrawClr.ucGreen == 0 && (int)FigGfxInfo.DrawClr.ucBlue == 0)
		drawingcolor = "black";
	else if ((int)FigGfxInfo.DrawClr.ucRed == 255 && FigGfxInfo.DrawClr.ucGreen == 255 && (int)FigGfxInfo.DrawClr.ucBlue == 255)
		drawingcolor = "white";
	else if ((int)FigGfxInfo.DrawClr.ucRed == 0 && FigGfxInfo.DrawClr.ucGreen == 255 && (int)FigGfxInfo.DrawClr.ucBlue == 0)
		drawingcolor = "green";
	else if ((int)FigGfxInfo.DrawClr.ucRed == 255 && FigGfxInfo.DrawClr.ucGreen == 0 && (int)FigGfxInfo.DrawClr.ucBlue == 0)
		drawingcolor = "red";
	savefile << drawingcolor << "  ";
}
void CFigure::loadfilling(ifstream &loadfile){
	string fillingcolor;
	loadfile >> fillingcolor;
	if (fillingcolor == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else {
		FigGfxInfo.isFilled = true;
		if (fillingcolor == "blue")
			FigGfxInfo.FillClr = BLUE;
		else if (fillingcolor == "black")
			FigGfxInfo.FillClr = BLACK;
		else if (fillingcolor =="white")
			FigGfxInfo.FillClr = WHITE;
		else if (fillingcolor =="green")
			FigGfxInfo.FillClr = GREEN;
		else if (fillingcolor =="red")
			FigGfxInfo.FillClr = RED;
	}


}
void CFigure::loaddrawing(ifstream &loadfile){
string drawingcolor;
	loadfile >> drawingcolor;
	if (drawingcolor == "blue")
		FigGfxInfo.DrawClr = BLUE;
	else if (drawingcolor == "black")
		FigGfxInfo.DrawClr = BLACK;
	else if (drawingcolor =="white")
		FigGfxInfo.DrawClr = WHITE;
	else if (drawingcolor =="green")
		FigGfxInfo.DrawClr = GREEN;
	else if (drawingcolor =="red")
		FigGfxInfo.DrawClr = RED;
}




void CFigure::getcount(int seltype,int&count,color selcolor) 
{bool filled;color tempcolor;int temptype;
filled=this->GetClr(tempcolor);
temptype=gettype();
if(temptype==seltype&&filled&&tempcolor==selcolor)
{count++;}
}

