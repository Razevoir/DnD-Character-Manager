#include "character.h"

character::character(raceList* allRaces, classList* allClasses, QLabel* wHPLabel)
{
	hitPoints = 0;

	currentRace = 0;
	races = allRaces;

	currentClass = 0;
	classes = allClasses;

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
	hitPoints = classes->classes.at(currentClass)->hitDie+conMod;
	HPLabel->setText(std::to_string(hitPoints).c_str());
}

character::~character()
{

}
