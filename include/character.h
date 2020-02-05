#pragma once

#include "raceList.h"
#include "classList.h"
#include "skillList.h"
#include <string>
#include <vector>

struct attribute
{
	std::string name;
	int value;
	int modifier;
	int ranks;
	int racialBonus;
	int misc;
	int temp;
};

class character
{
public:

	character();
	~character();

	void update();
	void addClass();

	inline const raceList& getRaceList() const { return races; };
	inline int getRace() { return currentRace; };
	inline void setRace(int index) { currentRace = index; };

	inline const classList& getClasses() const { return classes; };

	inline static character* getInstance() { return s_instance; };

private:
	int hitPoints;

	int currentRace;
	raceList races;

	classList classes;

	skillList skills;

	std::vector<int> knownClasses;
	std::vector<int> classLevels;

	attribute strength, dexterity, constitution, intelligence, wisdom, charisma;

	static character* s_instance;
};
