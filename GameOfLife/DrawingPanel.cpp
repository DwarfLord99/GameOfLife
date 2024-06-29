#include "DrawingPanel.h"
#include "wx/graphics.h"
#include "wx/dcbuffer.h"

wxBEGIN_EVENT_TABLE(DrawingPanel, wxPanel)
	EVT_PAINT(DrawingPanel::OnPaint, this)
	EVT_LEFT_UP(DrawingPanel::OnMouseUp)
wxEND_EVENT_TABLE()

DrawingPanel::DrawingPanel(wxFrame* parent, std::vector<std::vector<bool>>& gameBoard) : 
	wxPanel(parent, wxID_ANY, wxPoint(0,0), wxSize(400,400)), pGameBoard(gameBoard)
{
	// Gives control of the rendering of DrawingPanel
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
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

	// Draws grid. Cells for the grid adjust themselves to match the size of the window
	float cellWidth = this->GetSize().x / (float)pGridSize;
	float cellHeight = this->GetSize().y / (float)pGridSize;

	for (int i = 0; i < pGridSize; i++)
	{
		for (int j = 0; j < pGridSize; j++)
		{
			if (pGameBoard[i][j] == true)
			{
				// Cell in the grid is alive
				context->SetBrush(*wxLIGHT_GREY);
			}
			else if (pGameBoard[i][j] == false)
			{
				// Cell in the grid is dead
				context->SetBrush(*wxWHITE);
			}
			context->DrawRectangle(i * cellWidth, j * cellHeight, cellWidth, cellHeight);
		}
	}
}

void DrawingPanel::SetDrawingPanelSize(wxSize& windowSize)
{
	this->SetSize(windowSize);
	this->Refresh();
}

void DrawingPanel::SetGridSize(int size)
{
	pGridSize = size;
}

void DrawingPanel::OnMouseUp(wxMouseEvent& event)
{
	// X and Y coordinate of where the mouse was clicked
	wxCoord pMouseClickXCoord = event.GetX();
	wxCoord pMouseClickYCoord = event.GetY();

	float cellWidth = this->GetSize().x / (float)pGridSize;
	float cellHeight = this->GetSize().y / (float)pGridSize;

	// Determines which box was clicked the grid
	pMouseClickXCoord = pMouseClickXCoord / cellWidth;
	pMouseClickYCoord = pMouseClickYCoord / cellHeight;

	// Checks if box clicked is true or false and sets it to the opposite.
	// True becomes false and false becomes true
	// True means living cell. False means dead cell
	if (pGameBoard[pMouseClickXCoord][pMouseClickYCoord] == true)
	{
		// Living cell becomes dead cell
		pGameBoard[pMouseClickXCoord][pMouseClickYCoord] = false;
	}
	else
	{
		// Dead cell becomes living cell
		pGameBoard[pMouseClickXCoord][pMouseClickYCoord] = true;
	}

	Refresh();
}
