#ifndef CHARACTER_SKILL_H
#define CHARACTER_SKILL_H

#include <QObject>
#include <string>
#include <QtWidgets>
#include "skillList.h"
#include "character.h"

class characterSkill : public QObject
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

	//raceList* races;
	//int currentRace = 0;

	character** linkedCharacter;

	/*explicit*/ characterSkill(std::string name, QGridLayout* layout, int row);

	void update();

	~characterSkill();

signals:
	void modUpdated(int modVal);
};

#endif
