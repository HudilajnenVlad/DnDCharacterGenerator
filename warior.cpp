#include "warior.hpp"
#include "supFunctions.hpp"
#include <iostream>
#include <random>
#include <chrono>

Warior::Warior(int level)
{
  level_ = level;
  setMasteryBonus();
  int *stats = new int[6];
  fillStats(stats);
  chooseBattleStyle();
  switch (style_)
  {
    case DUELIST:
      DEX_ = stats[5];
      CON_ = stats[4];
      CHR_ = stats[3];
      INT_ = stats[2];
      WIS_ = stats[1];
      STR_ = stats[0];
      break;
    case ARCHER:
      DEX_ = stats[5];
      WIS_ = stats[4];
      CON_ = stats[3];
      INT_ = stats[2];
      CHR_ = stats[1];
      STR_ = stats[0];
      break;
    case TWO_WEAPON:
      DEX_ = stats[5];
      CON_ = stats[4];
      STR_ = stats[3];
      WIS_ = stats[2];
      CHR_ = stats[1];
      INT_ = stats[0];
      break;
    case BIG_WEAPON:
      STR_ = stats[5];
      DEX_ = stats[3];
      CON_ = stats[4];
      WIS_ = stats[2];
      CHR_ = stats[1];
      INT_ = stats[0];
      break;
    case PROTECTION:
      CON_ = stats[5];
      STR_ = stats[4];
      WIS_ = stats[3];
      CHR_ = stats[2];
      DEX_ = stats[1];
      INT_ = stats[0];
      break;
    case DEFENCE:
      STR_ = stats[5];
      CON_ = stats[4];
      WIS_ = stats[3];
      INT_ = stats[2];
      DEX_ = stats[1];
      CHR_ = stats[0];
      break;
  }
  chooseRace();
  setHP();
}

void Warior::chooseBattleStyle()
{
  style_ = BattleStyle(rollD());
}

void Warior::printStats(std::ostream &out)
{
  out << "STR = " << STR_ << '\n';
  out << "DEX = " << DEX_ << '\n';
  out << "CON = " << CON_ << '\n';
  out << "INT = " << INT_ << '\n';
  out << "WIS = " << WIS_ << '\n';
  out << "CHR = " << CHR_ << '\n';
}

void Warior::printCharacter(std::ostream &out)
{
  printStats(out);
  printRace(out);
  switch (style_)
  {
    case DUELIST:
      out << "Battle style - Duelist\n";
      printHP(out);
      out << "Armor Rating - " << 14 + (DEX_ - 10) / 2 << " Riveted leather armor and shield\n";
      out << "Rapier. Melee weapon attack: +" << (DEX_ - 10) / 2 + masteryBonus_
          << ", reach 5 ft, one goal. Hit: Piercing damage 1d8+" << (DEX_ - 10) / 2 + 2 << '\n';
      break;
    case ARCHER:
      out << "Battle style - Archer\n";
      printHP(out);
      out << "Armor Rating - " << 12 + (DEX_ - 10) / 2 << " Riveted leather armor\n";
      out << "Long bow. Range weapon attack: +" << (DEX_ - 10) / 2 + masteryBonus_ + 2
          << ", reach 150/600 ft, one goal. Hit: Piercing damage 1d8+" << (DEX_ - 10) / 2 << '\n';
      out << "Scimitar sword. Melee weapon attack: +" << (DEX_ - 10) / 2 + 2
          << ", reach 5 ft, one goal. Hit: Cutting damage 1d6+" << (DEX_ - 10) / 2 << '\n';
      break;
    case TWO_WEAPON:
      out << "Battle style - Two Weapon\n";
      printHP(out);
      out << "Armor Rating - " << 12 + (DEX_ - 10) / 2 << " Riveted leather armor\n";
      out << "Multiattack: Makes 2 attacks with a short sword\n";
      out << "Short sword. Melee weapon attack: +" << (DEX_ - 10) / 2 + masteryBonus_
          << ", reach 5 ft, one goal. Hit: Piercing damage 1d6+" << (DEX_ - 10) / 2 << '\n';
      break;
    case BIG_WEAPON:
      out<< "Battle style - Big weapons \n";
      printHP(out);
      out << "Armor Rating - " << 14 + (((DEX_ - 10) / 2) > 2 ? 2 : ((DEX_ - 10) / 2)) << " Scaly armor\n";
      out << "Master of Big Weapon: If you have a\" 1 \"or\" 2 \" on the weapon's damage dice during an attack"
          << "that you made with a melee weapon while holding it with two hands, then you can roll this dice,"
          << " and must use the new result, even if a \"1\" or \"2\" is rolled again."
          << "To take advantage of this advantage, your weapon must have the \"two-handed\" or \"universal\"property.\n";

      out << "Two-Handed-Sword. Melee weapon attack: +" << (STR_ - 10) / 2 + masteryBonus_
          << ", reach 5 ft, one goal. Hit: Cutting damage 2d6+" << (STR_ - 10) / 2 << '\n';
      break;
    case DEFENCE:
      out << "Battle style - Defence\n";
      printHP(out);
      out << "Armor Rating - " << 19 << " Chain mail + shield\n";
      out << "Long Sword. Melee weapon attack: +" << (STR_ - 10) / 2 + masteryBonus_
          << ", reach 5 ft, one goal. Hit: Cutting damage 1d8+" << (STR_ - 10) / 2 << '\n';
      break;
    case PROTECTION:
      out << "Battle style - Protection\n";
      printHP(out);
      out << "Armor Rating - " << 18 << " Chain mail + shield\n";
      out << "Defence Master: If the creature you see is not attacking you, but another creature within 5 ft."
          << " from you, you can react to interfere with his attack roll. To do this, you must use a shield.\n";
      out << "Warhammer. Melee weapon attack: +" << (STR_ - 10) / 2 + masteryBonus_
          << ", reach 5 ft, one goal. Hit: Crushing damage 1d8+" << (STR_ - 10) / 2 << '\n';
      break;
  }
  out << '\n';
}

