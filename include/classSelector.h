#ifndef _CLASS_SELECTOR_H_
#define _CLASS_SELECTOR_H_

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QHBoxLayout>
#include "classList.h"

class classSelector
{
public:
	QComboBox* menu;
	QSpinBox* levelSpin;
	QPushButton* removeButton;
	QHBoxLayout* layout;

	classSelector(classList* classes);

	

	~classSelector();
};

#endif
