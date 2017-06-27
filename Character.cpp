#include <vector>
#include "Character.h"

Character::Character()
{
}

Character::Character(char sgn, Controller* brthr, int str, int sta)
{
    this->sign = sgn;
    this->brother = brthr;
    this->strength = str;
    this->stamina = sta;
    if (sign == '$')
    {
        this->hitpoints = 20;//getmaxHP()*0.1;
    }
    else 
    this->hitpoints = getmaxHP();

}

char Character::getSign() const
{
    return sign;
}

int Character::move()
{
    return brother->move();
}

void Character::setprsn(Controller* newbrthr)
{
    this->brother = newbrthr;
}

int Character::getmaxHP()
{
    return (20 + (getstamina() * 5));
}

void Character::showInfo()
{
    std::cout << "Actual Stats of " << sign << ":" << std::endl;
    std::cout << "Stamina   :" << getstamina() << std::endl;
    std::cout << "Strenght  :" << getstrength() << std::endl;
    std::cout << "hitpoints :" << hitpoints << std::endl << std::endl;
}

void Character::addItem(Item* itm)
{
    equip.push_back(itm);
}

int Character::getstamina()
{
    int stam = 0;

    if (equip.size() > 0)
    {
        for (int i = 0; i < equip.size(); i++)
            stam = stam + equip[i]->modifyStamina(stamina);
    }
    else return stamina;

    stam = stam + stamina;
    return stam;
}

int Character::getstrength()
{
    int strn = 0;

    if (equip.size() > 0)
    {
        for (int j = 0; j < equip.size(); j++)
            strn = strn + equip[j]->modifyStrength(strength);
    }
    else return strength;

    strn = strn + strength;
    return strn;
}

void Character::hit(const int damage)
{
    hitpoints = hitpoints - damage;
}

Character::~Character()
{
    delete brother;
    for (int k = 0; k < equip.size(); k++)
        delete equip[k];
}