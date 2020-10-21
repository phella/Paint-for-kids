#include "CRectangle.h"
#include"CLine.h"
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	
	
	
}
void CRectangle::PrintInfo(Output* pOut){
		
			std::string id=std::to_string(ID);
		
		pOut->PrintMessage("You selected a rectangle which id = "+id   );
	
};


void CRectangle::Draw(Output* pOut) const
{
	
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
int CRectangle:: minimum(int p1,int p2){
	if (p1>p2) return p2 ;
	else return p1 ;
}
int CRectangle::maximum(int p1,int p2){
	if(p1>p2) return p1;
	else return p2 ;

}

bool CRectangle:: check(int x,int y){
if((minimum(Corner1.x,Corner2.x) <= x) && (maximum(Corner2.x,Corner1.x)>=x) && (minimum(Corner1.y,Corner2.y) <=y) && (maximum(Corner2.y,Corner1.y)>=y))
	return true; 

return false ;

}


CFigure* CRectangle::TransferFigure(Point p)
{
	CRectangle* addnewrectangle=new CRectangle(Corner1, Corner2, FigGfxInfo);
	

	Point cen;
	
	cen.x=(Corner1.x+Corner2.x)/2;
	cen.y=(Corner1.y+Corner2.y)/2;
	addnewrectangle->Corner1.x=p.x-cen.x+Corner1.x;
	addnewrectangle->Corner1.y=p.y-cen.y+Corner1.y;
	addnewrectangle->Corner2.x=p.x-cen.x+Corner2.x;
	addnewrectangle->Corner2.y=p.y-cen.y+Corner2.y;


	return addnewrectangle;

}

CFigure* CRectangle::copy()
{
	CRectangle* addnewrectangle=new CRectangle(Corner1, Corner2, FigGfxInfo);
return addnewrectangle;
}


void CRectangle::save(ofstream &savefile) {
	
	
	savefile << "rect  ";
	savefile << getID() << "  ";
	savefile << Corner1.x << " " << Corner1.y << "  ";
	savefile << Corner2.x << " " << Corner2.y << "  ";
	savedrawing(savefile);
	savefilling(savefile);
}
void CRectangle::Load(ifstream &loadfile) {
	bool x;
	loadfile >> ID;
	loadfile >> Corner1.x >> Corner1.y;
	loadfile >> Corner2.x >> Corner2.y;	
	loaddrawing(loadfile);
	loadfilling(loadfile);	
}

int CRectangle::gettype()
{return 1;}

void CRectangle::rotate(Point& point3,Point& p1,Point& p2,GfxInfo& g3) 
{
	CLine *l=new CLine(Corner1,Corner2,FigGfxInfo);
	l->rotate(Corner2,Corner1,p2,g3);
	point3=Corner1;
	p1=Corner2;
}