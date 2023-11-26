cmake_minimum_required( VERSION 3.28 )

set (SOLUTION_NAME "Stack")
set (APP_NAME "Stack_mech")
set (TEST_APP_NAME "Test_Stack")

Project(${SOLUTION_NAME})
set (STD 20)

#App
file (GLOB SOURCES
    ./app/main.cpp
    ./app/source/*.cpp
    )

file (GLOB HEADERS
    ./app/include/*.h
    )

add_executable(${SOLUTION_NAME} ${SOURCES} ${HEADERS} )
target_include_directories( ${SOLUTION_NAME} PUBLIC "./app/include")
set_property(TARGET ${SOLUTION_NAME} PROPERTY CXX_STANDARD ${STD})