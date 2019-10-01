#include "characterAttribute.h"
#include "attributesWidget.h"
#include <QtWidgets>

QGridLayout* attributeLayout;

attributesWidget::attributesWidget()
	: attributeLayout(new QGridLayout),
	strength("Strength", attributeLayout, 0),
	dexterity("Dexterity", attributeLayout, 1),
	constitution("Constitution", attributeLayout, 2),
	intelligence("Intelligence", attributeLayout, 3),
	wisdom("Wisdom", attributeLayout, 4),
	charisma("Charisma", attributeLayout, 5)
{

}
		
attributesWidget::~attributesWidget()
{
	delete attributeLayout;
}
