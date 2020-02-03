#include "application_qt.h"

std::unique_ptr<application> application::create(int argc, char* argv[])
{
	return std::make_unique<applicationQt>(argc, argv);
}

applicationQt::applicationQt(int argc, char* argv[])
{

}

void applicationQt::update()
{

}
