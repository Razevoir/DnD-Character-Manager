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
	charisma("Charisma", attributeLayout, 5),
	attributes{&strength, &dexterity, &constitution, &intelligence, &wisdom, &charisma}
{
	connect(&strength, &characterAttribute::modUpdated, this, &attributesWidget::updateStr);
	connect(&dexterity, &characterAttribute::modUpdated, this, &attributesWidget::updateDex);
	connect(&constitution, &characterAttribute::modUpdated, this, &attributesWidget::updateCon);
	connect(&intelligence, &characterAttribute::modUpdated, this, &attributesWidget::updateInt);
	connect(&wisdom, &characterAttribute::modUpdated, this, &attributesWidget::updateWis);
	connect(&charisma, &characterAttribute::modUpdated, this, &attributesWidget::updateCha);
}
		
attributesWidget::~attributesWidget()
{
	delete attributeLayout;
}

void attributesWidget::setRaceBonus(int index, int bonus)
{
	attributes[index]->raceBonus = bonus;
	attributes[index]->update();
	emit attributesChanged();
}

void attributesWidget::updateStr(int modVal)
{
	strMod = modVal;
	emit attributesChanged();
}

void attributesWidget::updateDex(int modVal)
{
	dexMod = modVal;
	emit attributesChanged();
}

void attributesWidget::updateCon(int modVal)
{
	conMod = modVal;
	emit attributesChanged();
}

void attributesWidget::updateInt(int modVal)
{
	intMod = modVal;
	emit attributesChanged();
}

void attributesWidget::updateWis(int modVal)
{
	wisMod = modVal;
	emit attributesChanged();
}

void attributesWidget::updateCha(int modVal)
{
	chaMod = modVal;
	emit attributesChanged();
}
