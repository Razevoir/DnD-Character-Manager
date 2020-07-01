#ifndef _CLASS_SELECTOR_H_
#define _CLASS_SELECTOR_H_

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QHBoxLayout>
#include "classList.h"

class classSelector : public QWidget
{

	Q_OBJECT

public:
	QComboBox* menu;
	QSpinBox* levelSpin;
	QPushButton* removeButton;
	QHBoxLayout* layout;
	int index;
	int classIndex=0;
	int levelValue=0;

	classSelector(const classList& classes, QWidget* parent = 0);

	~classSelector();

signals:
	//void classChanged(int classIndex, int selectorIndex);
	//void levelChanged(int levelValue, int selectorIndex);
	void classChanged(int classIndex, int levelValue, int myIndex);
	void removeButtonPressed(int index);

public slots:
	void updateClass(int newClassIndex);
	void updateLevel(int newLevelValue);
	void removeClass();

};

#endif
