#ifndef CHARACTER_H
#define CHARACTER_H

#include <QtWidgets>
#include "raceList.h"
#include "classList.h"
#include <string>

class character
{
public:
	int hitPoints;

	int currentRace;
	raceList* races;

	int currentClass;
	classList* classes;

	int strMod;
	int dexMod;
	int conMod;
	int intMod;
	int wisMod;
	int chaMod;

	QLabel* HPLabel;

	character(raceList* allRaces, classList* allClasses, QLabel* wHPLabel);
	void update();
	~character();
};

#endif
