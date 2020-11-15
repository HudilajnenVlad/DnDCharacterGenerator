cmake_minimum_required(VERSION 3.15)
project(CharacterMaker)

set(CMAKE_CXX_STANDARD 14)
set(SOURCES warior.cpp warior.hpp supFunctions.cpp supFunctions.hpp BaseCharacter.cpp BaseCharacter.hpp)
add_executable(CharacterMaker main.cpp ${SOURCES})