#pragma once

#include <QWidget>
#include <QtCharts>
#include <QChartView>
#include <QTimer>


QT_CHARTS_USE_NAMESPACE

class testwidget : public QWidget {
	Q_OBJECT

	public: 
		explicit testwidget(QWidget* parent=0);
		~testwidget();

	private slots:
		void printToConsole();	
		void clearConsole();
		void reset_view();
		void addData();
		void test();

	private:
		QPushButton* button;
		QPushButton* clear_button;
		QPushButton* reset_view_button;
		QTextBrowser* browser;
		QLineEdit* input;
		QChartView* chartView;
		QChart* chart;
		QLineSeries* series;
		QTimer* timer;

		void saveGraph(QString);
		void openImage(QString);
};
