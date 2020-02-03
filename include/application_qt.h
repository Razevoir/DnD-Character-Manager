#pragma once

#include <QtWidgets>

#include "application.h"
#include "mainwidget.h"

class applicationQt : public application
{
public:
	applicationQt(int argc, char* argv[]);
	~applicationQt() override;

	virtual void run() override;

	virtual void update() override;
private:
	QApplication m_application;
	MainWidget m_mainWidget;
};
