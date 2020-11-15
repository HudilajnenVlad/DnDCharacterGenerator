cmake_minimum_required(VERSION 3.15)
project(CharacterMaker)

set(CMAKE_CXX_STANDARD 14)
set(SOURCES warior.hpp supFunctions.hpp character.hpp ability.hpp race.hpp characterClass.hpp)
add_executable(CharacterMaker main.cpp ${SOURCES})