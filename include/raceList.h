#ifndef _RACE_LIST_H
#define _RACE_LIST_H

#include <string>
#include <vector>

class raceList{
public:
	struct race
	{
		std::string name;
		int strBonus;
		int dexBonus;
		int conBonus;
		int intBonus;
		int wisBonus;
		int chaBonus;
	};
	
	std::vector<race*> races;

//public:
	raceList();

	void addRace(std::string name, int strBonus, int dexBonus, int conBonus, int intBonus, int wisBonus, int chaBonus);
	void loadRaces(const char* fileName);

	~raceList();

};

#endif
