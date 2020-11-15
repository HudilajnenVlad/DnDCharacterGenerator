#ifndef CHARACTERMAKER_ABILITY_HPP
#define CHARACTERMAKER_ABILITY_HPP

#include <string>
#include <vector>

class Ability
{
public:

private:
  short level_
  std::string name_;
  std::string description_;
  bool isArchetype;
  std::vector<Ability> relatedAbility_;
};

#endif
