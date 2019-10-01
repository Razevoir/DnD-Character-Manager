#include "characterAttribute.h"
#include "attributesWidget.h"
#include <QtWidgets>

QGridLayout* attributeLayout;

attributesWidget::attributesWidget(character** lChar, raceList* allRaces)
	: attributeLayout(new QGridLayout),
	strength("Strength", attributeLayout, 0, lChar, allRaces),
	dexterity("Dexterity", attributeLayout, 1, lChar, allRaces),
	constitution("Constitution", attributeLayout, 2, lChar, allRaces),
	intelligence("Intelligence", attributeLayout, 3, lChar, allRaces),
	wisdom("Wisdom", attributeLayout, 4, lChar, allRaces),
	charisma("Charisma", attributeLayout, 5, lChar, allRaces)
{

}
		
attributesWidget::~attributesWidget()
{
	delete attributeLayout;
}
