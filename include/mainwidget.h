#pragma once

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>

#include "classSelector.h"
#include "character.h"
#include "attributesWidget.h"
#include "skillsWidget.h"

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
	//void updateAttributes();
	//void updateRace(int index);
	//void updateClass(int classIndex, int levelValue, int selectorIndex);
	//void updateLevel(int index);
	//void addClass();

private:
	QLabel* characterNameLabel;
	QLineEdit* characterNameField;
	QLabel* playerNameLabel;
	QLineEdit* playerNameField;
	QLabel* characterRaceLabel;
	QComboBox* characterRaceMenu;

	//attributesWidget* attributeLayout;
	//skillsWidget* skillsLayout;
	//classSelector* selector;
};
