#ifndef CHARACTERMAKER_SUPFUNCTIONS_HPP
#define CHARACTERMAKER_SUPFUNCTIONS_HPP
#include <iostream>

void fillD6(int *array, size_t size = 4);

int rollD(int left = 1, int right = 6);

void sort(int *array, size_t size = 4);

void printArray(int *array, size_t size = 4);

int getStat();

void fillStats(int *statsArray);

#endif //CHARACTERMAKER_SUPFUNCTIONS_HPP
