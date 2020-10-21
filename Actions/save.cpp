#include"save.h"




void save::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("enter the name of the folder you want to save in");
	
	f = pIn->GetSrting(pOut);
	//std::ofstream savefile(f, std::ios_base::out | std::ios_base::app);
	//savefile.open(f);

	pOut->ClearStatusBar();
}
void save::Execute() {
	
	ReadActionParameters();
	savefile = new ofstream(f);
	savecurcolors(*savefile);
	*savefile << pManager->getfigcount() << endl;
	 
	pManager->saveall(*savefile);
	Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("you saved to the file <"+f+">");

	savefile->close();
}

void save::autoExecute() 
{
	savefile=new ofstream("auto");
	*savefile << pManager->getfigcount() << endl;
	pManager->saveall(*savefile);
	savefile->close();
}
save :: save (ApplicationManager * pApp) :Action(pApp)
{
	savefile = NULL;
}
void save::savecurcolors(ofstream &savefile) {

	Output* pOut = pManager->GetOutput();
		string colors;


	if (UI.DrawColor.ucRed == 0 && UI.DrawColor.ucGreen == 0 && UI.DrawColor.ucBlue == 255)
		colors = "blue";
	else if (UI.DrawColor.ucRed == 0 && UI.DrawColor.ucGreen == 0 && UI.DrawColor.ucBlue == 0)
		colors = "black";
	else if (UI.DrawColor.ucRed == 255 && UI.DrawColor.ucGreen == 255 && UI.DrawColor.ucBlue == 255)
		colors = "white";
	else if (UI.DrawColor.ucRed == 0 && UI.DrawColor.ucGreen == 255 && UI.DrawColor.ucBlue == 0)
		colors = "green";
	else if (UI.DrawColor.ucRed == 255 && UI.DrawColor.ucGreen == 0 && UI.DrawColor.ucBlue == 0)
		colors = "red";
	savefile << colors << "  ";

	if (pOut->getFilled()) {
		if (UI.FillColor.ucRed == 0 && UI.FillColor.ucGreen == 0 && UI.FillColor.ucBlue == 255)
			colors = "blue";
		else if (UI.FillColor.ucRed == 0 && UI.FillColor.ucGreen == 0 && UI.FillColor.ucBlue == 0)
			colors = "black";
		else if (UI.FillColor.ucRed == 255 && UI.FillColor.ucGreen == 255 && UI.FillColor.ucBlue == 255)
			colors = "white";
		else if (UI.FillColor.ucRed == 0 && UI.FillColor.ucGreen == 255 && UI.FillColor.ucBlue == 0)
			colors = "green";
		else if (UI.FillColor.ucRed == 255 && UI.FillColor.ucGreen == 0 && UI.FillColor.ucBlue == 0)
			colors = "red";
		savefile << colors << endl;
	}
	else
		savefile << "NO_FILL" << endl;
}
save::~save() {
	delete savefile;

}