#include "skillList.h"
#include <fstream>
#include <iostream>

skillList::skillList()
{
	// Constructor
}

void skillList::addSkill(std::string name, int ability)
{
	skill* newSkill;
	newSkill = new skill;
	skills.push_back(newSkill);
	
	newSkill->name = name;
	newSkill->baseAbility = ability;
}

void skillList::loadSkills(const char* fileName)
{
	std::ifstream inFile(fileName);
	//TODO: return -1 if file fails to open and respond accordingly
	//TODO: change the format of the file so class names can have spaces
	if (!inFile)
		return;
	std::string name;
	int ability;
	while (!inFile.eof())
	{
		inFile >> name;
		inFile >> ability;
		addSkill(name, ability);
		std::cout << name << "\t" << ability << std::endl;
	}
}

skillList::~skillList()
{
	// Destructor
	for (unsigned int i=0; i<skills.size(); i++)
	{
		delete skills.at(i);
	}
}
