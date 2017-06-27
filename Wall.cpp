#include "Wall.h"

Wall::Wall(Character* prsn) : Tile(prsn)
{
}

char Wall::print() const
{
    return '#';
}

void Wall::onEnter(Character* prsn, Tile* fromTile)
{
    fromTile->onEnter(prsn, & * this);
}

void Wall::onLeave(Tile* toTile)
{
}

bool Wall::isTransparent()
{
    return false;
}

bool Wall::EnemyAcces()
{
    return false;
}

Wall::~Wall()
{
}

