#include "characterAttribute.h"

characterAttribute::characterAttribute(std::string characterName)
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
	layout = new QHBoxLayout;

	layout->addWidget(modLabel);
	layout->addWidget(baseSpin);
	layout->addWidget(raceLabel);
	layout->addWidget(levelSpin);
	layout->addWidget(miscSpin);
	layout->addWidget(tempSpin);
}

characterAttribute::~characterAttribute()
{
	delete modLabel;
	delete baseSpin;
	delete raceLabel;
	delete levelSpin;
	delete miscSpin;
	delete tempSpin;
	delete layout;
}
