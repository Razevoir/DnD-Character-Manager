#ifndef CHARACTER_ATTRIBUTE_H
#define CHARACTER_ATTRIBUTE_H

#include <string>
#include <QtWidgets>
#include "raceList.h"
#include "character.h"
#include "raceList.h"

class characterAttribute : public QWidget
{
public:
	std::string name;
	int modVal;
	int baseVal;
	int raceBonus;
	int levelBonus;
	int miscBonus;
	int tempBonus;

	// GUI elements
	QLabel* nameLabel;
	QLabel* modLabel;
	QSpinBox* baseSpin;
	QLabel* raceLabel;
	QSpinBox* levelSpin;
	QSpinBox* miscSpin;
	QSpinBox* tempSpin;
	QHBoxLayout* layout;

	raceList* races;
	int currentRace = 0;

	character** linkedCharacter;

	explicit characterAttribute(std::string name, QGridLayout* layout, int row, character** lChar, raceList* allRaces, QWidget* parent = 0);

	void update();

	~characterAttribute();
};

#endif
