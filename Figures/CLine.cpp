#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	point1 = P1;
	point2 = P2;
	
	FigureGfxInfo.length=pow(abs(point1.x-point2.x)+abs(point1.y+point2.y),2);
}
	

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->Drawline(point1, point2, FigGfxInfo, Selected);
}
void CLine::PrintInfo(Output* pOut) {
	int length= sqrt (pow(point1.x-point2.x,2)+pow(point1.y-point2.y,2) );
	std::string ln =std::to_string(length);
			std::string id=std::to_string(ID);
		
		pOut->PrintMessage("You selected a line which id = "+id +"and its length = "+ln);

};
int CLine::minn(int p1,int p2){
	if (p1>p2) return p2 ;
	else return p1 ;
}
int CLine::maxx(int p1,int p2){
	if(p1>p2) return p1;
	else return p2 ;

}

bool CLine:: check(int x,int y){
if((minn(point1.x,point2.x) <= x) && (maxx(point2.x,point1.x)>=x) && (minn(point1.y,point2.y) <=y) && (maxx(point2.y,point1.y)>=y))
	return true; 

return false ;

}


CFigure* CLine::TransferFigure(Point p)
{
	
	CLine* addnewline=new CLine(point1,point2, FigGfxInfo);

	Point cen;
	
	cen.x=(point1.x+point2.x)/2;
	cen.y=(point1.y+point2.y)/2;
	addnewline->point1.x=p.x-cen.x+point1.x;
	addnewline->point1.y=p.y-cen.y+point1.y;
	addnewline->point2.x=p.x-cen.x+point2.x;
	addnewline->point2.y=p.y-cen.y+point2.y;


	return addnewline;

}
CFigure* CLine::copy()
{
	CLine* addnewline=new CLine(point1,point2, FigGfxInfo);
	return addnewline;

}


void CLine::save(ofstream &savefile) {
	savefile << "line  ";
	savefile << getID() << "  ";
	savefile << point1.x << " " << point1.y << "  ";
	savefile << point2.x << " " << point2.y << "  ";
	savedrawing(savefile);
}
void CLine::Load(ifstream &loadfile) {
	loadfile >> ID;
	loadfile >>point1.x >> point1.y ;
	loadfile >> point2.x >> point2.y;
		FigGfxInfo.isFilled=false;
	loaddrawing(loadfile);
}
void CLine::rotate(Point& point3,Point& p1,Point& point4,GfxInfo& gfx ) 
{
	p1=point1;
	gfx=FigGfxInfo;
	point2.x-=point1.x;
	point2.y-=point1.y;
	if(point2.x>0 && point2.y>0) 
	{
		point3.y=-point2.x+point1.y;
		point3.x=point2.y+point1.x;
	}
	else if(point2.x>0 && point2.y<0) 
	{
		point3.y=-point2.x+point1.y;
		point3.x=point2.y+point1.x;
	}
	else if(point2.x<0 && point2.y<0)
	{
		point3.y=-point2.x+point1.y;
		point3.x=point2.y+point1.x;
	}
	else if(point2.x<0&&point2.y>0)
	{
		point3.y=-point2.x+point1.y;
		point3.x=point2.y+point1.x;
	}
}

int CLine::gettype()
{return 2;}