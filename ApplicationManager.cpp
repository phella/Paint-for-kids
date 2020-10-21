#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions\AddCircAction.h"
#include "Actions\AddSelectAction.h"
#include"Actions\DeleteAction.h"
#include"Actions\AddLineAction.h"
#include"Actions\AddTriAction.h"
#include"Figures\CFigure.h"
#include"Actions\ChngCurrentColor.h"
#include "Actions\changefigcolors.h"
#include "CopyAction.h"
#include "CutAction.h"
#include "PasteAction.h"
#include"Actions\load.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	SelectedFig=NULL ;
	Clipboard=NULL;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	save *AutoS= NULL;
	load *AutoL=NULL;
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pOut->PrintMessage("draw a rectangle");
		pAct = new AddRectAction(this);
		break;

	case DRAW_LINE:
		///create AddLineAction here
		pOut->PrintMessage("draw a line");
		pAct= new AddLineAction(this);
		break;
	case DRAW_CIRC:
		pOut->PrintMessage("draw a circle");
		pAct=new AddCircAction(this);
		break ;
	case DRAW_TRI:
		pOut->PrintMessage("draw a triangle");
		pAct =new AddTriAction(this);
		break ;
	case EXIT:
		///create ExitAction here
		//	pOut->PrintMessage("exiting");
		break;
	case CHNG_DRAW_CLR:
		pOut->PrintMessage(" Change the drawing color ");
		pOut->setchoice(FRAME);	
		pOut->CreatecolorBar();
		break;

	case CHNG_FILL_CLR:
		pOut->PrintMessage("Action: Change background color , Click anywhere");
		pOut->setchoice(FILLED);
		if(SelectedFig ==NULL)
			{pOut->setfilled(true);}
		pOut->CreatecolorBar();
		break;
	case BLUEs :
		pOut->PrintMessage("Action: blue selected");
		if(SelectedFig !=NULL)	
		{pAct=new changefigcolors(this,BLUE);
		}
		else {pAct=new chngcurrentclrAction(this,BLUE);
		}
		pOut->ClearToolbar();
		pOut->CreateDrawToolBar();
		break ;


	case BLACKs :
		pOut->PrintMessage("Action: black selected");
		if(SelectedFig !=NULL){	pAct=new changefigcolors(this,BLACK);

		}
		else{	pAct=new chngcurrentclrAction(this,BLACK);}

		pOut->ClearToolbar();
		pOut->CreateDrawToolBar();
		break ;

	case WHITEs :
		pOut->PrintMessage("Action: white selected");
		if(SelectedFig !=NULL) {pAct=new changefigcolors(this,WHITE);


		}
		else{	pAct=new chngcurrentclrAction(this,WHITE);}

		pOut->ClearToolbar();
		pOut->CreateDrawToolBar();
		break ;

	case REDs :
		pOut->PrintMessage("Action: red selected");
		if(SelectedFig !=NULL){pAct=new changefigcolors(this,RED);
		}
		else{ pAct=new chngcurrentclrAction(this,RED);}

		pOut->ClearToolbar();
		pOut->CreateDrawToolBar();
		break ;

	case GREENs :
		pOut->PrintMessage("Action: green selected");

		if(SelectedFig !=NULL)
		{
			pAct=new changefigcolors(this,GREEN);
		}
		else
		{
			pAct=new chngcurrentclrAction(this,GREEN);
		}
		pOut->ClearToolbar();
		pOut->CreateDrawToolBar();
		break ;

	case STATUS:
		pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
		break;

	case DRAWING_AREA:
		pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
		break;

	case COPY:
		pOut->PrintMessage("Action:copy the figure");
		pAct=new CopyAction(this);
		break;
	case CUT :
		pOut->PrintMessage("Action: cut the figure, Click anywhere");
		pAct=new CutAction(this);
		break;
	case PASTE:
		pOut->PrintMessage("Action: paste the figure,Click anywhere");
		pAct=new PasteAction(this);
		break;
	case EMPTY:
		pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
		break;
	case SAVE:
		pOut->PrintMessage("Action: save the file,Click anywhere");
		pAct = new save(this);
		break;
	case LOAD:
		pOut->PrintMessage("Action: load something,Click anywhere");
		pAct = new load(this);
		break;
	case SELECTE:
		pOut->PrintMessage("Select a figure");
		pAct=new AddSelectAction(this);
		break ;
	case DEL :
		pOut->PrintMessage(" delecte the figure");
		pAct=new DeleteAction(this);
		break;
	case TO_DRAW:
		pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
		pOut->ClearToolbar();
		pOut->CreateDrawToolBar();
		pOut->ClearDrawArea();
		AutoL=new load(this);
		AutoL->autoload();
		delete AutoL;
		break;

	case TO_PLAY:
		pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
		pOut->ClearToolbar();
		pOut->CreatePlayToolBar();
		AutoS=new save(this);
		AutoS->autoExecute();
		delete AutoS;
		break;
	case HIDE_TYPE: 
		pOut->PrintMessage("Action: click on items of same type");
		pAct= new p_shapes(this);
		pOut->ClearDrawArea();
		AutoL=new load(this);
		AutoL->autoload();
		delete AutoL;
		break ;
	case HIDE_COLOR: 
		pOut->PrintMessage("Action: click on items of same color");
		pAct= new p_colors(this);
		pOut->ClearDrawArea();
		AutoL=new load(this);
		AutoL->autoload();
		delete AutoL;
		break ;
	case HIDE_CNT: 
		pOut->PrintMessage("Action: click on items of same type and color");
		pAct= new p_CS(this);
		pOut->ClearDrawArea();
		AutoL=new load(this);
		AutoL->autoload();
		delete AutoL;
		break ;
	case B_FORWARD: 
		Bforward();		
		break;
	case B_BACKWARD: 
		Bback() ;
		break;
	case ROTATE:
			pAct=new rotatee(this);
			break;
	}

	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) 
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	for(int i=1;i<=FigCount;i++){

		if(FigList[FigCount-i]->check(x,y) == true){
			return FigList[FigCount-i] ;}
		//Add your code here to search for a figure given a point x,y	

		//Remember that ApplicationManager only calls functions do NOT implement it.
	}
	return NULL ; 
}



