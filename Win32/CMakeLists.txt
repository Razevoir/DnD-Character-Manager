project("Win32")

add_executable("Win32" WIN32)
#add_library("Win32")

target_sources("Win32" PRIVATE
	application_win32.cpp
	application_win32.h)

target_link_libraries("Win32" "Core")

set(WIN32 TRUE)