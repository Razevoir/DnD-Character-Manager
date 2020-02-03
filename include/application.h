#pragma once

#include <memory>

class application
{
public:
	static std::unique_ptr<application> create(int argc, char* argv[]);

	virtual ~application() = default;

	virtual void update() = 0;
};
