#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Item.h"
#include "ConsoleController.h"
#include "AttackController.h"

class Character {
public:

    Character();
    Character(char sgn, Controller* brthr, int str, int sta);

    void setprsn(Controller* newbrthr);
    char getSign() const;
    int move();

    int getmaxHP();
    void showInfo();
    void addItem(Item* itm);
    int getstrength();
    int getstamina();
    int getHP(){return hitpoints;};
    void hit(const int damage);

    virtual ~Character();
private:
    char sign;
    Controller* brother;
    int stamina;
    int strength;
    int hitpoints;
    std::vector <Item*> equip;
};

#endif /* CHARACTER_H */

