#ifndef CHARACTER_ATTRIBUTE_H
#define CHARACTER_ATTRIBUTE_H

#include <string>
#include <QtWidgets>

class characterAttribute
{
public:
	std::string name;
	int baseVal;
	int raceBonus;
	int levelBonus;
	int miscBonus;
	int tempBonus;

	// GUI elements
	QLabel* modLabel;
	QSpinBox* baseSpin;
	QLabel* raceLabel;
	QSpinBox* levelSpin;
	QSpinBox* miscSpin;
	QSpinBox* tempSpin;
	QHBoxLayout* layout;

	characterAttribute(std::string name);

	~characterAttribute();
};

#endif
