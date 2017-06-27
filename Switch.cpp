#include "Switch.h"

Switch::Switch(Passive* brthr) : Active{brthr}
{
}

char Switch::print()const
{
    if (Active::getstat() == false && Tile::getprsn() == nullptr)
        return '?';
    else if (Active::getstat() == true && Tile::getprsn() == nullptr)
        return '!';
    else return Tile::getprsn()->getSign();
}
//Switch behaves like a Wall, it puts the Character back

void Switch::onEnter(Character* prsn, Tile* fromTile)
{
    if (Active::getstat() == false)
        Active::setstat(true);
    Active::brother->setstat(true);
    if (Tile::hasCharacter() == 0)
        Tile::onEnter(prsn, fromTile);
}

void Switch::onLeave(Tile* toTile)
{
    if (toTile->hasCharacter() == 0)
    {
        toTile->onEnter(Tile::getprsn(), & * this);
        Tile::setprsn(nullptr);
    }
    else if (toTile->getprsn() == Tile::getprsn())
        return;
    else throw "Function onLeave error";
}

bool Switch::EnemyAcces()
{
    if (getstat()==true)
        return true;
    return false;
}


Switch::~Switch()
{
}

