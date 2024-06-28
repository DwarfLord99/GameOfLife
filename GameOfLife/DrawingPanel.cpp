#include "DrawingPanel.h"
#include "wx/graphics.h"
#include "wx/dcbuffer.h"

DrawingPanel::DrawingPanel(wxFrame* parent) : wxPanel(parent, wxID_ANY, wxPoint(0,0), wxSize(400,400))
{
	// Gives control of the rendering of DrawingPanel
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
	// Tells DrawingPanel to use the OnPaint method
	this->Bind(wxEVT_PAINT, &DrawingPanel::OnPaint, this);
}

DrawingPanel::~DrawingPanel()
{

}

void DrawingPanel::OnPaint(wxPaintEvent& paintEvent)
{
	// Prevents rendering issues in Windows
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();

	// Provides a graphic context to work with
	wxGraphicsContext* context = wxGraphicsContext::Create(dc);
	// Checks to see if the context failed
	if (!context) { return; }
	// Pen color. Represents the outline of any shape that is made
	context->SetPen(*wxBLACK);
	// Brush color. Represents the fill color of the shapes made
	context->SetBrush(*wxWHITE);
	// Draws a rectangle shape on the drawing panel
	//context->DrawRectangle(2, 5, 200, 200);

	// Draws grid. Cells for the grid adjust themselves to match the size of the window
	// Currently only works for preset grid size, does not adjust when resizing window after game is open

	float cellWidth = this->GetSize().x / (float)pGridSize;
	float cellHeight = this->GetSize().y / (float)pGridSize;

	for (int i = 0; i < pGridSize; i++)
	{
		for (int j = 0; j < pGridSize; j++)
		{
			context->DrawRectangle(i * cellWidth, j * cellHeight, cellWidth, cellHeight);
		}
	}
}

void DrawingPanel::SetDrawingPanelSize(wxSize& windowSize)
{
	this->SetSize(windowSize);
	this->Refresh();
}
