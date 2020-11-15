cmake_minimum_required(VERSION 3.15)
project(CharacterMaker)

set(CMAKE_CXX_STANDARD 14)
set(SOURCES warior supFunctions character ability race characterClass)
add_executable(CharacterMaker main.cpp ${SOURCES})