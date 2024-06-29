#pragma once
#include "wx/wx.h"
#include "DrawingPanel.h"

class MainWindow :
    public wxFrame
{
private:
    int pGridSize = 15;

    DrawingPanel* pPanelGraphic = nullptr;
    std::vector<std::vector<bool>> pGameBoard;
public:
    // Constructor and destructor for the Main Window
    MainWindow();
    ~MainWindow();

    void OnSizeChange(wxSizeEvent& event);
    void InitializeGameBoard();

    wxDECLARE_EVENT_TABLE();
};

