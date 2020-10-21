#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CCircle(){}
	CCircle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool check(int,int);
		virtual void PrintInfo(Output* pOut) ;
	virtual CFigure* TransferFigure(Point p);
	virtual void save(ofstream &savefile);
 virtual void Load(ifstream &loadfile);
 virtual CFigure* copy();
 virtual int gettype() ;
 void rotate(Point& ,Point&,Point&,GfxInfo&);
};

#endif