#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include "warior.hpp"

int main()
{
  std::ofstream out;
  out.open("text.txt");
  Warior warior(2);
  Warior warior1;
  Warior warior2;
  Warior warior3;
  Warior warior4;
  Warior warior5;
  Warior warior6;
  warior.printCharacter(out);
  warior1.printCharacter(out);
  warior2.printCharacter(out);
  warior3.printCharacter(out);
  warior4.printCharacter(out);
  warior5.printCharacter(out);
  warior6.printCharacter(out);
  out.close();
  return 0;
}