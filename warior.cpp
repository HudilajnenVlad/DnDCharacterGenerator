#include "warior.hpp"
#include "supFunctions.hpp"
#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>

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
  out << '\n';
  out << std::setw(8) << "STR";
  out << std::setw(8) << "DEX";
  out << std::setw(8) << "CON";
  out << std::setw(8) << "INT";
  out << std::setw(8) << "WIS";
  out << std::setw(8) << "CHR";
  out << '\n';
  out << std::setw(8) << STR_;
  out << std::setw(8) << DEX_;
  out << std::setw(8) << CON_;
  out << std::setw(8) << INT_;
  out << std::setw(8) << WIS_;
  out << std::setw(8) << CHR_;
  out << '\n';
  out << '\n';
}

void Warior::printCharacter(std::ostream &out)
{
  printRace(out);
  printHP(out);
  printAR(out);
  printStats(out);
  printAbilities(out);
  printAttack(out);
  out << '\n';
  printPrehistory(out);
  out << '\n';
}

void Warior::printRace(std::ostream &out)
{
  out << "Раса: ";
  switch (race_)
  {
    case HUMAN:
      out << "Человек";
      break;
    case MOUNTAIN_DWARF:
      out << "Горный дварф";
      break;
    case HILL_DWARF:
      out << "Холмовой дварф";
      break;
    case HIGH_ELF:
      out << "Высший эльф";
      break;
    case FOREST_ELF:
      out << "Лесной эльф";
      break;
    case DROW:
      out << "Дроу";
      break;
    case STOCKY_HALFLING:
      out << "Скальный полурослик";
      break;
    case LIGHTFOOT_HALFLING:
      out << "Легконогий полурослик";
      break;
    case DRAGONBORN:
      out << "Драконорождённый";
      break;
    case FOREST_GNOME:
      out << "Лесной гном";
      break;
    case ROCKY_GNOME:
      out << "Скальный гном";
      break;
    case HALF_ELF:
      out << "Полуэльф";
      break;
    case HALF_ORC:
      out << "Полуорк";
      break;
    case TIEFLING:
      out << "Тифлинг";
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

void Warior::printAR(std::ostream &out)
{
  switch (style_)
  {
    case DUELIST:
      out << "Класс доспеха - " << 14 + (DEX_ - 10) / 2 << " Доспех из проклёпанной кожи и щит\n";
      break;
    case ARCHER:
      out << "Класс доспеха - " << 12 + (DEX_ - 10) / 2 << " Доспех из проклёпанной кожи\n";
      break;
    case TWO_WEAPON:
      out << "Класс доспеха - " << 12 + (DEX_ - 10) / 2 << " Доспех из проклёпанной кожи\n";
      break;
    case BIG_WEAPON:
      out << "Класс доспеха - " << 14 + (((DEX_ - 10) / 2) > 2 ? 2 : ((DEX_ - 10) / 2)) << " Чешуйчатый доспех\n";
      break;
    case DEFENCE:
      out << "Класс доспеха - " << 19 << " Кольчуга и щит\n";
      break;
    case PROTECTION:
      out << "Класс доспеха - " << 18 << " Кольчуга и щит\n";
      break;
  }
}

void Warior::printAttack(std::ostream &out)
{
  out << "Атаки:\n";
  switch (style_)
  {
    case DUELIST:
      out << "Рапира. Рукапашная атака оружием: +" << (DEX_ - 10) / 2 + masteryBonus_
          << ", досягаемость 5 футов, одна цель. Попадание: Колющий урон 1d8+" << (DEX_ - 10) / 2 + 2 << '.' << '\n';
      break;
    case ARCHER:
      out << "Длинный лук. Дальнобойная атака оружием: +" << (DEX_ - 10) / 2 + masteryBonus_ + 2
          << ", дистанция 150/600 футов, одна цель. Попадание: Колющий урон 1d8+" << (DEX_ - 10) / 2 << '.' << '\n';
      out << "Скимитар. Рукапашная атака оружием: +" << (DEX_ - 10) / 2 + 2
          << ", досягаемость 5 футов, одна цель. Попадание: Режущий урон 1d6+" << (DEX_ - 10) / 2 << '.' << '\n';
      break;
    case TWO_WEAPON:
      out << "Мультиатака: Совершает 2 атаки коротким мечом (Бонусное и основное действия)\n";
      out << "Короткий меч. Рукопашная атака оружием: +" << (DEX_ - 10) / 2 + masteryBonus_
          << ", досягаемость 5 футов, одна цель. Попадание: колющий урон 1d6+" << (DEX_ - 10) / 2 << '.' << '\n';
      break;
    case BIG_WEAPON:
      out << "Двуручный меч. Melee weapon attack: +" << (STR_ - 10) / 2 + masteryBonus_
          << ", досягаемость 5 футов, одна цель. Попадание: Режущий урон 2d6+" << (STR_ - 10) / 2 << '.' << '\n';
      break;
    case DEFENCE:
      out << "Длинный меч. Рукопашная атака оружием: +" << (STR_ - 10) / 2 + masteryBonus_
          << ", досягаемость 5 футов, одна цель. Попадание: Режущий урон 1d8+" << (STR_ - 10) / 2 << '.' << '\n';
      break;
    case PROTECTION:
      out << "Боевой молот. Рукопашная атака оружием: +" << (STR_ - 10) / 2 + masteryBonus_
          << ", досягаемость 5 футов, одна цель. Попадание: Дробящий урон 1d8+" << (STR_ - 10) / 2 << '.' << '\n';
      break;
  }
}

void Warior::printBattleStyle(std::ostream &out)
{
  switch (style_)
  {
    case DUELIST:
      out << "Боевой стиль - Дуэлянт:\n";
      out << "Пока вы держите рукопашное оружие в одной руке, и не используете другого оружия, "
          << "вы получаете бонус +2 к броскам урона этим оружием. \n";
      break;
    case ARCHER:
      out << "Боевой стиль - Стрелок\n";
      out << "Вы получаете бонус +2 к броску атаки, когда атакуете дальнобойным оружием.\n";
      break;
    case TWO_WEAPON:
      out << "Боевой стиль - два оружия\n";
      out
          << "Если вы сражаетесь двумя оружиями, вы можете добавить модификатор характеристики к урону от второй атаки.\n";
      break;
    case BIG_WEAPON:
      out << "Боевой стиль - сражение большим оружием \n";
      out
          << "Если у вас выпало «1» или «2» на кости урона оружия при атаке, которую вы совершали рукопашным оружием, удерживая его двумя руками,"
          << " то вы можете перебросить эту кость, и должны использовать новый результат, даже если снова выпало «1» или «2»."
          << "Чтобы воспользоваться этим преимуществом, ваше оружие должно иметь свойство «двуручное» или «универсальное».\n";
      break;
    case DEFENCE:
      out << "Боевой стиль - Оборона\n";
      out << "Пока вы носите доспехи, вы получаете бонус +1 к Классу Доспеха\n";
      break;
    case PROTECTION:
      out << "Боевой стиль - Защита\n";
      out << "Если существо, которое вы видите, атакует не вас, а другое существо, находящееся в пределах 5 фт. от вас,"
          << " вы можете реакцией создать помеху его броску атаки. Для этого вы должны использовать щит.\n";
      break;
  }
}

void Warior::printTrait(int index, std::ostream &out)
{
  switch (index)
  {
    case 1:
      out << "Я всегда вежлив и почтителен.\n";
      break;
    case 2:
      out << "Меня терзают воспоминания о войне. Не могу забытьто насилие, что мне довелось увидеть..\n";
      break;
    case 3:
      out << "Я потерял много друзей, и теперь с трудом завожу новых.\n";
      break;
    case 4:
      out << "У меня много воодушевляющих и предостерегающих "
          << "рассказов из военного прошлого, подходящих практически к любой боевой ситуации.\n";
      break;
    case 5:
      out << "Я могу смотреть прямо на адскую гончую, не отводя глаз.\n";
      break;
    case 6:
      out << "Мне нравится быть сильным и крушить вещи.\n";
      break;
    case 7:
      out << "У меня грубое чувство юмора.\n";
      break;
    case 8:
      out << "Я решаю проблемы прямолинейно. Простое решение — лучший путь к успеху.\n";
      break;
  }
}

void Warior::printPrehistory(std::ostream &out)
{
  out << "Предыстория: Солдат ";
  int specialization = rollD(1, 8);
  switch (specialization)
  {
    case 1:
      out << "Офицер\n";
      break;
    case 2:
      out << "Разведчик\n";
      break;
    case 3:
      out << "Пехотинец\n";
      break;
    case 4:
      out << "Кавалерист\n";
      break;
    case 5:
      out << "Врач\n";
      break;
    case 6:
      out << "Интендант\n";
      break;
    case 7:
      out << "Знаменосец\n";
      break;
    case 8:
      out << "Обслуживающий персонал\n";
      break;
  }
  out << "Черты характера:\n";
  int CH1 = rollD(1, 8);
  printTrait(CH1, out);
  int CH2 = CH1;
  while (CH2 == CH1)
  {
    CH2 = rollD(1, 8);
  }
  printTrait(CH2, out);
  out << "Идеалы: ";
  int ideal = rollD();
  switch (ideal)
  {
    case 1:
      out << "Высшее благо. Наш жребий — отдать свои жизни ради других. (Добрый)\n";
      break;
    case 2:
      out << "Ответственность. Я делаю что должен, и подчиняюсь вышестоящим. (Законный)\n";
      break;
    case 3:
      out << "Независимость. Если слепо следовать приказам, попадаешь под пяту тирании. (Хаотичный)\n";
      break;
    case 4:
      out << "Мощь. В жизни и войне побеждает сильнейший. (Злой)\n";
      break;
    case 5:
      out << "Живи и не мешай другим. Идеалы не стоят того, чтобы ради них убивать или воевать. (Нейтральный)\n";
      break;
    case 6:
      out << "Нация. Мой город, нация и народ — вот что самое главное. (Любой)\n";
      break;
  }

  out << "Привязанность: ";
  int attachment = rollD();
  switch (attachment)
  {
    case 1:
      out << "Я по-прежнему готов отдать свою жизнь за тех, комупоклялся служить.\n";
      break;
    case 2:
      out << "Кое-кто спас мне жизнь на поле боя. С тех пор я никогда не оставляю друзей, оставшихся в бою.\n";
      break;
    case 3:
      out << "Моя честь — моя жизнь\n";
      break;
    case 4:
      out << "Никогда не забуду сокрушительное поражение, которое потерпел наш отряд, или врага, устроившего это.\n";
      break;
    case 5:
      out << "Те, кто сражаются рядом со мной, достойны того, чтобы за них умереть.\n";
      break;
    case 6:
      out << "Я сражаюсь за тех, кто не может это сделать сам.\n";
      break;
  }
  out << "Слабость: ";
  int disadv = rollD();
  switch (disadv)
  {
    case 1:
      out << "Одно чудовище, с которым мы когда-то сразились, до сих пор заставляет меня дрожать от страха\n";
      break;
    case 2:
      out << "Я мало уважаю тех, кто не доказал, что является достойным воителем.\n";
      break;
    case 3:
      out
          << "В одном сражении я совершил ужасную ошибку, стоившую жизни многим — и я сделаю что угодно, лишь бы это оставалось в тайне.\n";
      break;
    case 4:
      out << "Ярость к врагам ослепляет меня и делает безрассудным.\n";
      break;
    case 5:
      out << "Я подчиняюсь закону, даже если закон вызывает страдания.\n";
      break;
    case 6:
      out << "Я скорее съем свой доспех, чем признаюсь, что был неправ.\n";
      break;
  }
}

void Warior::printAbilities(std::ostream &out)
{
  switch (level_)
  {
    case 2:
      printActionSplash(out);
    case 1:
      printBattleStyle(out);
      out << "Второе дыхание:\n";
      out
          << "В свой ход раз за короткий отдых вы можете бонусным действием восстановить хиты в размере 1d10 + ваш уровень воина.\n";
  }
}

void Warior::printActionSplash(std::ostream &out)
{
  out << "Всплеск действий: \n";
  if (level_ >= 17)
  {
    out << "В свой ход вы можете совершить одно дополнительное действие помимо обычного и бонусного действий."
        << "Вы можете использовать это умение два раза за короткий отдых.\n";
  }
  else
  {
    out << "В свой ход вы можете совершить одно дополнительное действие помимо обычного и бонусного действий."
        << "Вы можете использовать это умение один раз за короткий отдых.\n";
  }
}