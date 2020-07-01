#include "characterSkill.h"
#include "skillsWidget.h"
#include <QtWidgets>

skillsWidget::skillsWidget(const skillList& allSkills, QWidget* parent)
	: QWidget(parent),
	skillsLayout(new QGridLayout)
	//strength("Strength", attributeLayout, 0),
	//attributes{&strength, &dexterity, &constitution, &intelligence, &wisdom, &charisma}
{
	characterSkill* newSkill;
	for (unsigned int i=0; i<allSkills.skills.size(); ++i)
	{
		newSkill = new characterSkill(allSkills.skills.at(i)->name, skillsLayout, i);
		skills.push_back(newSkill);
	}
	backgroundWidget = new QWidget;
	backgroundWidget->setLayout(skillsLayout);
	backgroundScroll = new QScrollArea;
	backgroundScroll->setWidget(backgroundWidget);
	//connect(&strength, &characterAttribute::modUpdated, this, &attributesWidget::updateStr);
}
		
skillsWidget::~skillsWidget()
{
	delete skillsLayout;
	delete backgroundWidget;
	delete backgroundScroll;
}

/*void attributesWidget::setRaceBonus(int index, int bonus)
{
	skills[index]->raceBonus = bonus;
	skills[index]->update();
	emit attributesChanged();
}*/

/*void skillsWidget::updateStr(int modVal)
{
	strMod = modVal;
	emit attributesChanged();
}*/
