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
	pStatusBar = CreateStatusBar(3);
	UpdateStatusBarText(pLivingCellCount, pGenerationCount);
	
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

void MainWindow::UpdateStatusBarText(int livingCellCount, int generationCount)
{
	//Update text shown in the status bar

	wxString _livingCellCount = wxString::Format(wxT("%d"), livingCellCount);
	wxString _generationCount = wxString::Format(wxT("%d"), generationCount);

	wxString cellCountMessage = wxString::Format("Living Cell Count: " + _livingCellCount);
	wxString generationCountMessage = wxString::Format("Generation Count: " + _generationCount);

	pStatusBar->SetStatusText(cellCountMessage, 1);
	pStatusBar->SetStatusText(generationCountMessage, 2);
}

void MainWindow::OnPlayButtonClicked(wxCommandEvent& event)
{

}

void MainWindow::OnPauseButtonClicked(wxCommandEvent& event)
{

}

void MainWindow::OnNextButtonClicked(wxCommandEvent& event)
{
	NextCellGeneration();
}

void MainWindow::OnTrashButtonClicked(wxCommandEvent& event)
{
	// clears the board and resets all values to default
	for (int i = 0; i < pGameBoard.size(); i++)
	{
		for (int j = 0; j < pGameBoard.size(); j++)
		{
			pGameBoard[i][j] = false;
		}
	}

	pLivingCellCount = 0;
	pGenerationCount = 0;

	UpdateStatusBarText(pLivingCellCount, pGenerationCount);

	pPanelGraphic->Refresh();
}

void MainWindow::NextCellGeneration()
{
	// Sandbox variable to handle the calculations of which cell lives or dies
	std::vector<std::vector<bool>> sandbox;

	// Resizes the sandbox to math the size of the main grid
	sandbox.resize(pGridSize);

	// Resize each subvector of the sandbox to math the grid size
	for (int innerSandboxVector = 0; innerSandboxVector < sandbox.size(); innerSandboxVector++)
	{
		sandbox[innerSandboxVector].resize(pGridSize);
	}

	for (int cellRow = 0; cellRow < pGridSize; cellRow++)
	{
		for (int cellColumn = 0; cellColumn < pGridSize; cellColumn++)
		{
			pCellNeighborCount = CellNeighborCount(cellRow, cellColumn);

			if (pGameBoard[cellRow][cellColumn] == true && pCellNeighborCount == 2 || 
				pGameBoard[cellRow][cellColumn] == true && pCellNeighborCount == 3)
			{
				sandbox[cellRow][cellColumn] = true;
				pLivingCellCount++;
			}
			else if (pGameBoard[cellRow][cellColumn] == true && pCellNeighborCount < 2 ||
				pGameBoard[cellRow][cellColumn] == true && pCellNeighborCount > 3)
			{
				sandbox[cellRow][cellColumn] = false;
			}
			else if (pGameBoard[cellRow][cellColumn] == false && pCellNeighborCount == 3)
			{
				sandbox[cellRow][cellColumn] = true;
				pLivingCellCount++;
			}

			pCellNeighborCount = 0;
		}
	}

	pGameBoard.swap(sandbox);

	pGenerationCount++;

	UpdateStatusBarText(pLivingCellCount, pGenerationCount);

	pLivingCellCount = 0;

	pPanelGraphic->Refresh();
}

int MainWindow::CellNeighborCount(int cellRow, int cellColumn)
{
	// Checks for how many neighbors a cell has
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (i == 0 && j == 0) { continue; }

			if (pGameBoard[cellRow][cellColumn] == true || pGameBoard[cellRow][cellColumn] == false)
			{
				if (cellRow + i >= 0 && cellRow + i < pGameBoard.size() || 
					cellRow + i < 0 && cellRow + i < pGameBoard.size())
				{
					if (cellColumn + j >= 0 && cellColumn + j < pGameBoard.size() ||
						cellColumn + j < 0 && cellColumn + j < pGameBoard.size())
					{
						if (pGameBoard[cellRow + i][cellColumn + j] == true)
						{
							pCellNeighborCount++;
						}
					}
				}
			}
		}
	}

	return pCellNeighborCount;
}
