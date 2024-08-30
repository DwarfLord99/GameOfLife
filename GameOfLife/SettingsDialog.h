#pragma once
#include "wx/wx.h"
#include "wx/spinctrl.h"
#include "wx/clrpicker.h"
#include "GameSettings.h"
#include "MainWindow.h"

class SettingsDialog :
    public wxDialog
{
private:
    
public:
    wxSpinCtrl* pGridSizeSpinner = nullptr;
    wxSpinCtrl* pTimeIntervalSpinner = nullptr;
    wxColourPickerCtrl* pLivingCellColorPicker = nullptr;
    wxColourPickerCtrl* pDeadCellColorPicker = nullptr;

    GameSettings* pGameSettings = nullptr;

    SettingsDialog(wxWindow* parent);

    void OnOkButtonClick(wxCommandEvent& event);
    void OnCancelButtonClick(wxCommandEvent& event);
    void SetGameSettings(GameSettings& settings);

    wxDECLARE_EVENT_TABLE();
};

