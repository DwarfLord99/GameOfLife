#pragma once
#include "wx/wx.h"
#include "GameSettings.h"

class DrawingPanel :
    public wxPanel
{
private:
    std::vector<std::vector<bool>>& pGameBoard;

    GameSettings* pGameSettings = nullptr;
public:
    DrawingPanel(wxFrame* parent, std::vector<std::vector<bool>>& gameBoard);
    ~DrawingPanel();

    void OnPaint(wxPaintEvent& paintEvent);
    void SetDrawingPanelSize(wxSize& windowSize);
    void SetGridSize(int size);
    void OnMouseUp(wxMouseEvent& event);

    void SetGameSettings(GameSettings& gameSetting);

    wxDECLARE_EVENT_TABLE();
};

