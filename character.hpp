#ifndef CHARACTERMAKER_BASE_CHARACTER_HPP
#define CHARACTERMAKER_BASE_CHARACTER_HPP

#include <cstddef>
#include "ability.hpp"

class Character
{
public:
private:
  std::size_t level_;
  std::string name_;
  Race race_;
  Class class_;
  short *mods_;
  short *skills_;
  short *saveRolls_;
  bool haveArchetype;
  std::vector<Ability> abilities_;
};

#endif
