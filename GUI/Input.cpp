#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	
	//Wait for mouse click

}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	if(UI.InterfaceMode == MODE_COLORS) 
	{
		if (y >=0 && y<UI.ToolBarHeight)
			{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
				{
				case ITM_BLUE: return BLUEs;
				case ITM_BLACK:return BLACKs;
				case ITM_WHITE: return WHITEs;
				case ITM_RED : return REDs;
				case ITM_GREEN: return GREENs;

				default: return EMPTY;	//A click on empty place in desgin toolbar
				}
			}
	}
	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;  //1
			case ITM_CIRC: return DRAW_CIRC; //2
			case ITM_LINE:return DRAW_LINE; //3
			case ITM_DC:return CHNG_DRAW_CLR; //4
			case ITM_FC:return CHNG_FILL_CLR; //5
			case ITM_DEL:return DEL; //6
			case ITM_SWITCH: return TO_PLAY; //7
			case ITM_EXIT: return EXIT;	 //8
			case ITM_TRI:return DRAW_TRI;
			case ITM_SAVE :return SAVE;
			case ITM_LOAD :return LOAD;
			case ITM_PASTE:return PASTE;
			case ITM_CUT:return CUT;
			case ITM_CPY:return COPY;
			case ITM_SELECT: return SELECTE;
			case ITM_FORWARD:return B_FORWARD;
			case ITM_BACKWARD:return B_BACKWARD;
			case ITM_ROTATE:return ROTATE; 
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_HIDE_TYPE: return HIDE_TYPE;
			case ITM_HIDE_COLOR: return HIDE_COLOR;
			case ITM_HIDE_CNT: return HIDE_CNT;
			case ITM_TO_DRAW : return TO_DRAW ;
			case ITM_EXIT2:return EXIT;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		//just for now. This should be updated
	}	}

}
/////////////////////////////////
	
Input::~Input()
{
}
