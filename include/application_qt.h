#pragma once

#include "application.h"

class applicationQt : public application
{
public:
	applicationQt(int argc, char* argv[]);

	virtual void update() override;
};
