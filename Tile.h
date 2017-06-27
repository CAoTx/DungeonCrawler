#ifndef TILE_H
#define TILE_H

#include "Character.h"
#include <string>
#include <vector>

class Tile
{
public:
    Tile(Character* prsn);

    Character* getprsn()const;
    void setprsn(Character* newprsn);
    bool hasCharacter()const;

    virtual char print() const = 0;
    virtual void onLeave(Tile* toTile) = 0;
    virtual void onEnter(Character* prsn, Tile* fromTile) = 0;
    virtual bool isTransparent() {return true;};
    virtual bool EnemyAcces() = 0;

    virtual ~Tile();
private:
    Character* person;
};

#endif /* TILE_H */

