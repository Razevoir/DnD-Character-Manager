#ifndef _CLASS_LIST_H
#define _CLASS_LIST_H

#include <string>
#include <vector>

class classList
{
	struct characterClass
	{
		std::string name;
		int levelsTaken=0;
		int hitDie;
	};

public:
	std::vector<characterClass*> classes;

	classList();

	void addClass(std::string name, int hitDie);
	void loadClasses(const char* filename);

	~classList();
};

#endif
