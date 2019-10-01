#include "characterAttribute.h"

characterAttribute::characterAttribute(std::string characterName, QGridLayout* layout, int row)
{
	name = characterName;
	baseVal = 10;
	raceBonus = 0;
	levelBonus = 0;
	miscBonus = 0;
	tempBonus = 0;

	// GUI elements
	modLabel = new QLabel(name.c_str());
	baseSpin = new QSpinBox;
	raceLabel = new QLabel;
	levelSpin = new QSpinBox;
	miscSpin = new QSpinBox;
	tempSpin = new QSpinBox;

	layout->addWidget(modLabel, row, 0);
	layout->addWidget(baseSpin, row, 1);
	layout->addWidget(raceLabel, row, 2);
	layout->addWidget(levelSpin, row, 3);
	layout->addWidget(miscSpin, row, 4);
	layout->addWidget(tempSpin, row, 5);
}

characterAttribute::~characterAttribute()
{
	delete modLabel;
	delete baseSpin;
	delete raceLabel;
	delete levelSpin;
	delete miscSpin;
	delete tempSpin;
}
