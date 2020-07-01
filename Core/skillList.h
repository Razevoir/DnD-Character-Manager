#ifndef _SKILL_LIST_H
#define _SKILL_LIST_H

#include <string>
#include <vector>

class skillList{
public:
	struct skill
	{
		std::string name;
		int modifier;
		int baseAbility; // Should be a value from 0 to 5 representing which ability (str, dex, etc) the skill is based on
		int baseMod;
		int ranksMod;
		int synMod;
		int miscMod;
		int tempMod;
	};
	
	std::vector<skill*> skills;

//public:
	skillList();

	void addSkill(std::string name, int baseAbility);
	void loadSkills(const char* fileName);

	~skillList();

};

#endif
