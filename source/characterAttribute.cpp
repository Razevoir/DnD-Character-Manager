#include "characterAttribute.h"
#include <cmath>
#include <QtGlobal>
#include <Qt>

characterAttribute::characterAttribute(std::string characterName, unsigned int index, QGridLayout* layout)
	: name(characterName),
	  index((ATTRIBUTES) index)
{
	// GUI elements
	nameLabel = new QLabel(name.c_str());
	modLabel = new QLabel;
	modLabel->setAlignment(Qt::AlignRight);
	baseSpin = new QSpinBox;
	raceLabel = new QLabel;
	raceLabel->setAlignment(Qt::AlignRight);
	levelSpin = new QSpinBox;
	miscSpin = new QSpinBox;
	tempSpin = new QSpinBox;

	layout->addWidget(nameLabel, index, 0);
	layout->addWidget(modLabel, index, 1);
	layout->addWidget(baseSpin, index, 2);
	layout->addWidget(raceLabel, index, 3);
	layout->addWidget(levelSpin, index, 4);
	layout->addWidget(miscSpin, index, 5);
	layout->addWidget(tempSpin, index, 6);

	void (QSpinBox::* mySignal)(int) = &QSpinBox::valueChanged;
	connect(baseSpin, mySignal, this, &characterAttribute::attributeChanged);
	connect(levelSpin, mySignal, this, &characterAttribute::attributeChanged);
	connect(miscSpin, mySignal, this, &characterAttribute::attributeChanged);
	connect(tempSpin, mySignal, this, &characterAttribute::attributeChanged);
}

void characterAttribute::attributeChanged()
{
	character* primaryCharacter = character::getInstance();

	primaryCharacter->setAttribute(index, baseSpin->value(), levelSpin->value(), miscSpin->value(), tempSpin->value());
}

void characterAttribute::update()
{

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
