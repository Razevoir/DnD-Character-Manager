#include "application_qt.h"

int main(int argc, char* argv[])
{
	{
		std::unique_ptr<application> app = application::create(argc, argv);

		app->run();
	}

	return 0;
}
