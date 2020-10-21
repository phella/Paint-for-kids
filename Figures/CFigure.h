#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include<fstream>
#include<cmath>
//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure() { Selected = false; }
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
virtual bool check(int,int)=0;
virtual	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	virtual void ChngFillClr(color Fclr);	//changes the figure's filling color
	
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	virtual CFigure* TransferFigure(Point p) = 0;
	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut)=0 ;	//print all figure info on the status bar
	virtual void save(ofstream &savefile) = 0;
	virtual void Load(ifstream &loadfile) = 0;
	virtual void setID(int) ;
	virtual int getID();
	bool GetClr(color&) ;
	void savefilling(ofstream &savefile);
	void savedrawing(ofstream &savefile);
	void loadfilling(ifstream &loadfile);
	void loaddrawing(ifstream &loadfile);
	virtual CFigure* copy()=0;
	virtual int gettype()=0;
	void getcount(int,int&,color);
	virtual void rotate(Point&,Point&,Point&,GfxInfo&)=0;
};

#endif