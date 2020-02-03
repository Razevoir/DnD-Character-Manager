#include "character.h"
#include <cmath>
#include <algorithm>

character* character::s_instance = nullptr;

character::character(raceList* allRaces, classList* allClasses, QLabel* wHPLabel)
{
	s_instance = this;
	
	hitPoints = 0;

	currentRace = 0;
	races = allRaces;

	currentClass = 0;
	classes = allClasses;

	addClass();

	currentLevel = 0;

	strMod = 0;
	dexMod = 0;
	conMod = 0;
	intMod = 0;
	wisMod = 0;
	chaMod = 0;

	HPLabel = wHPLabel;
}

void character::update()
{
	hitPoints = classes->classes[knownClasses[0]]->hitDie+conMod;
	for (unsigned int i=0; i<knownClasses.size(); ++i)
	{
		if (i != 0)
		{
			hitPoints += (std::ceil(float((classes->classes[knownClasses[i]]->hitDie)+1.0)/2.0)+conMod)*classLevels[i];
		}
		else
		{
			hitPoints += (std::ceil(float((classes->classes[knownClasses[i]]->hitDie)+1.0)/2.0)+conMod)*std::max(classLevels[i]-1, 0);
		}
	}
	HPLabel->setText(std::to_string(hitPoints).c_str());
}

void character::addClass()
{
	knownClasses.push_back(0);
	classLevels.push_back(0);
}

character::~character()
{

}
