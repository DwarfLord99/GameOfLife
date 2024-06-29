#pragma once
#include "wx/wx.h"
class DrawingPanel :
    public wxPanel
{
private:
    int pGridSize = 15;

    std::vector<std::vector<bool>>& pGameBoard;

public:
    DrawingPanel(wxFrame* parent, std::vector<std::vector<bool>>& gameBoard);
    ~DrawingPanel();

    void OnPaint(wxPaintEvent& paintEvent);
    void SetDrawingPanelSize(wxSize& windowSize);
    void SetGridSize(int size);
    void OnMouseUp(wxMouseEvent& event);

    wxDECLARE_EVENT_TABLE();
};

