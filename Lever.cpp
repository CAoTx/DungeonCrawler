#include "Lever.h"

Lever::Lever(Passive* brthr) : Active{brthr}
{
}

void Lever::onEnter(Character* prsn, Tile* fromTile)
{
    if (Active::getstat() == false)
    {
        Active::setstat(true);
        Active::brother->setstat(true);
    }
    else if (Active::getstat() == true)
    {
        Active::setstat(false);
        Active::brother->setstat(false);
    }
    if (Tile::hasCharacter() == 0)
        Tile::onEnter(prsn, fromTile);
}

void Lever::onLeave(Tile* toTile)
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

char Lever::print() const
{
    if (Active::getstat() == false && Tile::getprsn() == nullptr)
        return '?';
    else if (Active::getstat() == true && Tile::getprsn() == nullptr)
        return '!';
    else return Tile::getprsn()->getSign();
}

bool Lever::EnemyAcces()
{
    return false;
}



Lever::~Lever()
{
}

