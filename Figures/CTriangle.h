#ifndef CTri_H
#define CTri_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point p1;	
	Point p2;
	Point p3 ;
public:CTriangle() {}
	CTriangle(Point , Point, Point,GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool check(int,int);

	float area(int x1, int y1, int x2, int y2, int x3, int y3);
	virtual void PrintInfo(Output * pout);
virtual CFigure* TransferFigure(Point p);
	virtual void save(ofstream &savefile);
 virtual void Load(ifstream &loadfile);
 virtual CFigure* copy();
 virtual int gettype();
 void rotate(Point& ,Point&,Point&, GfxInfo&);
};

#endif