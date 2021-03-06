#include "characterSkill.h"
#include <cmath>
#include <QtGlobal>
#include <Qt>

characterSkill::characterSkill(std::string skillName, QGridLayout* layout, int row)
{
	name = skillName;
	modVal = 0;
	baseVal = 10;
	raceBonus = 0;
	rankBonus = 0;
	miscBonus = 0;
	tempBonus = 0;

	// GUI elements
	nameLabel = new QLabel(name.c_str());
	modLabel = new QLabel;
	modLabel->setAlignment(Qt::AlignRight);
	baseSpin = new QSpinBox;
	raceLabel = new QLabel;
	raceLabel->setAlignment(Qt::AlignRight);
	rankSpin = new QSpinBox;
	miscSpin = new QSpinBox;
	tempSpin = new QSpinBox;

	layout->addWidget(nameLabel, row, 0);
	layout->addWidget(modLabel, row, 1);
	layout->addWidget(baseSpin, row, 2);
	layout->addWidget(raceLabel, row, 3);
	layout->addWidget(rankSpin, row, 4);
	layout->addWidget(miscSpin, row, 5);
	layout->addWidget(tempSpin, row, 6);

	//void (QSpinBox::* mySignal)(int) = &QSpinBox::valueChanged;
	//connect(baseSpin, mySignal, this, &characterAttribute::update);
	//connect(levelSpin, mySignal, this, &characterAttribute::update);
	//connect(miscSpin, mySignal, this, &characterAttribute::update);
	//connect(tempSpin, mySignal, this, &characterAttribute::update);
}

void characterSkill::update()
{
	baseVal = baseSpin->value();
	//raceBonus = 0;//races->races.at(currentRace)->conBonus;
	rankBonus = rankSpin->value();
	miscBonus = miscSpin->value();
	tempBonus = tempSpin->value();
	modVal = floor((float(baseVal+raceBonus+rankBonus+miscBonus+tempBonus)-10.0)/2.0);

	//raceLabel->setText(std::to_string(raceBonus).c_str());
	modLabel->setText(std::to_string(modVal).c_str());

	//emit modUpdated(modVal);
	//(*linkedCharacter)->conMod = modVal;
	//(*linkedCharacter)->update();
}

characterSkill::~characterSkill()
{
	delete modLabel;
	delete baseSpin;
	delete raceLabel;
	delete rankSpin;
	delete miscSpin;
	delete tempSpin;
}
