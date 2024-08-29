#define SETTINGS_GRID_SIZE_SPINNER_CONTROL 10001
#define SETTINGS_TIMER_INTERVAL_SPINNER_CONTROL 10002
#define SETTINGS_LIVING_CELL_COLOR_PICKER 10003
#define SETTING_DEAD_CELL_COLOR_PICKER 10004

#include "SettingsDialog.h"

wxBEGIN_EVENT_TABLE(SettingsDialog, wxDialog)
	EVT_BUTTON(wxID_OK, SettingsDialog::OnOkButtonClick)
	EVT_BUTTON(wxID_CANCEL, SettingsDialog::OnCancelButtonClick)
wxEND_EVENT_TABLE()

SettingsDialog::SettingsDialog(wxWindow* parent) : 
	wxDialog(parent, wxID_ANY, "Settings", wxPoint(100,100), wxSize(300,300))
{
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	SetSizer(sizer);

	pGridSizeSpinner = new wxSpinCtrl(this, 10001);
	pTimeIntervalSpinner = new wxSpinCtrl(this, 10002);
	pLivingCellColorPicker = new wxColourPickerCtrl(this, 10003);
	pDeadCellColorPicker = new wxColourPickerCtrl(this, 10004);

	// Game settings that can be adjusted through the menu: grid size, timer interval, living and dead cell colors

	// Grid Size Settings
	wxBoxSizer* gridSizeSpinnerSizer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText* gridSizeSpinnerLabel = new wxStaticText(this, wxID_ANY, "Grid Size");
	gridSizeSpinnerLabel->SetMinSize(wxSize(50, 50));
	gridSizeSpinnerSizer->Add(gridSizeSpinnerLabel);
	gridSizeSpinnerSizer->Add(pGridSizeSpinner);
	sizer->Add(gridSizeSpinnerSizer);

	// Time Interval Settings
	wxBoxSizer* timeIntervalSpinnerSizer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText* timeIntervalSpinnerLabel = new wxStaticText(this, wxID_ANY, "Timer Interval");
	timeIntervalSpinnerLabel->SetMinSize(wxSize(50, 50));
	timeIntervalSpinnerSizer->Add(timeIntervalSpinnerLabel);
	timeIntervalSpinnerSizer->Add(pTimeIntervalSpinner);
	sizer->Add(timeIntervalSpinnerSizer);

	// Living Cell Color Picker Settings
	wxBoxSizer* livingCellColorWheelSizer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText* livingCellColorWheelLabel = new wxStaticText(this, wxID_ANY, "Living Cell Color");
	livingCellColorWheelLabel->SetMinSize(wxSize(50, 50));
	livingCellColorWheelSizer->Add(livingCellColorWheelLabel);
	livingCellColorWheelSizer->Add(pLivingCellColorPicker);
	sizer->Add(livingCellColorWheelSizer);

	// Dead Cell Color Picker Settings
	wxBoxSizer* deadCellColorWheelSizer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText* deadCellColorWheelLabel = new wxStaticText(this, wxID_ANY, "Dead Cell Color");
	deadCellColorWheelLabel->SetMinSize(wxSize(50, 50));
	deadCellColorWheelSizer->Add(deadCellColorWheelLabel);
	deadCellColorWheelSizer->Add(pDeadCellColorPicker);
	sizer->Add(deadCellColorWheelSizer);

	// Ok and Cancel Buttons for settings
	wxSizer* okAndCancelButton = CreateButtonSizer(wxOK | wxCANCEL);
	sizer->Add(okAndCancelButton);
}

void SettingsDialog::OnOkButtonClick(wxCommandEvent& event)
{
	pGameSettings->GridSize = pGridSizeSpinner->GetValue();
	pGameSettings->TimerInterval = pTimeIntervalSpinner->GetValue();
	pGameSettings->SetLivingCellColor(pLivingCellColorPicker->GetColour());
	pGameSettings->SetDeadCellColor(pDeadCellColorPicker->GetColour());

	EndModal(wxID_OK);
}

void SettingsDialog::OnCancelButtonClick(wxCommandEvent& event)
{
	EndModal(wxID_CANCEL);
}

void SettingsDialog::SetGameSettings(GameSettings& settings)
{
	pGameSettings = &settings;
}
