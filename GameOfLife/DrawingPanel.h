#pragma once
#include "wx/wx.h"
class DrawingPanel :
    public wxPanel
{
private:
    int pGridSize = 15;

public:
    DrawingPanel(wxFrame* parent);
    ~DrawingPanel();

    void OnPaint(wxPaintEvent& paintEvent);
    void SetDrawingPanelSize(wxSize& windowSize);
    void SetGridSize(int size);
};