void ApplicationManager::DeleteFigure(CFigure* sf) 
{ int x;
if(sf){
	for(int i=0;i<FigCount;i++)
		if(sf==FigList[i])x=i;
	delete FigList[x];
	for(int i=x;i<FigCount;i++)
	{FigList[i]=FigList[i+1];}

	FigList[FigCount-1]=NULL;
	FigCount--;
	setSelectedFig(NULL);
	
    }

}

CFigure*ApplicationManager::getSelectedFig(){
	return SelectedFig ;
}
void ApplicationManager::setSelectedFig(CFigure* sf){
	SelectedFig=sf ;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++){
		FigList[i]->Draw(pOut);	
		FigList[i]->setID(i); }//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }



void ApplicationManager::setClipboard(CFigure*ptr)
{
	Clipboard=ptr;
}
void ApplicationManager::ClearClipboard()
{
	if(Clipboard!=NULL)
	{
		delete Clipboard;
		Clipboard=NULL;
	}

}
CFigure* ApplicationManager::getClipboard()
{
	return Clipboard;

}

int ApplicationManager::getfigcount() {
	return FigCount;
}

void ApplicationManager::saveall(ofstream &savefile)const {
	for (int i = 0; i < FigCount; i++) {		
		FigList[i]->save(savefile);	
	}
}
void ApplicationManager::loadall(ifstream &loadfile, int x, load *a) {
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	FigCount=0;
	pOut->ClearDrawArea();
	for (int i = 0; i < x; i++) {
		a->loadload(loadfile, x, FigList[i]);
		FigCount++;
	}
}
//==================================================================================//
//							play mode Functions							            //
//==================================================================================//
void ApplicationManager::SetClrs(int& B,int& G,int& R,int& BK,int& W) const
{ color c; 
B=0;G=0;R=0;W=0;BK=0;
for(int i=0;i<FigCount;i++)
{if(FigList[i]->GetClr(c))
{  
	if(c == RED)R++;
	if(c == BLACK)BK++;
	if(c == WHITE)W++;
	if(c == GREEN)G++;
	if(c == BLUE)B++;
}	
}}

void ApplicationManager::SetShapes(int& C,int& R,int& L,int& T)const
{C=0;R=0;L=0;T=0;
int type;
for(int i=0;i<FigCount;i++)
{
	type=FigList[i]->gettype();
	switch (type)
	{
	case(0):C++;break;
	case(1):R++;break;
	case(2):L++;break;
	case(3):T++;break;
	}
}

}

void ApplicationManager::randfig(int& type,color& selcolor,int& count)const
{bool game=false;
for(int i=0;i<FigCount;i++) 
{if(FigList[i]->GetClr(selcolor))game=true;}
count=0;
if(game)
{
	int x ;bool fill=false;
	while(fill==false){
		x=rand()% FigCount;
		fill=FigList[x]->GetClr(selcolor);
	}
	type=FigList[x]->gettype();
	for(int i=0;i<FigCount;i++)
	{
		FigList[i]->getcount(type,count,selcolor);
}
}}

////////////////////////////////////////////////////////////////////////////////////
//bring forward and backward
void ApplicationManager::Bback() 
{int x; CFigure* fig ;
if(getSelectedFig())
{
for(int i=0;i<FigCount;i++)
if(FigList[i]==getSelectedFig())x=i;

for(int i=x;i>0;i--)
{fig=FigList[i-1];
FigList[i-1]=FigList[i];
FigList[i]=fig;}
}
pOut->ClearDrawArea();
UpdateInterface();
}

void ApplicationManager::Bforward() 
{
	int x; CFigure* fig ;
if(getSelectedFig())
{
for(int i=0;i<FigCount;i++)
if(FigList[i]==getSelectedFig())x=i;
for(int i=x;i<FigCount-1;i++)
{fig=FigList[i+1];
FigList[i+1]=FigList[i];
FigList[i]=fig;}
}
pOut->ClearDrawArea();
UpdateInterface();
}

/*void ApplicationManager::delrotate(CFigure* fig,CFigure*rotated) 
{
	int x;
	for(int i=0;i<FigCount;i++)
	{
		if(fig==FigList[i]) x=i;
	}
	delete	FigList[x];
	FigList[x]= rotated;
}*/



////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete Clipboard;
	delete pIn;
	delete pOut;

}


