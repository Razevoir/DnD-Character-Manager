#pragma once

#include <string>
#include <vector>

struct race
{
	std::string name;
	int bonus[6];
};
	
class raceList{
public:
	std::vector<race*> races;

//public:
	raceList();

	void addRace(std::string name, int strBonus, int dexBonus, int conBonus, int intBonus, int wisBonus, int chaBonus);
	void loadRaces(const char* fileName);

	~raceList();

};
