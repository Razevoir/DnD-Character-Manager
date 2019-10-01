#include "raceList.h"
#include <string>
#include <vector>

raceList::raceList()
{
	// Constructor
}

void raceList::addRace(std::string name, int strBonus, int dexBonus, int conBonus, int intBonus, int wisBonus, int chaBonus)
{
	race* newRace;
	newRace = new race;
	races.push_back(newRace);
	
	newRace->name = name;
	newRace->strBonus = strBonus;
	newRace->dexBonus = dexBonus;
	newRace->conBonus = conBonus;
	newRace->intBonus = intBonus;
	newRace->wisBonus = wisBonus;
	newRace->chaBonus = chaBonus;
}

raceList::~raceList()
{
	// Destructor
	for (unsigned int i=0; i<races.size(); i++)
	{
		delete races.at(i);
	}
}
