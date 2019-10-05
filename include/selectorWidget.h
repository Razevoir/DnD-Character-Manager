#ifndef SELECTOR_WIDGET_H
#define SELECTOR_WIDGET_H

#include <QtWidgets>
#include <vector>
#include "selectorWidget.h"
#include "classSelector.h"

class selectorWidget : public QWidget
{
	Q_OBJECT

public:
	classList* classes;
	std::vector<classSelector*> selectors;
	QVBoxLayout* backgroundLayout;
	QWidget* backgroundWidget;
	QScrollArea* backgroundScroll;
	QVBoxLayout* layout;
	QPushButton* addButton;

	selectorWidget(classList* classes);

	~selectorWidget();

signals:
	void classModified(int classIndex, int levelValue, int selectorIndex);
	//void levelModified(int index);
	void classAdded();

public slots:
	void updateClass(int classIndex, int levelValue, int selectorIndex);
	//void updateLevel(int levelValue, int selectorIndex);
	void addClass();
	void removeClass(int index);
};

#endif
