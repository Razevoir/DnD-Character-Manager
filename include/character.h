#pragma once

#include "raceList.h"
#include "classList.h"
#include "skillList.h"
#include <string>
#include <vector>

class character
{
public:
	int hitPoints;

	int currentRace;
	raceList races;

	classList classes;

	skillList skills;

	std::vector<int> knownClasses;
	std::vector<int> classLevels;

	int currentLevel;

	int strMod;
	int dexMod;
	int conMod;
	int intMod;
	int wisMod;
	int chaMod;

	character();
	void update();
	void addClass();
	~character();

	inline static const character* getInstance() { return s_instance; };

private:
	static character* s_instance;
};
