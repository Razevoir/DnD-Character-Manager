#pragma once

#include "application.h"

class applicationWin32 : public application
{
public:
	applicationWin32(int argc, char* argv[]);
	~applicationWin32() override;

	virtual void run() override;

	virtual void update() override;
private:
};
