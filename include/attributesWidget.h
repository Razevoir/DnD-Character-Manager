#ifndef ATTRIBUTES_WIDGET_H
#define ATTRIBUTES_WIDGET_H

#include <QtWidgets>
#include "characterAttribute.h"
#include "character.h"
#include "raceList.h"

class attributesWidget
{
public:
	QGridLayout* attributeLayout;
	characterAttribute strength;
	characterAttribute dexterity;
	characterAttribute constitution;
	characterAttribute intelligence;
	characterAttribute wisdom;
	characterAttribute charisma;

	attributesWidget(character** lChar, raceList* allRaces);
		
	~attributesWidget();
};

#endif
