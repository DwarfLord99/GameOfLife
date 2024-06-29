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
    wxToolBar* pToolBar;
public:
    // Constructor and destructor for the Main Window
    MainWindow();
    ~MainWindow();

    void OnSizeChange(wxSizeEvent& event);
    void InitializeGameBoard();

    void OnPlayButtonClicked(wxCommandEvent& event);
    void OnPauseButtonClicked(wxCommandEvent& event);
    void OnNextButtonClicked(wxCommandEvent& event);
    void OnTrashButtonClicked(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

