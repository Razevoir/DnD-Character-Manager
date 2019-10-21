#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include "raceList.h"
#include "classList.h"
#include "skillList.h"
#include "classSelector.h"
#include "character.h"
#include "attributesWidget.h"

class QPushButton;
class QTextBrowser;

// This is the declaration of our MainWidget class
// The definition/implementation is in mainwidget.cpp
class MainWidget : public QWidget
{
	Q_OBJECT

public:
	explicit MainWidget(QWidget *parent = 0); //Constructor
	~MainWidget(); // Destructor

public slots:
	void updateAttributes();
	void updateRace(int index);
	void updateClass(int classIndex, int levelValue, int selectorIndex);
	//void updateLevel(int index);
	void addClass();

private:
	QLabel* characterNameLabel;
	QLineEdit* characterNameField;
	QLabel* playerNameLabel;
	QLineEdit* playerNameField;
	QLabel* characterRaceLabel;
	QComboBox* characterRaceMenu;
	attributesWidget* attributeLayout;
	raceList races;
	classList classes;
	skillList skills;
	classSelector* selector;
	character* primaryCharacter;
};

#endif // MAINWIDGET_H
