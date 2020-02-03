#include "application_qt.h"
#include <iostream>

std::unique_ptr<application> application::create(int argc, char* argv[])
{
	return std::make_unique<applicationQt>(argc, argv);
}

applicationQt::applicationQt(int argc, char* argv[])
	: m_application(argc, argv)
{
	m_mainWidget.show();
}

applicationQt::~applicationQt()
{

}

void applicationQt::run()
{
	m_application.exec();
}

void applicationQt::update()
{

}
