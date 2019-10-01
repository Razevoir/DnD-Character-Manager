#include "classList.h"
#include <fstream>

classList::classList()
{
	// Constructor
}

void classList::addClass(std::string name, int hitDie)
{
	characterClass* newClass;
	newClass = new characterClass;
	classes.push_back(newClass);
	
	newClass->name = name;
	newClass->hitDie = hitDie;
}

void classList::loadClasses(const char* fileName)
{
	std::ifstream inFile(fileName);
	//TODO: return -1 if file fails to open and respond accordingly
	//TODO: change the format of the file so class names can have spaces
	if (!inFile)
		return;
	std::string name;
	int hitDie;
	while (!inFile.eof())
	{
		inFile >> name;
		inFile >> hitDie;
		addClass(name, hitDie);
	}
}

classList::~classList()
{
	// Destructor
	for (unsigned int i=0; i<classes.size(); i++)
	{
		delete classes.at(i);
	}
}
