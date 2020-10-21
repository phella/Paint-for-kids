#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	filled=false ;
	
	UI.width = 1500;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = WHITE;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
void Output::CreatecolorBar() const
{ ClearToolbar();
	UI.InterfaceMode = MODE_COLORS;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\blues.jpg";
	MenuItemImages[ITM_BLACK] ="images\\MenuItems\\black.jpg";
    MenuItemImages[ITM_WHITE] ="images\\MenuItems\\whiteonly.jpg";
	MenuItemImages[ITM_RED] ="images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_GREEN] ="images\\MenuItems\\green.jpg";
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	//Draw a line under the toolbar
	pWind->SetPen(BLUE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\rectangle.jpg";//1
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\circle.jpg";//2
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\line.jpg";//3
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\triangle.jpg";
	MenuItemImages[ITM_SWITCH]="images\\MenuItems\\switch.jpg";
	MenuItemImages[ITM_SWITCH]="images\\MenuItems\\switch.jpg";
	MenuItemImages[ITM_DC] = "images\\MenuItems\\brush.jpg";//4
	MenuItemImages[ITM_FC] = "images\\MenuItems\\fillcopy.jpg";//5
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\select.jpg";//5
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\savecopy.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\LOAD.jpg";
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\deletecopy.jpg";//6
	MenuItemImages[ITM_CPY] = "images\\MenuItems\\copycopy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\cut2dkebyr.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\pastecopy.jpg";
	MenuItemImages[ITM_FORWARD]="images\\MenuItems\\b_forward.jpg";
	MenuItemImages[ITM_BACKWARD]="images\\MenuItems\\b_backward.jpg";
	MenuItemImages[ITM_ROTATE]="images\\MenuItems\\rotate.jpg";	
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";


	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(BLUE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_HIDE_TYPE] = "images\\MenuItems\\type.jpg";
	MenuItemImages[ITM_HIDE_COLOR] = "images\\MenuItems\\bycolor.jpg";
	MenuItemImages[ITM_HIDE_CNT] = "images\\MenuItems\\bothh.jpg";

	MenuItemImages[ITM_TO_DRAW] = "images\\MenuItems\\switch.jpg";
	MenuItemImages[ITM_EXIT2] = "images\\MenuItems\\Menu_Exit.jpg";
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(GREEN, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
void Output::ClearToolbar() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	
}


//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//0 for frame and	1 for filled

//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}
void Output:: setfilled(bool s){
	filled=s;

}
void Output::setchoice(drawstyle dw){
	
	switch(dw)
	{
	
		case FILLED:
			drw="fillclr" ;
		
				break ;
		case FRAME:
			drw="drwclr" ;
			break;
			
		
		default:
		
		
			break ;

	}

}
bool Output::getFilled(){

	if(filled) return true;
	else return false ;
}
bool Output:: choice(){
	if(drw =="fillclr") return true;
	else return false;


}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo trianGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = trianGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);

	drawstyle style;
	if (trianGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(trianGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}
void Output::Drawline(Point P1, Point P2, GfxInfo lineGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = lineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (lineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(lineGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawCircle(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected) const
{
	double radius = (sqrt(pow(abs(P1.x - P2.x), 2) + pow(abs(P1.y - P2.y), 2))) ;
	double center_x =P1.x;
	double center_y = P1.y ;
	color DrawingClr;

	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);

	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(center_x, center_y, radius, style);

}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	filled=false;
	delete pWind;
}


