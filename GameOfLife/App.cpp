#include "App.h"

wxIMPLEMENT_APP(App);

App::App() {

}

App::~App() {

}

bool App::OnInit() {
	// Instantiate the window created in App.h and call Show on window
	window = new MainWindow();
	window->Show();
	return true;
}