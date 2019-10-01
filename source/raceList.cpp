#include "raceList.h"
#include <fstream>

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

void raceList::loadRaces(const char* fileName)
{
	//TODO: return -1 if file fails to open and respond accordingly
	//TODO: change the format of the files sso race names can have spaces
	std::ifstream inFile(fileName);
	if (!inFile)
		return;
	std::string name;
	int strBonus;
	int dexBonus;
	int conBonus;
	int intBonus;
	int wisBonus;
	int chaBonus;
	while (!inFile.eof())
	{
		inFile >> name;
		inFile >> strBonus;
		inFile >> dexBonus;
		inFile >> conBonus;
		inFile >> intBonus;
		inFile >> wisBonus;
		inFile >> chaBonus;
		addRace(name, strBonus, dexBonus, conBonus, intBonus, wisBonus, chaBonus);
	}
}

raceList::~raceList()
{
	// Destructor
	for (unsigned int i=0; i<races.size(); i++)
	{
		delete races.at(i);
	}
}
