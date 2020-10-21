#pragma once
#include"Action.h"
#include<fstream>
#include "..\ApplicationManager.h"
class load :public Action {
	string f;
	ifstream*loadfile;
public:
	load(ApplicationManager * pApp);

	virtual void ReadActionParameters();//read the file name
	virtual void Execute();
	void autoload();
	void loadload(ifstream &loadfile, int x, CFigure*&a);
	void loadcurcolors(ifstream &loadfile);
		~load();











};