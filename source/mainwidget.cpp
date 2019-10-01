#include "mainwidget.h"
#include "raceList.h"
#include "characterAttribute.h"
#include "attributesWidget.h"
#include "selectorWidget.h"

// Constructor for main widget
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
	characterNameLabel = new QLabel(tr("Character Name:"));
	characterNameField = new QLineEdit();
	playerNameLabel = new QLabel(tr("Player Name:"));
	playerNameField = new QLineEdit();
	characterRaceLabel = new QLabel(tr("Race:"));
	characterRaceMenu = new QComboBox();
	races.addRace("Dwarf", 0, 0, 2, 0, 0, -2);
	races.addRace("Elf", 0, 2, -2, 0, 0, 0);
	races.addRace("Gnome", -2, 0, 2, 0, 0, 0);
	races.addRace("Half-elf", 0, 0, 0, 0, 0, 0);
	races.addRace("Half-orc", 2, 0, 0, -2, 0, -2);
	races.addRace("Halfling", -2, 2, 0, 0, 0, 0);
	races.addRace("Human", 0, 0, 0, 0, 0, 0);
	for (unsigned int i = 0; i < races.races.size(); i++)
	{
		characterRaceMenu->addItem(tr(races.races.at(i)->name.c_str()));
	}

	classes.addClass("Barbarian", 12);
	classes.addClass("Bard", 6);
	classes.addClass("Cleric", 8);
	classes.addClass("Druid", 8);
	classes.addClass("Fighter", 10);
	classes.addClass("Monk", 8);
	classes.addClass("Paladin", 10);
	classes.addClass("Psion", 4);
	classes.addClass("Psychic Warrior", 8);
	classes.addClass("Ranger", 8);
	classes.addClass("Rogue", 6);
	classes.addClass("Sorcerer", 4);
	classes.addClass("Soulknife", 10);
	classes.addClass("Wilder", 6);
	classes.addClass("Wizard", 4);

	QGridLayout *topLayout = new QGridLayout;
	topLayout->addWidget(characterNameLabel, 0, 0);
	topLayout->addWidget(characterNameField, 0, 1);
	topLayout->addWidget(playerNameLabel, 1, 0);
	topLayout->addWidget(playerNameField, 1, 1);
	topLayout->addWidget(characterRaceLabel, 2, 0);
	topLayout->addWidget(characterRaceMenu, 2, 1);

	selectorWidget* selector = new selectorWidget(&classes);

	attributesWidget* attributeLayout = new attributesWidget;

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addLayout(topLayout);
	mainLayout->addLayout(selector->layout);
	mainLayout->addLayout(attributeLayout->attributeLayout);

	setLayout(mainLayout);
	setWindowTitle(tr("Connecting buttons to processes.."));
}

// Destructor
MainWidget::~MainWidget()
{
   delete characterNameLabel;
   delete characterNameField;
   delete playerNameLabel;
   delete playerNameField;
}
