#include "primarycontainer.h"

primarycontainer::primarycontainer(QWidget* parent) : QWidget(parent) {
	mainlayout = new QGridLayout();

	button = new QPushButton(tr("RAA Mimir"), this);
	connect(button, SIGNAL(clicked()), this, SLOT(test_echo()));

	tester = new testwidget(this);
	connect(tester, SIGNAL(mysignal()), this, SLOT(test_echo()));

	label = new QLabel(tr("Hello"));

	top_splitter = new QSplitter();
	top_splitter->setStyleSheet("QSplitter::handle {border: 1px outset grey}");

	top_splitter->addWidget(button);
	top_splitter->addWidget(label);
	top_splitter->addWidget(tester);

	mainlayout->addWidget(top_splitter);

	// Setting margins to 0
	mainlayout->setContentsMargins(0, 0, 0, 0);

	setLayout(mainlayout);
}

primarycontainer::~primarycontainer() {
	delete label;
	delete button;
	delete tester;
	delete top_splitter;
	delete mainlayout;
}

void primarycontainer::identify() {
	qDebug("Primary Container");
}

void primarycontainer::test_echo() {
	qDebug("Hello RAA");
}
