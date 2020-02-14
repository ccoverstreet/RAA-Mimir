#include "testwidget.h"

testwidget::testwidget(QWidget* parent) : QWidget(parent) {
	grid = new QGridLayout();

	button = new QPushButton(tr("Test Widget"), this);
	connect(button, SIGNAL(clicked()), this, SLOT(sendsignal()));

	grid->addWidget(button);

	setLayout(grid);
}

testwidget::~testwidget() {
	delete button;
	delete grid;
}

void testwidget::sendsignal() {
	qDebug("Sending signal from test widget");
	emit mysignal();
}
