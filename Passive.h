#ifndef PASSIVE_H
#define PASSIVE_H

#include "Tile.h"

class Passive : public Tile
{
public:
    Passive(Character* prsn);

    void setstat(bool newstat);
    bool getstat()const;

    virtual char print() const override = 0;
    virtual void onEnter(Character* prsn, Tile* fromTile) override = 0;
    virtual void onLeave(Tile* toTile) override = 0;


    virtual ~Passive();
private:
    bool status;
};

#endif /* PASSIVE_H */

