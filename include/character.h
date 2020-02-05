#pragma once

#include "raceList.h"
#include "classList.h"
#include "skillList.h"
#include <string>
#include <vector>

class character
{
public:

	character();
	~character();

	void update();
	void addClass();

	inline const raceList& getRaces() const { return races; };

	inline const classList& getClasses() const { return classes; };

	inline static const character* getInstance() { return s_instance; };

private:
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

	static character* s_instance;
};
