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

	QGridLayout *topLayout = new QGridLayout;
	topLayout->addWidget(characterNameLabel, 0, 0);
	topLayout->addWidget(characterNameField, 0, 1);
	topLayout->addWidget(playerNameLabel, 1, 0);
	topLayout->addWidget(playerNameField, 1, 1);
	topLayout->addWidget(characterRaceLabel, 2, 0);
	topLayout->addWidget(characterRaceMenu, 2, 1);

	classes.loadClasses("classList");
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
   delete characterRaceLabel;
   delete characterRaceMenu;
}
