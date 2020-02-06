#include "characterAttribute.h"
#include "attributesWidget.h"
#include <QtWidgets>
#include "character.h"

attributesWidget::attributesWidget(QWidget* parent)
	: QWidget(parent),
	attributeLayout(new QGridLayout)
{
	for (auto i : character::getInstance()->getAttributes())
	{
		attributes.push_back(std::make_unique<characterAttribute>(i.name, attributes.size(), attributeLayout, i.modifier, i.base, i.ranks, i.racialBonus, i.misc, i.temp));
	}
}
		
attributesWidget::~attributesWidget()
{
	delete attributeLayout;
}

void attributesWidget::updateAttribute(int modVal)
{
	character::getInstance()->setAttribute(ATTRIBUTES::STR, modVal);
	emit attributesChanged();
}
