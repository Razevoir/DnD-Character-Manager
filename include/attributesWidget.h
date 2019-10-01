#ifndef ATTRIBUTES_WIDGET_H
#define ATTRIBUTES_WIDGET_H

#include <QtWidgets>
#include "characterAttribute.h"

class attributesWidget
{
public:
	QGridLayout* attributeLayout;
	characterAttribute strength;
	characterAttribute dexterity;
	characterAttribute constitution;
	characterAttribute intelligence;
	characterAttribute wisdom;
	characterAttribute charisma;

	attributesWidget();
		
	~attributesWidget();
};

#endif
