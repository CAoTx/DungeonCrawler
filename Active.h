#ifndef ACTIVE_H
#define ACTIVE_H

#include "Passive.h"

class Active : public Tile
{
public:

    Active(Passive* brthr);

    void setstat(const bool& newstat);
    bool getstat() const;
    void setbrother(Passive* newbrthr);

    virtual char print() const override = 0;
    virtual void onEnter(Character* prsn, Tile* fromTile) override = 0;
    virtual void onLeave(Tile* toTile) override = 0;


    virtual ~Active();
protected:
    bool active;
    Passive* brother;
};

#endif /* ACTIVE_H */

