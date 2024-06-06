#include "MainWindow.h"

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(0,0), wxSize(400,400))
{
	pPanelGraphic = new DrawingPanel(this);
}

MainWindow::~MainWindow()
{

}
