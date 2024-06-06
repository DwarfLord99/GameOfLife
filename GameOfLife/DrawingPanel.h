#pragma once
#include "wx/wx.h"
class DrawingPanel :
    public wxPanel
{
private:
    

public:
    DrawingPanel(wxFrame* parent);
    ~DrawingPanel();

    void OnPaint(wxPaintEvent& paintEvent);
};

