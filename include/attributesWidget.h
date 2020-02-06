#pragma once

#include <QObject>
#include <QtWidgets>
#include "characterAttribute.h"
#include "character.h"
#include <vector>
#include <memory>

class attributesWidget : public QWidget
{

	Q_OBJECT

public:
	QGridLayout* attributeLayout;
	std::vector<std::unique_ptr<characterAttribute>> attributes;

	inline void setRaceBonus(int att, int value) { attributes[att]->raceBonus = value; attributes[att]->update(); };

	attributesWidget(QWidget* parent = 0);
	~attributesWidget();

public slots:
	void updateAttribute(int modVal);

signals:
	void attributesChanged();
};
