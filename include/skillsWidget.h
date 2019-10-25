#ifndef SKILLS_WIDGET_H
#define SKILLS_WIDGET_H

#include <QObject>
#include <QtWidgets>
#include "characterSkill.h"
#include "character.h"
#include "skillList.h"
#include "characterSkill.h"
#include <vector>

class skillsWidget : public QWidget
{

	Q_OBJECT

public:
	QGridLayout* skillsLayout;
	QWidget* backgroundWidget;
	QScrollArea* backgroundScroll;

	std::vector<characterSkill*> skills;

	std::vector<int> modifiers;

	skillsWidget(skillList* allSkills, QWidget* parent = 0);

	//void setRaceBonus(int skillIndex, int bonus);
		
	~skillsWidget();

public slots:
	//void updateSkill(int index, int modVal);

signals:
	//void skillsChanged(int index);
};

#endif
