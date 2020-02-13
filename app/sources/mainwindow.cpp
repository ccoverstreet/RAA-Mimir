#include "mainwindow.h"

#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QMenuBar>


raa_mainwindow::raa_mainwindow(QMainWindow* parent) : QMainWindow(parent) {
	QAction* quit = new QAction("&Quit", this);
	quit->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));

	QMenu* file_menu = menuBar()->addMenu("&File");
	file_menu->addAction(quit);

	connect(quit, &QAction::triggered, qApp, QApplication::quit);

	container = new primarycontainer(this);
	container->setStyleSheet("background-color: #ffffff");
	setCentralWidget(container);
}

raa_mainwindow::~raa_mainwindow() {
	delete container;
}
