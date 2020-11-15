#ifndef CHARACTERMAKER_CHARACTERCLASS_HPP
#define CHARACTERMAKER_CHARACTERCLASS_HPP

class CharacterClass
{
public:

private:
  std::string name_;
  short *mods_;
  short *skills_;
  short *saveRolls_;
  std::vector <Ability> relatedAbility_;
};

#endif
