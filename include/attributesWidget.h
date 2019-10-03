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

	int strMod;
	int dexMod;
	int conMod;
	int intMod;
	int wisMod;
	int chaMod;

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
