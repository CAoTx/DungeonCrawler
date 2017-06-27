#include "Door.h"

Door::Door(Character* prsn) : Passive{prsn}
{
}

char Door::print() const
{
    if (Passive::getstat() == false && Tile::getprsn() == nullptr)
        return 'X';
    else if (Passive::getstat() == true && Tile::getprsn() == nullptr)
        return '/';
    else return Tile::getprsn()->getSign();
}

void Door::onEnter(Character* prsn, Tile* fromTile)
{
    if (Tile::hasCharacter() == false && Passive::getstat() == true)
        Tile::setprsn(prsn);
    else fromTile->onEnter(prsn, & * this);
}

void Door::onLeave(Tile* toTile)
{
    if (toTile->hasCharacter() == false)
    {
        toTile->onEnter(Tile::getprsn(), & * this);
        Tile::setprsn(nullptr);
    }
    else if (toTile->getprsn() == Tile::getprsn())
        return;
    else throw "Function onLeave error";
}

bool Door::EnemyAcces()
{
    if (Passive::getstat() == false)
        return false;
    return true;
}

Door::~Door()
{
}

