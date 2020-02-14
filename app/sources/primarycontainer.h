#include <QWidget>

#include <QGridLayout>
#include <QPushButton>
#include <QSplitter>
#include <QLabel>

#include "testwidget.h"

class primarycontainer: public QWidget {
	Q_OBJECT

	public:
		explicit primarycontainer(QWidget* parent = 0);
		~primarycontainer();
		void identify();
		
	public slots:
		void test_echo();


	private:
		QGridLayout* mainlayout;
		QSplitter* top_splitter;
		QPushButton* button;
		QLabel* label;
		testwidget* tester;
};
