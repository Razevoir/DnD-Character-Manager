#include "characterAttribute.h"
#include "attributesWidget.h"
#include <QtWidgets>

QGridLayout* attributeLayout;

attributesWidget::attributesWidget()
	: strength("Strength"), dexterity("Dexterity"), constitution("Constitution"), intelligence("Intelligence"), wisdom("Wisdom"), charisma("Charisma")
{
	attributeLayout = new QGridLayout;
	attributeLayout->addLayout(strength.layout, 1, 1);
	attributeLayout->addLayout(dexterity.layout, 2, 1);
	attributeLayout->addLayout(constitution.layout, 3, 1);
	attributeLayout->addLayout(intelligence.layout, 4, 1);
	attributeLayout->addLayout(wisdom.layout, 5, 1);
	attributeLayout->addLayout(charisma.layout, 6, 1);
	
}
		
attributesWidget::~attributesWidget()
{
	delete attributeLayout;
}
