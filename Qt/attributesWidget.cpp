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
		attributes.push_back(std::make_unique<characterAttribute>(i.name, attributes.size(), attributeLayout));
	}
}
		
attributesWidget::~attributesWidget()
{
	delete attributeLayout;
}

void attributesWidget::update()
{
	for (auto& i : attributes)
	{
		i->update();
	}
}

/*void attributesWidget::updateAttribute(ATTRIBUTES att, int modVal)
{
	character::getInstance()->setAttribute(att, modVal);
	emit attributesChanged();
}*/
