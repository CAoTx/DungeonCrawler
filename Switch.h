#ifndef SWITCH_H
#define SWITCH_H

#include "Active.h"

class Switch : public Active
{
public:

    Switch(Passive* brthr);

    char print() const override;
    void onEnter(Character* prsn, Tile* fromTile) override;
    void onLeave(Tile* toTile) override;
    virtual bool EnemyAcces() override;


    virtual ~Switch();
private:
};

#endif /* SWITCH_H */

