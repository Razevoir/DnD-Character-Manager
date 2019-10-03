#ifndef SELECTOR_WIDGET_H
#define SELECTOR_WIDGET_H

#include <QtWidgets>
#include "selectorWidget.h"
#include "classSelector.h"

class selectorWidget : public QWidget
{
	Q_OBJECT

public:
	classSelector* selector;
	QVBoxLayout* backgroundLayout;
	QWidget* backgroundWidget;
	QScrollArea* backgroundScroll;
	QVBoxLayout* layout;
	QPushButton* addButton;

	selectorWidget(classList* classes);

	~selectorWidget();

signals:
	void classModified(int index);
	void levelModified(int index);

public slots:
	void updateClass(int index);
	void updateLevel(int index);
};

#endif
