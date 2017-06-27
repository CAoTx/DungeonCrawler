#include "Trap.h"

Trap::Trap() : Passive(nullptr)
{
    Passive::setstat(false);
}

void Trap::onEnter(Character* prsn, Tile* fromTile)
{
    int damage = 15; //
    if (Tile::hasCharacter() == 0)
    {
        Tile::setprsn(prsn);
        
        if (getstat()==false)
        {
            prsn->hit(damage);
        }
        Passive::setstat(true);
    }
    else fromTile->onEnter(prsn, this);
}

void Trap::onLeave(Tile* toTile)
{
    if (toTile->hasCharacter() == 0)
    {
        Character* c_ptr = this->getprsn();
        Tile::setprsn(nullptr);
        toTile->onEnter(c_ptr, this);
    }
    else if (toTile->getprsn() == Tile::getprsn())
        return;
    else throw "Function onLeave error";
}

char Trap::print() const
{
    if (Tile::hasCharacter() == false && Passive::getstat() == true)
        return 'T';
    else if (Tile::hasCharacter() == true)
        return Tile::getprsn()->getSign();
    else if (Tile::hasCharacter() == false && Passive::getstat() == false)
        return ' ';
	return ' ';
}

bool Trap::EnemyAcces()
{
    if (getstat()==true)
        return true;
    return false;
}


Trap::~Trap()
{
}

