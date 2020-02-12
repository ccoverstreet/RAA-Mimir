#include <QtWidgets>
#include "testwidget.h"
#include <string>

testwidget::testwidget(QWidget* parent) : QWidget(parent) {

	// User Inputs
	button = new QPushButton(tr("Test"));
	clear_button = new QPushButton("Clear");
	input = new QLineEdit();
	reset_view_button = new QPushButton("Reset View");

	// User Inputs layout
	QHBoxLayout* input_layout = new QHBoxLayout();
	input_layout->addWidget(input);
	input_layout->addWidget(button);
	input_layout->addWidget(clear_button);
	input_layout->addWidget(reset_view_button);

~	browser = new QTextBrowser();
	browser->setStyleSheet("background-color: #2C2C2C; color: #f0f0f0; font-size: 18px");

	series = new QLineSeries();

	chart = new QChart();
	chart->setTitle("Random data controlled by terminal");
	chart->addSeries(series);
	chart->createDefaultAxes();

	chartView = new QChartView(chart);
	chartView->setRubberBand(QChartView::RectangleRubberBand);
	chartView->setRenderHint(QPainter::Antialiasing);

	QGridLayout* mainLayout = new QGridLayout;
	mainLayout->addWidget(browser, 0, 0);
	mainLayout->addLayout(input_layout, 1, 0, 1, 2);
	mainLayout->addWidget(chartView, 0, 1);

	setLayout(mainLayout);
	setWindowTitle(tr("Test Widget"));

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(addData()));

	connect(button, SIGNAL(released()), this, SLOT(test()));
	connect(clear_button, SIGNAL(released()), this, SLOT(clearConsole()));
	connect(reset_view_button, SIGNAL(released()), this, SLOT(reset_view()));
	connect(input, SIGNAL(returnPressed()), this, SLOT(printToConsole()));
}

testwidget::~testwidget() {
	delete button;
	delete browser;
	delete input;
	delete clear_button;
	delete series;
	delete chart;
	delete chartView;
	delete timer;
}

void testwidget::printToConsole() {
	QString input_text = input->text().trimmed();	
	QStringList split_input = input_text.split(" ");
	browser->append("<div style='color: #61ab86;'>[QT Practice]$</div> " + input_text);
	if (split_input.at(0) == "clear") {
		browser->clear();
		series->clear();
	} else if (split_input.at(0) == "exit") {
		qApp->exit();
	} else if (split_input.at(0) == "start") {
		timer->start(100);	
	} else if (split_input.at(0) == "stop") {
		timer->stop();
	} else if (split_input.at(0) == "help") {
		browser->append("\tstart\tStarts timer for plotting random values");
		browser->append("\tstop\tStops timer for plotting random values");
		browser->append("\thelp\tShows this information");
		browser->append("\tclear\tClears the graph and this text browser");
	} else if (split_input.at(0) == "save") {
		if (split_input.size() >= 2) {
			browser->append("Saving png of graph");
			saveGraph(split_input.at(1));
		} else {
			browser->append("<div style='color: #e17055;'>Error</div>: Insufficient arguments. Requires form \"save filenamenoextension\"");
		}
	} else if (split_input.at(0) == "open") {
		if (split_input.size() >= 2) {
			browser->append("Opening png of graph");
			openImage(split_input.at(1));
		} else {
			browser->append("<div style='color: #e17055;'>Error</div>: Insufficient arguments. Requires form \"open filenamenoextension\"");
		}
	} else {
		browser->append("<div style='color: #e17055;'>Error</div>: command not found");
	}

	input->clear();
}

void testwidget::clearConsole() {
	browser->clear();
}

void testwidget::addData() {
	qDebug("Added Data");
	series->append(rand() / double(RAND_MAX), rand() / double(RAND_MAX));
	chart->removeSeries(series);
	chart->addSeries(series);
	chart->createDefaultAxes();
}

void testwidget::saveGraph(QString filename) {
	QPixmap p = chartView->grab();
	p.save(filename, "PNG");
}

void testwidget::test() {
	QMessageBox::StandardButton reply = QMessageBox::question(this, tr("Test"), tr("Save Image?"), QMessageBox::Yes|QMessageBox::No);

	if (reply == QMessageBox::Yes) {
		qDebug("Yes");
	} else {
		qDebug("No");
	}
}

void testwidget::openImage(QString filename) {
	QLabel* opened_image = new QLabel(this);	
	opened_image->setWindowFlags(Qt::Window);
	QPixmap p = QPixmap(QApplication::applicationDirPath() + "/" + filename, 0, Qt::AutoColor);
	opened_image->setPixmap(p);
	opened_image->setGeometry(0, 0, p.width(), p.height());
	opened_image->show();
}

void testwidget::reset_view() {
	chart->zoomReset();
}
