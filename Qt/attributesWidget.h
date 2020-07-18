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

	attributesWidget(QWidget* parent = 0);
	virtual ~attributesWidget();

	virtual void update();

public slots:
	//void updateAttribute(ATTRIBUTES att, int modVal);

signals:
	void attributesChanged();
};
