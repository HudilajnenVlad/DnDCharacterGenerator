#ifndef CHARACTERMAKER_WARIOR_HPP
#define CHARACTERMAKER_WARIOR_HPP

#include <iostream>

class Warior
{
public:
  enum battleStyle_t
  {
    DUELIST = 1,
    PROTECTION,
    DEFENCE,
    BIG_WEAPON,
    TWO_WEAPON,
    ARCHER
  };

  enum race_t
  {
    HUMAN = 1, MOUNTAIN_DWARF, HILL_DWARF, HIGH_ELF, FOREST_ELF, DROW, STOCKY_HALFLING, LIGHTFOOT_HALFLING, DRAGONBORN,
    FOREST_GNOME, ROCKY_GNOME, HALF_ELF, HALF_ORC, TIEFLING
  };

  Warior(int level = 1);

  void printCharacter(std::ostream &out = std::cout);

  void printRace(std::ostream &out = std::cout);

  void printStats(std::ostream &out = std::cout);

  void printHP(std::ostream &out = std::cout);

  void printAttack(std::ostream &out = std::cout);

  void printAR(std::ostream &out = std::cout);

  void printBattleStyle(std::ostream &out = std::cout);

  bool isForceBuild();

  void printTrait(int index, std::ostream &out = std::cout);

  void printPrehistory(std::ostream &out = std::cout);

  void printAbilities(std::ostream &out = std::cout);

  void printActionSplash(std::ostream &out = std::cout);

private:
  int level_;
  int masteryBonus_;
  int STR_;
  int DEX_;
  int CON_;
  int INT_;
  int WIS_;
  int CHR_;
  int HP_;
  battleStyle_t style_;
  race_t race_;

  void setMasteryBonus();

  void chooseRace();

  void chooseBattleStyle();

  void setHP();
};


#endif
