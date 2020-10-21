#pragma once
#include"Action.h"
#include "ChngCurrentColor.h"
#include<fstream>
#include "..\ApplicationManager.h"

class save : public Action {
	string f;
	ofstream* savefile;
public:
	save(ApplicationManager * pApp);
	
	virtual void ReadActionParameters();//read the file name
	virtual void Execute();
	virtual void autoExecute();
	void savecurcolors(ofstream &savefile);
	~save();
};