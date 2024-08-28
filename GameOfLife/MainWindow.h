#pragma once
#include "wx/wx.h"
#include "DrawingPanel.h"

class MainWindow :
    public wxFrame
{
private:
    int pGridSize = 3;
    int pLivingCellCount = 0;
    int pCellNeighborCount = 0;
    int pGenerationCount = 0;

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
    void UpdateStatusBarText(int livingCellCount, int generationCount);

    void OnPlayButtonClicked(wxCommandEvent& event);
    void OnPauseButtonClicked(wxCommandEvent& event);
    void OnNextButtonClicked(wxCommandEvent& event);
    void OnTrashButtonClicked(wxCommandEvent& event);

    void NextCellGeneration();
    int CellNeighborCount(int cellRow, int cellColumn);

    wxDECLARE_EVENT_TABLE();
};

