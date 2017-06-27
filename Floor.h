#ifndef FLOOR_H
#define FLOOR_H

#include "Tile.h"

class Floor : public Tile
{
public:

    Floor(Character* prsn, Item* itm);

    char print() const override;
    void onLeave(Tile* toTile) override;
    void onEnter(Character* prsn, Tile* fromTile) override;
    void getItem(Item* itm);
    virtual bool EnemyAcces() override;


    virtual ~Floor();
private:
    Item* item;
};

#endif /* FLOOR_H */

