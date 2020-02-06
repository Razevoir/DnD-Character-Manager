#include "character.h"
#include <cmath>
#include <algorithm>

character* character::s_instance = nullptr;

character::character()
	: attributes( {
		attribute({"Strength", 10, 0, 0, 0, 0, 0}),
		attribute({"Dexterity", 10, 0, 0, 0, 0, 0}),
		attribute({"Constitution", 10, 0, 0, 0, 0, 0}),
		attribute({"Intelligence", 10, 0, 0, 0, 0, 0}),
		attribute({"Wisdom", 10, 0, 0, 0, 0, 0}),
		attribute({"Charisma", 10, 0, 0, 0, 0, 0})
	})

{
	s_instance = this;

	hitPoints = 0;

	currentRace = 0;
	races.loadRaces("raceList");

	classes.loadClasses("classList");

	addClass();

}

void character::update()
{
	for (auto& att : attributes)
	{
		att.calculateModifier();
	}

	hitPoints = classes.classes[knownClasses[0]]->hitDie+attributes[(unsigned int) ATTRIBUTES::CON].modifier;
	for (unsigned int i=0; i<knownClasses.size(); ++i)
	{
		if (i != 0)
		{
			hitPoints += (std::ceil(float((classes.classes[knownClasses[i]]->hitDie)+1.0)/2.0)+attributes[(unsigned int) ATTRIBUTES::CON].modifier)*classLevels[i];
		}
		else
		{
			hitPoints += (std::ceil(float((classes.classes[knownClasses[i]]->hitDie)+1.0)/2.0)+attributes[(unsigned int) ATTRIBUTES::CON].modifier)*std::max(classLevels[i]-1, 0);
		}
	}
}

void character::addClass()
{
	knownClasses.push_back(0);
	classLevels.push_back(0);
}

void character::setAttribute(ATTRIBUTES att, int base, int ranks, int misc, int temp)
{
	unsigned int attInt = (unsigned int) att;
	attributes[attInt].base = base;
	attributes[attInt].ranks = ranks;
	attributes[attInt].misc = misc;
	attributes[attInt].temp = temp;

	update();
}

character::~character()
{

}
