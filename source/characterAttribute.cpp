#include "characterAttribute.h"
#include <cmath>
#include <QtGlobal>

characterAttribute::characterAttribute(std::string characterName, QGridLayout* layout, int row)
{
	name = characterName;
	modVal = 0;
	baseVal = 10;
	raceBonus = 0;
	levelBonus = 0;
	miscBonus = 0;
	tempBonus = 0;

	// GUI elements
	nameLabel = new QLabel(name.c_str());
	modLabel = new QLabel;
	baseSpin = new QSpinBox;
	raceLabel = new QLabel;
	levelSpin = new QSpinBox;
	miscSpin = new QSpinBox;
	tempSpin = new QSpinBox;

	layout->addWidget(nameLabel, row, 0);
	layout->addWidget(modLabel, row, 1);
	layout->addWidget(baseSpin, row, 2);
	layout->addWidget(raceLabel, row, 3);
	layout->addWidget(levelSpin, row, 4);
	layout->addWidget(miscSpin, row, 5);
	layout->addWidget(tempSpin, row, 6);

	void (QSpinBox::* mySignal)(int) = &QSpinBox::valueChanged;
	connect(baseSpin, mySignal, this, &characterAttribute::update);
	connect(levelSpin, mySignal, this, &characterAttribute::update);
	connect(miscSpin, mySignal, this, &characterAttribute::update);
	connect(tempSpin, mySignal, this, &characterAttribute::update);
}

void characterAttribute::update()
{
	baseVal = baseSpin->value();
	raceBonus = 0;//races->races.at(currentRace)->conBonus;
	levelBonus = levelSpin->value();
	miscBonus = miscSpin->value();
	tempBonus = tempSpin->value();
	modVal = floor(((baseVal+raceBonus+levelBonus+miscBonus+tempBonus)-10)/2);

	raceLabel->setText(std::to_string(raceBonus).c_str());
	modLabel->setText(std::to_string(modVal).c_str());

	//(*linkedCharacter)->conMod = modVal;
	//(*linkedCharacter)->update();
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
