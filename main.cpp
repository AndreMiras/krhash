/*
 * Version: 0.1pre
 * Date:    12/03/2008
 * Licence: GPL
 *
 */
#include <QApplication>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
	//Q_INIT_RESOURCE(application);
	
	QApplication app(argc, argv);
	MainWindow win;
	win.show();

	return app.exec();
}


