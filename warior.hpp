#ifndef CHARACTERMAKER_WARIOR_HPP
#define CHARACTERMAKER_WARIOR_HPP

#include <iostream>

class Warior
{
public:
  enum BattleStyle
  {
    DUELIST = 1,
    PROTECTION,
    DEFENCE,
    BIG_WEAPON,
    TWO_WEAPON,
    ARCHER
  };

  enum Race
  {
    HUMAN = 1, MOUNTAIN_DWARF, HILL_DWARF, HIGH_ELF, FOREST_ELF, DROW, STOCKY_HALFLING, LIGHTFOOT_HALFLING, DRAGONBORN,
    FOREST_GNOME, ROCKY_GNOME, HALF_ELF, HALF_ORC, TIEFLING
  };

  Warior(int level = 1);

  void printCharacter(std::ostream &out = std::cout);

  void printRace(std::ostream &out = std::cout);

  void printStats(std::ostream &out = std::cout);

  void printHP(std::ostream &out = std::cout);

  bool isForceBuild();

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
  BattleStyle style_;
  Race race_;

  void setMasteryBonus();

  void chooseRace();

  void chooseBattleStyle();

  void setHP();
};


#endif