void Warior::printRace(std::ostream &out)
{
  out << "Race: ";
  switch (race_)
  {
    case HUMAN:
      out << "Human";
      break;
    case MOUNTAIN_DWARF:
      out << "Mountain Dwarf";
      break;
    case HILL_DWARF:
      out << "Hill Dwarf";
      break;
    case HIGH_ELF:
      out << "High Elf";
      break;
    case FOREST_ELF:
      out << "Forest Elf";
      break;
    case DROW:
      out << "Drow";
      break;
    case STOCKY_HALFLING:
      out << "Stocky Halfling";
      break;
    case LIGHTFOOT_HALFLING:
      out << "Lightfoot Halfling";
      break;
    case DRAGONBORN:
      out << "Dragonborn";
      break;
    case FOREST_GNOME:
      out << "Forest Gnome";
      break;
    case ROCKY_GNOME:
      out << "Rocky Gnome";
      break;
    case HALF_ELF:
      out << "Half-Elf";
      break;
    case HALF_ORC:
      out << "Half-Orc";
      break;
    case TIEFLING:
      out << "Tiefling";
      break;
  }
  out << '\n';
}

void Warior::chooseRace()
{
  race_ = Race(rollD(1, 14));
  switch (race_)
  {
    case HUMAN:
      STR_++;
      DEX_++;
      CON_++;
      INT_++;
      WIS_++;
      CHR_++;
      break;
    case MOUNTAIN_DWARF:
      if (!isForceBuild())
      {
        chooseRace();
      }
      CON_ += 2;
      STR_ += 2;
      break;
    case HILL_DWARF:
      CON_ += 2;
      WIS_++;
      break;
    case HIGH_ELF:
      if (isForceBuild())
      {
        chooseRace();
      }
      DEX_ += 2;
      INT_++;
      break;
    case FOREST_ELF:
      if (isForceBuild())
      {
        chooseRace();
      }
      DEX_ += 2;
      WIS_++;
      break;
    case DROW:
      if (isForceBuild())
      {
        chooseRace();
      }
      DEX_ += 2;
      CHR_++;
      break;
    case STOCKY_HALFLING:
      if (isForceBuild())
      {
        chooseRace();
      }
      DEX_ += 2;
      CON_++;
      break;
    case LIGHTFOOT_HALFLING:
      if (isForceBuild())
      {
        chooseRace();
      }
      DEX_ += 2;
      CHR_++;
      break;
    case DRAGONBORN:
      STR_ += 2;
      CHR_++;
      break;
    case FOREST_GNOME:
      if (isForceBuild())
      {
        chooseRace();
      }
      INT_ += 2;
      DEX_++;
      break;
    case ROCKY_GNOME:
      if (isForceBuild())
      {
        chooseRace();
      }
      INT_ += 2;
      CON_++;
      break;
    case HALF_ELF:
      CHR_ += 2;
      STR_++;
      DEX_++;
      break;
    case HALF_ORC:
      if (!isForceBuild())
      {
        chooseRace();
      }
      STR_ += 2;
      CON_++;
      break;
    case TIEFLING:
      INT_++;
      CHR_ += 2;
      break;
  }
}

bool Warior::isForceBuild()
{
  return (style_ == DEFENCE || style_ == PROTECTION || style_ == BIG_WEAPON);
}

void Warior::setMasteryBonus()
{
  if (level_ <= 4)
  {
    masteryBonus_ = 2;
  }
  else if (level_ <= 8)
  {
    masteryBonus_ = 3;
  }
  else if (level_ <= 12)
  {
    masteryBonus_ = 4;
  }
  else if (level_ <= 16)
  {
    masteryBonus_ = 5;
  }
  else
  {
    masteryBonus_ = 6;
  }
}

void Warior::setHP()
{
  HP_ = 10 + (CON_ - 10) / 2;
  if (level_ != 1)
  {
    for (int i = 1; i < level_; ++i)
    {
      HP_ += rollD(1, 10) + (CON_ - 10) / 2;
    }
  }
}

void Warior::printHP(std::ostream &out)
{
  out << "HP: " << HP_ << '\n';
}
/*
  switch (race_)
  {
    case HUMAN:
      break;
    case MOUNTAIN_DWARF:
      break;
    case HILL_DWARF:
      break;
    case HIGH_ELF:
      break;
    case FOREST_ELF:
      break;
    case DROW:
      break;
    case STOCKY_HALFLING:
      break;
    case LIGHTFOOT_HALFLING:
      break;
    case DRAGONBORN:
      break;
    case FOREST_GNOME:
      break;
    case ROCKY_GNOME:
      break;
    case HALF_ELF:
      break;
    case HALF_ORC:
      break;
    case TIEFLING:
      break;
  }
 */