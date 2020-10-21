#include "CCircle.h"
#include<cmath>
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	
	}
	

void CCircle::Draw(Output* pOut) const
{

	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawCircle(Corner1, Corner2, FigGfxInfo, Selected);
}

void CCircle::PrintInfo(Output* pOut){
		int distx=abs(Corner2.x-Corner1.x );
int disty=abs(Corner2.y-Corner1.y) ;

int radius=sqrt(pow(disty,2) + pow(distx,2)) ;
double area=3.14*radius*radius ;

				std::string id=std::to_string(ID);
		std::string rad=std::to_string(radius);
		std::string are =std::to_string(area);
		pOut->PrintMessage("You selected a circle which id = "+id +" and its radius= "+rad +" and its area =" +are );

};
bool CCircle::check(int x,int y){
int distx=abs(Corner2.x-Corner1.x );
int disty=abs(Corner2.y-Corner1.y) ;

int radius=sqrt(pow(disty,2) + pow(distx,2)) ;
	
	
	int center_x=Corner1.x ;
		int  center_y=Corner1.y ;
	if( ( pow((x -center_x),2) + pow((y - center_y),2) ) <= pow(radius,2) )
	return true ;
	
	return false;
}


CFigure* CCircle::TransferFigure(Point p)
{
	Point cen;
	CCircle* addnewcircle=new CCircle(Corner1,Corner2,FigGfxInfo);



cen.x=(Corner1.x+Corner2.x)/2;
	cen.y=(Corner1.y+Corner2.y)/2;
	addnewcircle->Corner1.x=p.x-cen.x+Corner1.x;
	addnewcircle->Corner1.y=p.y-cen.y+Corner1.y;
	addnewcircle->Corner2.x=p.x-cen.x+Corner2.x;
	addnewcircle->Corner2.y=p.y-cen.y+Corner2.y;

    return addnewcircle;

}

CFigure* CCircle::copy()
{
	CCircle* addnewcircle=new CCircle(Corner1,Corner2,FigGfxInfo);
	 return addnewcircle;
}




void  CCircle::save(ofstream &savefile) {
	
	savefile << "circle  ";
	savefile << getID() << "  ";
	savefile << Corner1.x << " " << Corner1.y << "  ";
	savefile << Corner2.x << " " << Corner2.y << "  ";
	savedrawing(savefile);
	savefilling(savefile);
}
void CCircle::Load(ifstream &loadfile) {
	bool x;
	loadfile >> ID;
	loadfile >> Corner1.x >> Corner1.y;
	loadfile >> Corner2.x >> Corner2.y;
	loaddrawing(loadfile);
	loadfilling(loadfile);	
}
int CCircle::gettype()
{return 0;}


void CCircle::rotate(Point& dummy,Point& dummy1,Point& dummy2,GfxInfo& g1) 
{
}