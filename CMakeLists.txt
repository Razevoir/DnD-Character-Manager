cmake_minimum_required(VERSION "3.13")

project("Application")

#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_compile_definitions(GLEW_STATIC)

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

add_subdirectory("Core")
add_subdirectory("Qt")
add_subdirectory("Win32")

add_dependencies("Qt" "Core")
add_dependencies("Win32" "Core")