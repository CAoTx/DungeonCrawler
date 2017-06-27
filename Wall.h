#ifndef WALL_H
#define WALL_H

#include "Tile.h"

class Wall : public Tile
{
public:

    Wall(Character* prsn);

    char print() const override;
    void onEnter(Character* prsn, Tile* fromTile) override;
    void onLeave(Tile* toTile) override;
    bool isTransparent() override;
    virtual bool EnemyAcces() override;



    virtual ~Wall();
private:

};

#endif /* WALL_H */

