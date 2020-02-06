#ifndef CHARACTER_ATTRIBUTE_H
#define CHARACTER_ATTRIBUTE_H

#include <QObject>
#include <string>
#include <QtWidgets>
#include "raceList.h"
#include "character.h"
//#include "raceList.h"

class characterAttribute : public QObject
{

	Q_OBJECT

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

	characterAttribute(std::string name, unsigned int row, QGridLayout* layout, int baseValue = 10, int modValue = 0, int ranksValue = 0, int raceValue = 0, int miscValue = 0, int tempValue = 0);

	void update();

	~characterAttribute();

signals:
	void modUpdated(int modVal);
};

#endif
