#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include"Actions\save.h"
#include"Actions\p_colors.h"
#include"Actions\p_CS.h"
#include"Actions\p_shapes.h"
#include"Figures\CCircle.h"
#include"Figures\CLine.h"
#include"Figures\CRectangle.h"
#include"Figures\CTriangle.h"
#include"Actions\rotate.h"

//Main class that manages everything in the application.
class load;

class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	
public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	CFigure* getSelectedFig();
	void setSelectedFig(CFigure*);
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) ; //Search for a figure given a point inside the figure
	void DeleteFigure(CFigure* );	
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	


	
	void setClipboard(CFigure*);
	CFigure* getClipboard();

	void saveall(ofstream &savefile)const;
	void loadall(ifstream &loadfile, int x, load *a);
		int getfigcount() ;
		 void SetClrs(int& ,int& ,int& ,int& ,int& )const;
	 void SetShapes(int&,int&,int&,int&)const;
	 void randfig(int& ,color&,int&)const;
	 void Bback();
	 void Bforward();
	
	 void ClearClipboard();
	 //void delrotate(CFigure*,CFigure*);

};

#endif