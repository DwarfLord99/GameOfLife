#pragma once
#include "wx/wx.h"
#include "DrawingPanel.h"

class MainWindow :
    public wxFrame
{
private:
    DrawingPanel* pPanelGraphic = nullptr;
public:
    // Constructor and destructor for the Main Window
    MainWindow();
    ~MainWindow();
};

