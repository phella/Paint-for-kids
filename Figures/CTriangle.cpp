#include "CTriangle.h"
#include"CLine.h"
CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	p1 = P1;
	p2 = P2;
	p3=P3;
	
}

void CTriangle::PrintInfo(Output* pOut) {
	float area = CTriangle::area(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);
	std::string are=std::to_string(area);
				std::string id=std::to_string(ID);
		
		pOut->PrintMessage("You selected a triangle which id = "+id +" and its area = "+are   );

};
void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTriangle(p1, p2,p3, FigGfxInfo, Selected);
}



float CTriangle::area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return (abs(x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}



bool CTriangle:: check(int x,int y){
	float A = area (p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
 
 
   float A1 = area (x, y, p2.x, p2.y, p3.x, p3.y);
 
   
   float A2 = area (p1.x, p1.y, x, y, p3.x,p3. y);
 
   
   float A3 = area (p1.x, p1.y, p2.x, p2.y, x, y);
   
 
   return (A == A1 + A2 + A3);

} 


CFigure* CTriangle::TransferFigure(Point p)
{
		CTriangle* addnewtriangle=new CTriangle(p1,p2,p3, FigGfxInfo);
Point cen;
	
	cen.x=(p1.x+p2.x+p3.x)/3;
	cen.y=(p1.y+p2.y+p3.y)/3;

	addnewtriangle->p1.x=p.x-cen.x+p1.x;
	addnewtriangle->p1.y=p.y-cen.y+p1.y;
	addnewtriangle->p2.x=p.x-cen.x+p2.x;
	addnewtriangle->p2.y=p.y-cen.y+p2.y;
	addnewtriangle->p3.x=p.x-cen.x+p3.x;
	addnewtriangle->p3.y=p.y-cen.y+p3.y;

	return addnewtriangle;


}

CFigure* CTriangle::copy()
{
	CTriangle* addnewtriangle=new CTriangle(p1,p2,p3, FigGfxInfo);

return addnewtriangle;


}





void  CTriangle::save(ofstream &savefile) {
	savefile << "triangle  ";
	savefile << getID() << "  ";
	savefile << p1.x << " " << p1.y << "  ";
	savefile << p2.x << " " << p2.y << "  ";
	savefile << p3.x << " " << p3.y << "  ";
	savedrawing(savefile);
	savefilling(savefile);
}
void CTriangle::Load(ifstream &loadfile) {
	bool x;
	loadfile >> ID;
	loadfile >> p1.x >> p1.y;
	loadfile >> p2.x >> p2.y;
	loadfile >> p3.x >> p3.y;
	loaddrawing(loadfile);
	loadfilling(loadfile);
}

void CTriangle::rotate(Point& point3,Point& point2,Point& point1,GfxInfo& g3) 
{
	CLine *l=new CLine(p1,p2,FigGfxInfo);
	l->rotate(p2,p1,point1,g3);
	CLine *l2=new CLine(p1,p3,FigGfxInfo);
	l2->rotate(p3,p1,point1,g3);
	point3 = p1;
	point2 = p2;
	point1 =p3;
	delete l,l2;
}

int CTriangle::gettype()
{return 3;}