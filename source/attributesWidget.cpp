#include "characterAttribute.h"
#include "attributesWidget.h"
#include <QtWidgets>

attributesWidget::attributesWidget(QWidget* parent)
	: QWidget(parent),
	attributeLayout(new QGridLayout),
	strength("Strength", attributeLayout, 0),
	dexterity("Dexterity", attributeLayout, 1),
	constitution("Constitution", attributeLayout, 2),
	intelligence("Intelligence", attributeLayout, 3),
	wisdom("Wisdom", attributeLayout, 4),
	charisma("Charisma", attributeLayout, 5)
{
	//connect(strength.modUpdated to self.updateStr)
	connect(&strength, &characterAttribute::modUpdated, this, &attributesWidget::updateStr);
}
		
attributesWidget::~attributesWidget()
{
	delete attributeLayout;
}

void attributesWidget::updateStr(int modVal)
{
	strMod = modVal;
}

void attributesWidget::updateDex(int modVal)
{
	dexMod = modVal;
}

void attributesWidget::updateCon(int modVal)
{
	conMod = modVal;
}

void attributesWidget::updateInt(int modVal)
{
	intMod = modVal;
}

void attributesWidget::updateWis(int modVal)
{
	wisMod = modVal;
}

void attributesWidget::updateCha(int modVal)
{
	chaMod = modVal;
}
