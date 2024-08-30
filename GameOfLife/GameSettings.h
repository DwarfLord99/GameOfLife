#pragma once
#include <wx/colour.h>
#include <fstream>

struct GameSettings
{
	// control grid size
	int GridSize = 15;
	// control the timer interval
	int TimerInterval = 50;
	// variable to store the number of living neighbor cells to display
	int NumberOfLivingNeighborCells = 0;
	// bool to turn on orr off the neighbor count display
	bool isCountOn = false;

	// Cell Color Control

	// Living Cells
	unsigned int LivingCellRed = 128;
	unsigned int LivingCellGreen = 128;
	unsigned int LivingCellBlue = 128;
	unsigned int LivingCellAlpha = 128;

	// Dead Cells
	unsigned int DeadCellRed = 255;
	unsigned int DeadCellGreen = 255;
	unsigned int DeadCellBlue = 255;
	unsigned int DeadCellAlpha = 255;

	void SetLivingCellColor(wxColor color)
	{
		// Breaks down chosen color into RGBA values to create the color of living cells

		LivingCellRed = color.GetRed();
		LivingCellGreen = color.GetGreen();
		LivingCellBlue = color.GetBlue();
		LivingCellAlpha = color.GetAlpha();
	}

	wxColor GetLivingCellColor()
	{
		// uses RGBA value to sett he color of the living cells

		wxColor livingCellColor(LivingCellRed, LivingCellGreen, LivingCellBlue, LivingCellAlpha);
		return livingCellColor;
	}

	void SetDeadCellColor(wxColor color)
	{
		DeadCellRed = color.GetRed();
		DeadCellGreen = color.GetGreen();
		DeadCellBlue = color.GetBlue();
		DeadCellAlpha = color.GetAlpha();
	}

	wxColor GetDeadCellColor()
	{
		wxColor deadCellColor(DeadCellRed, DeadCellGreen, DeadCellBlue, DeadCellAlpha);
		return deadCellColor;
	}

	void SaveMenuSettings()
	{
		std::ofstream file("settings.bin", std::ios::out | std::ios::binary);
		file.write((char*)this, sizeof(GameSettings));
		file.close();
	}

	void LoadMenuSettings()
	{
		std::ifstream file("settings.bin", std::ios::binary | std::ios::in);
		file.read((char*)this, sizeof(GameSettings));
		file.close();
	}
};