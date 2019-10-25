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
	races.loadRaces("raceList");
	for (unsigned int i = 0; i < races.races.size(); i++)
	{
		characterRaceMenu->addItem(tr(races.races.at(i)->name.c_str()));
	}
	void (QComboBox::* raceSignal)(int) = & QComboBox::currentIndexChanged;
	connect(characterRaceMenu, raceSignal, this, &MainWidget::updateRace);

	QGridLayout* topLayout = new QGridLayout;
	topLayout->addWidget(characterNameLabel, 0, 0);
	topLayout->addWidget(characterNameField, 0, 1);
	topLayout->addWidget(playerNameLabel, 1, 0);
	topLayout->addWidget(playerNameField, 1, 1);
	topLayout->addWidget(characterRaceLabel, 2, 0);
	topLayout->addWidget(characterRaceMenu, 2, 1);

	QHBoxLayout* healthLayout = new QHBoxLayout;
	QLabel* HPNameLabel = new QLabel("Hit points:");
	QLabel* HPLabel = new QLabel;
	healthLayout->addWidget(HPNameLabel);
	healthLayout->addWidget(HPLabel);

	classes.loadClasses("classList");
	selectorWidget* selector = new selectorWidget(&classes);

	connect(selector, &selectorWidget::classModified, this, &MainWidget::updateClass);
	connect(selector, &selectorWidget::classAdded, this, &MainWidget::addClass);

	attributeLayout = new attributesWidget();

	connect(attributeLayout, &attributesWidget::attributesChanged, this, &MainWidget::updateAttributes);

	skills.loadSkills("skillList");

	skillsLayout = new skillsWidget(&skills);

	primaryCharacter = new character(&races, &classes, HPLabel);

	attributeLayout->constitution.update();

	QVBoxLayout* statsLayout = new QVBoxLayout;
	statsLayout->addLayout(topLayout);
	statsLayout->addLayout(healthLayout);
	statsLayout->addLayout(selector->layout);
	statsLayout->addLayout(attributeLayout->attributeLayout);

	QHBoxLayout* mainLayout = new QHBoxLayout;
	mainLayout->addLayout(statsLayout);
	mainLayout->addWidget(skillsLayout->backgroundScroll);

	setLayout(mainLayout);
	setWindowTitle(tr("Dungeons and Dragons Character Manager"));
}

// Destructor
MainWidget::~MainWidget()
{
   delete characterNameLabel;
   delete characterNameField;
   delete playerNameLabel;
   delete playerNameField;
   delete characterRaceLabel;
   delete characterRaceMenu;
   delete attributeLayout;
}

void MainWidget::updateAttributes()
{
	primaryCharacter->conMod = attributeLayout->conMod;
	primaryCharacter->update();
}

void MainWidget::updateRace(int index)
{
	attributeLayout->setRaceBonus(0, races.races.at(index)->strBonus);
	attributeLayout->setRaceBonus(1, races.races.at(index)->dexBonus);
	attributeLayout->setRaceBonus(2, races.races.at(index)->conBonus);
	attributeLayout->setRaceBonus(3, races.races.at(index)->intBonus);
	attributeLayout->setRaceBonus(4, races.races.at(index)->wisBonus);
	attributeLayout->setRaceBonus(5, races.races.at(index)->chaBonus);
}

void MainWidget::updateClass(int classIndex, int levelValue, int selectorIndex)
{
	primaryCharacter->knownClasses[selectorIndex] = classIndex;
	primaryCharacter->classLevels[selectorIndex] = levelValue;
	primaryCharacter->update();
}

void MainWidget::addClass()
{
	primaryCharacter->addClass();
}
