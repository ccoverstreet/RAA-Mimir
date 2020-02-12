#include "primarycontainer.h"

primarycontainer::primarycontainer(QWidget* parent) : QWidget(parent) {
	button = new QPushButton(tr("RAA Mimir"));

	mainlayout = new QGridLayout();

	mainlayout->addWidget(button, 0, 0);

	setLayout(mainlayout);
}

primarycontainer::~primarycontainer() {
	delete button;
	delete mainlayout;
}
