#include "classSelector.h"
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QHBoxLayout>
#include "classList.h"

classSelector::classSelector(classList* classes)
{
	menu = new QComboBox();
	for (unsigned int i = 0; i < classes->classes.size(); i++)
	{
		menu->addItem(/*tr*/(classes->classes.at(i)->name.c_str()));
	}
	levelSpin = new QSpinBox();
	removeButton = new QPushButton("Remove");

	layout = new QHBoxLayout();
	layout->addWidget(menu);
	layout->addWidget(levelSpin);
	layout->addWidget(removeButton);
}

classSelector::~classSelector()
{
	// Destroy the class
}
