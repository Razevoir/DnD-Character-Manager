#include "selectorWidget.h"

selectorWidget::selectorWidget(classList* classes)
{
	selector = new classSelector(classes);

	backgroundLayout = new QVBoxLayout;
	backgroundLayout->addLayout(selector->layout);

	backgroundWidget = new QWidget;
	backgroundWidget->setLayout(backgroundLayout);

	backgroundScroll = new QScrollArea;
	backgroundScroll->setWidget(backgroundWidget);

	layout = new QVBoxLayout;
	layout->addWidget(backgroundScroll);

	addButton = new QPushButton("Add class");
	layout->addWidget(addButton);
}


selectorWidget::~selectorWidget()
{
	delete backgroundLayout;
	delete backgroundWidget;
	delete backgroundScroll;
	delete addButton;
	delete layout;
	delete selector;
}



