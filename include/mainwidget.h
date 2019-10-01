#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include "raceList.h"
#include "classList.h"
#include "classSelector.h"
#include "character.h"

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

private:
	QLabel* characterNameLabel;
	QLineEdit* characterNameField;
	QLabel* playerNameLabel;
	QLineEdit* playerNameField;
	QLabel* characterRaceLabel;
	QComboBox* characterRaceMenu;
	raceList races;
	classList classes;
	classSelector* selector;
	character* primaryCharacter;
};

#endif // MAINWIDGET_H
