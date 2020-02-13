#include <QWidget>

#include <QGridLayout>
#include <QPushButton>
#include <QSplitter>
#include <QLabel>

class primarycontainer: public QWidget {
	Q_OBJECT

	public:
		explicit primarycontainer(QWidget* parent = 0);
		~primarycontainer();
		
	public slots:
		void test_echo();


	private:
		QGridLayout* mainlayout;
		QSplitter* top_splitter;
		QPushButton* button;
		QLabel* label;
};
