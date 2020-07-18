project("Qt")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_executable(${PROJECT_NAME}
	application_qt.cpp
	application_qt.h
	attributesWidget.cpp
	attributesWidget.h
	characterAttribute.cpp
	characterAttribute.h
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

target_link_libraries(${PROJECT_NAME} "Core" Qt5::Core Qt5::Widgets)
