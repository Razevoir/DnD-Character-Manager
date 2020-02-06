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

	unsigned int index;

	inline void calculateModifier()
	{
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
	void setRace(unsigned int index);

	inline const classList& getClasses() const { return classes; };

	inline const std::array<attribute, 6>& getAttributes() { return attributes; };
	void setAttribute(ATTRIBUTES att, int base, int ranks, int misc, int temp);
	inline const attribute& getAttribute(ATTRIBUTES att) const { return attributes[(unsigned int) att]; };

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
