#include "mainwindow.h"


raa_mainwindow::raa_mainwindow(QMainWindow* parent) : QMainWindow(parent) {
	container = new primarycontainer(this);
	setCentralWidget(container);
}

raa_mainwindow::~raa_mainwindow() {
	delete container;
}
