#pragma once
#include "wx/wx.h"
#include "DrawingPanel.h"
#include "GameSettings.h"

class MainWindow :
    public wxFrame
{
private:
    int pLivingCellCount = 0;
    int pCellNeighborCount = 0;
    int pGenerationCount = 0;

    DrawingPanel* pPanelGraphic = nullptr;
    std::vector<std::vector<bool>> pGameBoard;
    std::vector<std::vector<int>> pNeighborCount;

    wxMenuBar* pMenuBar = nullptr;
    wxMenu* pOptionsMenu = nullptr;
    wxMenu* pViewMenu = nullptr;
    wxMenuItem* pNeighborShowOption = nullptr;

    wxStatusBar* pStatusBar = nullptr;
    wxToolBar* pToolBar = nullptr;
    wxTimer* pCellTimer = nullptr;    
public:
    GameSettings gameSettings;

    // Constructor and destructor for the Main Window
    MainWindow();
    ~MainWindow();

    void OnSizeChange(wxSizeEvent& event);
    void InitializeGameBoard();
    void UpdateStatusBarText(int livingCellCount, int generationCount);

    void NextCellGeneration();
    int CellNeighborCount(int cellRow, int cellColumn);

    void CellGenerationTimer(wxTimerEvent& event);

    void OnPlayButtonClicked(wxCommandEvent& event);
    void OnPauseButtonClicked(wxCommandEvent& event);
    void OnNextButtonClicked(wxCommandEvent& event);
    void OnTrashButtonClicked(wxCommandEvent& event);
    void OnOptionsButtonClicked(wxCommandEvent& event);
    void OnNeighborCountClicked(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};

