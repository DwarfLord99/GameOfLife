#include "MainWindow.h"

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(0,0), wxSize(400,400))
{
	pPanelGraphic = new DrawingPanel(this);

	Bind(wxEVT_SIZE, &MainWindow::OnSizeChange, this);
}

MainWindow::~MainWindow()
{

}

void MainWindow::OnSizeChange(wxSizeEvent& event)
{
	wxSize windowSize = GetSize();
	if (pPanelGraphic != nullptr)
	{
		pPanelGraphic->SetDrawingPanelSize(windowSize);
	}
	event.Skip();
}
