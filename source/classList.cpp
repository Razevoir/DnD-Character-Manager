#include "classList.h"
#include <string>
#include <vector>

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

classList::~classList()
{
	// Destructor
	for (unsigned int i=0; i<classes.size(); i++)
	{
		delete classes.at(i);
	}
}
