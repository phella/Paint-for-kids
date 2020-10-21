#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
		CRectangle() {}
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool check(int,int);
		virtual void PrintInfo(Output* pOut) ;
	float area(int,int);
	int minimum(int,int);
	int maximum(int,int);

virtual CFigure* TransferFigure(Point p);
virtual void save(ofstream &savefile);
 virtual void Load(ifstream &loadfile);
 virtual CFigure* copy();
 virtual int gettype() ; 
 void rotate(Point& ,Point&,Point&,GfxInfo&);
};

#endif