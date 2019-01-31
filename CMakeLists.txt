cmake_minimum_required( VERSION 3.11.0 )

MESSAGE(STATUS "CMAKE SYSTEM NAME: ${CMAKE_SYSTEM_NAME}")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules")

add_definitions(-DUSE_STANDARD_LOG)

include(buildfunctional)

set(table_lib_name Table)
set(table_core_name TableCore)
set(table_ser_lib_name TableSerialize)


add_subdirectory(libraries)

add_subdirectory(test1)


