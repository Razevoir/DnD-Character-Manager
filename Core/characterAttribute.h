#pragma once

#include <QObject>
#include <string>
#include <QtWidgets>
#include "raceList.h"
#include "character.h"
//#include "raceList.h"

class characterAttribute : public QObject
{

	Q_OBJECT

public:
	std::string name;
	ATTRIBUTES index;

	// GUI elements
	QLabel* nameLabel;
	QLabel* modLabel;
	QSpinBox* baseSpin;
	QLabel* raceLabel;
	QSpinBox* levelSpin;
	QSpinBox* miscSpin;
	QSpinBox* tempSpin;
	QHBoxLayout* layout;

	characterAttribute(std::string name, unsigned int index, QGridLayout* layout);

	void attributeChanged();
	void update();

	~characterAttribute();

signals:
	void modUpdated(int modVal);
};
