#pragma once
#include "wx/wx.h"
#include "DrawingPanel.h"

class MainWindow :
    public wxFrame
{
private:
    int pGridSize = 15;
    int pLivingCellCount;
    int pCellGenerationCount;

    DrawingPanel* pPanelGraphic = nullptr;
    std::vector<std::vector<bool>> pGameBoard;

    wxStatusBar* pStatusBar;
public:
    // Constructor and destructor for the Main Window
    MainWindow();
    ~MainWindow();

    void OnSizeChange(wxSizeEvent& event);
    void InitializeGameBoard();

    wxDECLARE_EVENT_TABLE();
};

