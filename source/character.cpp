#include "character.h"
#include <cmath>
#include <algorithm>

character::character(raceList* allRaces, classList* allClasses, QLabel* wHPLabel)
{
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
	//hitPoints = classes->classes.at(currentClass)->hitDie+conMod+ceil((float(classes->classes.at(currentClass)->hitDie)+1.0)/2+conMod)*std::max(currentLevel-1, 0);
	hitPoints = 0;
	for (unsigned int i=0; i<knownClasses.size(); ++i)
	{
		hitPoints += classes->classes[knownClasses[i]]->hitDie;
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
