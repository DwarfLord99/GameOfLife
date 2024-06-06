#pragma once

#include "wx/wx.h"
#include "MainWindow.h"

class App : public wxApp
{
private:
	
public:
	// Main Window pointer
	MainWindow* window = nullptr;

	App();
	~App();
	virtual bool OnInit();
};

