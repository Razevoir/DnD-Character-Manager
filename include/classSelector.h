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

	classSelector(classList* classes, QWidget* parent = 0);

	~classSelector();

signals:
	void classChanged(int index);
	void levelChanged(int index);
	void removeButtonPressed(int index);

public slots:
	void updateClass(int index);
	void updateLevel(int index);
	void removeClass();

};

#endif
