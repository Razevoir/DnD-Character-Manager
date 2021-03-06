#include "selectorWidget.h"
#include "character.h"

selectorWidget::selectorWidget(const classList& classesList)
{
	classes = &classesList;

	backgroundLayout = new QVBoxLayout;

	addClass();
	selectors[0]->removeButton->setEnabled(false);

	backgroundWidget = new QWidget;
	backgroundWidget->setLayout(backgroundLayout);

	backgroundScroll = new QScrollArea;
	backgroundScroll->setWidget(backgroundWidget);
	backgroundScroll->setWidgetResizable(1);

	layout = new QVBoxLayout;
	layout->addWidget(backgroundScroll);

	addButton = new QPushButton("Add class");
	layout->addWidget(addButton);

	//connect(selectors[0], &classSelector::levelChanged, this, &selectorWidget::updateLevel);

	connect(addButton, &QPushButton::clicked, this, &selectorWidget::addClass);
}


selectorWidget::~selectorWidget()
{
	delete backgroundLayout;
	delete backgroundWidget;
	delete backgroundScroll;
	delete addButton;
	delete layout;
	for (auto i : selectors)
	{
		delete i;
	}
}

void selectorWidget::updateClass(int classIndex, int levelValue, int selectorIndex)
{
	emit classModified(classIndex, levelValue, selectorIndex);
}

void selectorWidget::addClass()
{
	selectors.push_back(new classSelector(character::getInstance()->getClasses()));
	backgroundLayout->addLayout(selectors.back()->layout);
	connect(selectors.back(), &classSelector::classChanged, this, &selectorWidget::updateClass);
	connect(selectors.back(), &classSelector::removeButtonPressed, this, &selectorWidget::removeClass);
	selectors.back()->index = selectors.size()-1;
	emit classAdded();
}

void selectorWidget::removeClass(int index)
{
	delete selectors[index];
	selectors.erase(selectors.begin()+index);
	for (unsigned int i=0; i<selectors.size(); ++i)
		selectors[i]->index = i;
}
