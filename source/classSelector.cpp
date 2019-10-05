#include "classSelector.h"
#include "classList.h"

classSelector::classSelector(classList* classes, QWidget* parent)
	: QWidget(parent)
{
	menu = new QComboBox;
	levelSpin = new QSpinBox;
	removeButton = new QPushButton("Remove");
	layout = new QHBoxLayout;

	for (unsigned int i = 0; i < classes->classes.size(); i++)
	{
		menu->addItem(/*tr*/(classes->classes.at(i)->name.c_str()));
	}

	layout->addWidget(menu);
	layout->addWidget(levelSpin);
	layout->addWidget(removeButton);

	void (QComboBox::* classSignal)(int) = & QComboBox::currentIndexChanged;
	connect(menu, classSignal, this, &classSelector::updateClass);

	void (QSpinBox::* levelSignal)(int) = & QSpinBox::valueChanged;
	connect(levelSpin, levelSignal, this, &classSelector::updateLevel);

	connect(removeButton, &QPushButton::clicked, this, &classSelector::removeClass);
}

void classSelector::updateClass(int newClassIndex)
{
	classIndex = newClassIndex;
	emit classChanged(classIndex, levelValue, index);
}

void classSelector::updateLevel(int newLevelValue)
{
	levelValue = newLevelValue;
	emit classChanged(classIndex, newLevelValue, index);
}

void classSelector::removeClass()
{
	emit removeButtonPressed(index);
}

classSelector::~classSelector()
{
	// Destroy the class
	delete menu;
	delete levelSpin;
	delete removeButton;
	delete layout;
}
