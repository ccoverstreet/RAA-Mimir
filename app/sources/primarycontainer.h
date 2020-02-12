#include <QWidget>

#include <QGridLayout>
#include <QPushButton>

class primarycontainer: public QWidget {
	Q_OBJECT

	public:
		explicit primarycontainer(QWidget* parent = 0);
		~primarycontainer();

	private:
		QPushButton* button;
		QGridLayout* mainlayout;
};
