#include "MainWindow.h"
#include "play.xpm"
#include "next.xpm"
#include "pause.xpm"
#include "trash.xpm"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
	EVT_SIZE(MainWindow::OnSizeChange)
	EVT_MENU(10001, MainWindow::OnPlayButtonClicked)
	EVT_MENU(10002, MainWindow::OnPauseButtonClicked)
	EVT_MENU(10003, MainWindow::OnNextButtonClicked)
	EVT_MENU(10004, MainWindow::OnTrashButtonClicked)
wxEND_EVENT_TABLE()

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(0,0), wxSize(400,400))
{
	pStatusBar = CreateStatusBar();
	
	wxBitmap playIcon(play_xpm);
	wxBitmap pauseIcon(pause_xpm);
	wxBitmap nextIcon(next_xpm);
	wxBitmap trashIcon(trash_xpm);

	pToolBar = CreateToolBar();
	pToolBar->AddTool(10001, "Play", playIcon);
	pToolBar->AddTool(10002, "Pause", pauseIcon);
	pToolBar->AddTool(10003, "Next", nextIcon);
	pToolBar->AddTool(10004, "Trash", trashIcon);
	pToolBar->Realize();

	pPanelGraphic = new DrawingPanel(this, pGameBoard);

	InitializeGameBoard();
	this->Layout();
}

MainWindow::~MainWindow()
{

}

void MainWindow::OnSizeChange(wxSizeEvent& event)
{
	// Allows the grid to resize itself proportionately based on the size of the window
	wxSize windowSize = GetSize();
	if (pPanelGraphic != nullptr)
	{
		pPanelGraphic->SetDrawingPanelSize(windowSize);
	}
	event.Skip();
}

void MainWindow::InitializeGameBoard()
{
	// GameBoard size set to the grid size
	pGameBoard.resize(pGridSize);

	// Subvector of GameBoard vector set to grid size
	for (int i = 0; i < pGridSize; i++)
	{
		pGameBoard[i].resize(pGridSize);
	}

	// Sets the grid size in the DP
	pPanelGraphic->SetGridSize(pGridSize);
}

void MainWindow::OnPlayButtonClicked(wxCommandEvent& event)
{

}

void MainWindow::OnPauseButtonClicked(wxCommandEvent& event)
{

}

void MainWindow::OnNextButtonClicked(wxCommandEvent& event)
{

}

void MainWindow::OnTrashButtonClicked(wxCommandEvent& event)
{

}
