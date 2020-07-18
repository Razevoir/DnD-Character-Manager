project("Core")

add_library("Core")

target_include_directories("Core" PUBLIC "${PROJECT_SOURCE_DIR}") #TODO: Update this when you restructure the folders

target_sources("Core" PUBLIC
	application.h
	character.cpp
	character.h
	classList.cpp
	classList.h
	raceList.cpp
	raceList.h
	skillList.cpp
	skillList.h)
