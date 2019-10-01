#ifndef SELECTOR_WIDGET_H
#define SELECTOR_WIDGET_H

#include <QtWidgets>
#include "selectorWidget.h"
#include "classSelector.h"

class selectorWidget
{
public:
	classSelector* selector;
	QVBoxLayout* backgroundLayout;
	QWidget* backgroundWidget;
	QScrollArea* backgroundScroll;
	QVBoxLayout* layout;
	QPushButton* addButton;

	selectorWidget(classList* classes);

	~selectorWidget();
};

#endif
