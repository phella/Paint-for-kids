#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;
bool filled ;	
string drw ;
public:
	Output();		
	bool getFilled();
	bool choice() ;
	void setchoice(drawstyle);
	void setfilled(bool);
	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void ClearToolbar() const ;
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	
	//Clears the drawing area
	void CreatecolorBar() const ;
	

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const; 
	//Draw a rectangle
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo trianGfxInfo, bool selected) const ;
	///Make similar functions for drawing all other figures.
	void Drawline(Point P1, Point P2, GfxInfo lineGfxInfo, bool selected) const ;
	void DrawCircle(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected) const ;

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	
	~Output();
};

#endif