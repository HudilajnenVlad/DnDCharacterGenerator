#include "supFunctions.hpp"
#include <iostream>
#include <random>
#include <chrono>

int rollD(int left, int right)
{
  static std::default_random_engine gen(std::chrono::steady_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<int> distribution(left, right);
  return distribution(gen);
}

void fillD6(int *array, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    array[i] = rollD();
  }
}

void sort(int *array, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    for (size_t j = i; j < size; ++j)
    {
      if (array[i] > array[j])
      {
        std::swap(array[i], array[j]);
      }
    }
  }
}

void printArray(int *array, size_t size)
{
  for (int i = 0; i < size; ++i)
  {
    std::cout << array[i] << ' ';
  }
  std::cout << '\n';
}

int getStat()
{
  int *array = new int[4];
  fillD6(array);
  sort(array);
  int sum = 0;
  for (size_t i = 1; i < 4; ++i)
  {
    sum += array[i];
  }
  delete array;
  if (sum < 8)
  {
    sum = getStat();
  }
  return sum;
}

void fillStats(int *statsArray)
{
  for (size_t i = 0; i < 6; ++i)
  {
    statsArray[i] = getStat();
  }
  sort(statsArray, 6);
}
