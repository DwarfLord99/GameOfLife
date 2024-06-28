#include "MainWindow.h"

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(0,0), wxSize(400,400))
{
	pPanelGraphic = new DrawingPanel(this);

	Bind(wxEVT_SIZE, &MainWindow::OnSizeChange, this);
	InitializeGameBoard();
}

MainWindow::~MainWindow()
{

}

void MainWindow::OnSizeChange(wxSizeEvent& event)
{
	//Allows the grid to resize itself proportionately based on the size of the window
	wxSize windowSize = GetSize();
	if (pPanelGraphic != nullptr)
	{
		pPanelGraphic->SetDrawingPanelSize(windowSize);
	}
	event.Skip();
}

void MainWindow::InitializeGameBoard()
{
	//GameBoard size set to the grid size
	pGameBoard.resize(pGridSize);

	//Subvector of GameBoard vector set to grid size
	for (int i = 0; i < pGridSize; i++)
	{
		pGameBoard[i].resize(pGridSize);
	}

	pPanelGraphic->SetGridSize(pGridSize);
}
