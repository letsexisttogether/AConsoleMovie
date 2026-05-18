cmake_minimum_required(VERSION 3.30)

set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_STANDARD 23)

project(AConsoleMovie LANGUAGES CXX VERSION 1.0)

add_subdirectory(Source)
add_subdirectory(Dependencies)

option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
	enable_testing()
	add_subdirectory(Test)
endif()
