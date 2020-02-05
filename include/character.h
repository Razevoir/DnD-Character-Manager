#pragma once

#include "raceList.h"
#include "classList.h"
#include "skillList.h"
#include <string>
#include <vector>
#include <array>
#include <cmath>

enum class ATTRIBUTES { STR = 0, DEX, CON, INT, WIS, CHA };

struct attribute
{
	std::string name;
	int base;
	int modifier;
	int ranks;
	int racialBonus;
	int misc;
	int temp;

	inline void setValue(int value)
	{
		base = value;
		modifier = floor((((float) base + (float) ranks + (float) racialBonus + (float) misc + (float) temp) - 10.0f)/2.0f);
	}
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

	void setAttribute(ATTRIBUTES att, int value);

	inline static character* getInstance() { return s_instance; };

private:
	int hitPoints;

	int currentRace;
	raceList races;

	classList classes;

	skillList skills;

	std::vector<int> knownClasses;
	std::vector<int> classLevels;

	std::array<attribute, 6> attributes;

	static character* s_instance;
};
