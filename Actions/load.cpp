#include"load.h"
#include"..\Figures\CCircle.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CTriangle.h"

load::load(ApplicationManager * pApp) :Action(pApp)
{
	loadfile = NULL;
}

void load::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("enter the name of the folder you want to load from");

	f = pIn->GetSrting(pOut);
	//std::ofstream savefile(f, std::ios_base::out | std::ios_base::app);
	//savefile.open(f);

	pOut->ClearStatusBar();
}
void load::Execute() {
	int x;
	ReadActionParameters();
	loadfile = new ifstream(f);
	loadcurcolors(*loadfile);
	*loadfile >> x;
	pManager->loadall(*loadfile, x,this);
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("you loaded from <" + f + ">");
}
	//for (int i = 0; i < x; i++)
	void load::loadload(ifstream &loadfile,int x, CFigure*&a){
	
		string y;

		loadfile >> y;
		if (y == "circle") {
			a = new CCircle;
			a->Load(loadfile);
		}
		else if (y == "rect") {
			a = new CRectangle;
			a->Load(loadfile);
		}
		else if (y == "triangle") {
			a = new CTriangle;
			a->Load(loadfile);
		}
		else if (y == "line") {
			a = new CLine;
			a->Load(loadfile);
			
		}
	}
	void load::autoload()
	{int x;
	loadfile=new ifstream("auto");
	*loadfile>>x;
	pManager->loadall(*loadfile,x,this);}



void load::loadcurcolors(ifstream &loadfile) {
	Output* pOut = pManager->GetOutput();
	string colors;
	loadfile >> colors;
	if (colors == "blue")
		UI.DrawColor = BLUE;
	else if (colors == "black")
		UI.DrawColor = BLACK;
	else if (colors == "white")
		UI.DrawColor = WHITE;
	else if (colors == "green")
		UI.DrawColor = GREEN;
	else if (colors == "red")
		UI.DrawColor = RED;

	loadfile >> colors;
	if (colors != "NO_FILL") {
		pOut->setfilled(true);
		if (colors == "blue")
			UI.FillColor = BLUE;
		else if (colors == "black")
			UI.FillColor = BLACK;
		else if (colors == "white")
			UI.FillColor = WHITE;
		else if (colors == "green")
			UI.FillColor = GREEN;
		else if (colors == "red")
			UI.FillColor = RED;
	}
	else pOut->setfilled(false);
}
load::~load() {
	delete loadfile;

}