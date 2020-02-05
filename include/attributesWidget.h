#ifndef ATTRIBUTES_WIDGET_H
#define ATTRIBUTES_WIDGET_H

#include <QObject>
#include <QtWidgets>
#include "characterAttribute.h"
#include "character.h"
//#include "raceList.h"

class attributesWidget : public QWidget
{

	Q_OBJECT

public:
	QGridLayout* attributeLayout;
	characterAttribute strength;
	characterAttribute dexterity;
	characterAttribute constitution;
	characterAttribute intelligence;
	characterAttribute wisdom;
	characterAttribute charisma;

	characterAttribute* attributes[6];

	inline void setRaceBonus(int att, int value) { attributes[att]->raceBonus = value; attributes[att]->update(); };

	attributesWidget(QWidget* parent = 0);
	~attributesWidget();

public slots:
	void updateStr(int modVal);
	void updateDex(int modVal);
	void updateCon(int modVal);
	void updateInt(int modVal);
	void updateWis(int modVal);
	void updateCha(int modVal);

signals:
	void attributesChanged();
};

#endif
