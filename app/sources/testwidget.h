#include <QWidget>
#include <QGridLayout>
#include <QPushButton>


class testwidget : public QWidget {
	Q_OBJECT

	public:
		explicit testwidget(QWidget* parent = 0);
		~testwidget();

	signals:
		void mysignal();

	private slots:
		void sendsignal();

	private:
		QPushButton* button;
		QGridLayout* grid;
};
