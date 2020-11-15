#ifndef CHARACTERMAKER_RACE_HPP
#define CHARACTERMAKER_RACE_HPP

#include <vector>
#include "ability.hpp"

class Race
{
public:

private:
  std::string name_;
  short *mods_;
  short *skills_;
  short *saveRolls_;
  std::vector<Ability> relatedAbility_;
};

#endif
