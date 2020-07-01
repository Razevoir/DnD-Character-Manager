project("Qt")

add_library("Qt")

target_sources("Qt" PUBLIC
	application_qt.cpp
	application_qt.h
	attributesWidget.cpp
	attributesWidget.h
	characterSkill.cpp
	characterSkill.h
	classSelector.cpp
	classSelector.h
	mainwidget.cpp
	mainwidget.h
	selectorWidget.cpp
	selectorWidget.h
	skillsWidget.cpp
	skillsWidget.h)