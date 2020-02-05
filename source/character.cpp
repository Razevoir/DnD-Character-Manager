#include "character.h"
#include <cmath>
#include <algorithm>

character* character::s_instance = nullptr;

character::character()
{
	s_instance = this;

	hitPoints = 0;

	currentRace = 0;
	races.loadRaces("raceList");

	classes.loadClasses("classList");

	addClass();

	strength     = {"Strength", 10, 0, 0, 0, 0, 0};
	dexterity    = {"Dexterity", 10, 0, 0, 0, 0, 0};
	constitution = {"Constitution", 10, 0, 0, 0, 0, 0};
	intelligence = {"Intelligence", 10, 0, 0, 0, 0, 0};
	wisdom       = {"Wisdom", 10, 0, 0, 0, 0, 0};
	charisma     = {"Charisma", 10, 0, 0, 0, 0, 0};
}

void character::update()
{
	hitPoints = classes.classes[knownClasses[0]]->hitDie+constitution.modifier;
	for (unsigned int i=0; i<knownClasses.size(); ++i)
	{
		if (i != 0)
		{
			hitPoints += (std::ceil(float((classes.classes[knownClasses[i]]->hitDie)+1.0)/2.0)+constitution.modifier)*classLevels[i];
		}
		else
		{
			hitPoints += (std::ceil(float((classes.classes[knownClasses[i]]->hitDie)+1.0)/2.0)+constitution.modifier)*std::max(classLevels[i]-1, 0);
		}
	}
	//HPLabel->setText(std::to_string(hitPoints).c_str());
}

void character::addClass()
{
	knownClasses.push_back(0);
	classLevels.push_back(0);
}

void character::setAttribute(ATTRIBUTES att, int value)
{
	switch (att)
	{
		case ATTRIBUTES::STR:
		{
			strength.setValue(value);
			return;
		}
		case ATTRIBUTES::DEX:
		{
			dexterity.setValue(value);
			return;
		}
		case ATTRIBUTES::CON:
		{
			constitution.setValue(value);
			return;
		}
		case ATTRIBUTES::INT:
		{
			intelligence.setValue(value);
			return;
		}
		case ATTRIBUTES::WIS:
		{
			wisdom.setValue(value);
			return;
		}
		case ATTRIBUTES::CHA:
		{
			charisma.setValue(value);
			return;
		}
		default:
		{
			return;
		}
	}
}

character::~character()
{

}
