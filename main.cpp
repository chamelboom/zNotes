#include "application.h"
#include "mainwindow.h"
#include "settings.h"

int main(int argc, char **argv)
{
	zApplication app(argc, argv);
	settings.load();
	//if another copy is startes
	if(app.isRunning() && settings.getSingleInstance()) return !app.sendMessage("proton is our god!");
	app.setQuitOnLastWindowClosed(false);
	MainWindow w;
	app.setActivationWindow(&w);
	return app.exec();
}
