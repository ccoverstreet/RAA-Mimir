// RAA-Mimir: mainwindow.h
// Cale Overstreet
// February 12th, 2020
// This is the primary widget that is opened when the Qt program starts. Acts as a parent for all other widgets

#pragma once

#include <QMainWindow>

#include "primarycontainer.h"

class raa_mainwindow : public QMainWindow {
	Q_OBJECT

	public:
		explicit raa_mainwindow(QMainWindow* parent = 0);
		~raa_mainwindow();

	private:
		primarycontainer* container;
};
