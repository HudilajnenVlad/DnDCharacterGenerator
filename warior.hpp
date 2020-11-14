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

  Warior();

  void chooseRace();

  void chooseBattleStyle();

  void printCharacter(std::ostream &out);

  void printRace(std::ostream &out);

  void printStats(std::ostream &out);

  bool isForceBuild();

private:
  int STR_;
  int DEX_;
  int CON_;
  int INT_;
  int WIS_;
  int CHR_;
  BattleStyle style_;
  Race race_;
};


#endif
