#include "Floor.h"

Floor::Floor(Character* prsn, Item* itm) : Tile(prsn)
{
    if (prsn != nullptr&&itm != nullptr)
        throw"Floor Init with Char & Item";
    else item = itm;
}

char Floor::print()const
{
    if (Tile::getprsn() == nullptr&&item == nullptr)
        return ' ';
    else if (item == nullptr)
        return Tile::getprsn()->getSign();
    else return item->print();
}

void Floor::onLeave(Tile* toTile)
{
    if (toTile->hasCharacter() == 0)
    {
        Character* c_ptr = this->getprsn();
        Tile::setprsn(nullptr);
        toTile->onEnter(c_ptr, this);

    }
    else if (toTile->getprsn() == Tile::getprsn())
        return;
    else if (toTile->hasCharacter() == true)
        return;
    else throw "Function onLeave error";
}

void Floor::onEnter(Character* prsn, Tile* fromTile)
{
    if (Tile::hasCharacter() == 0)
    {
        Tile::setprsn(prsn);
        if (item != nullptr)
        {
            Tile::getprsn()->addItem(item);
            item = nullptr;
        }
    }
    else
        fromTile->onEnter(prsn, this);
}

void Floor::getItem(Item* itm)
{
    this->item = itm;
}

bool Floor::EnemyAcces()
{
    if (item == nullptr)
        return true;
    return false;
}

Floor::~Floor()
{
}

