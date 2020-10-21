#ifndef CLine_H
#define CLine_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point point1;	
	Point point2;
public:
	CLine() {}
	CLine(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual  bool check(int,int);
	virtual void PrintInfo(Output* pOut) ;
 int minn(int ,int );
 int maxx(int,int);
virtual CFigure* TransferFigure(Point p);
virtual void save(ofstream &savefile);
 virtual void Load(ifstream &loadfile);
 virtual CFigure* copy();
 virtual int gettype() ; 
 void rotate(Point&,Point&,Point&,GfxInfo&);
};

#endif