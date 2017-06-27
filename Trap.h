#ifndef TRAP_H
#define TRAP_H

#include "Passive.h"

class Trap : public Passive
{
public:
    Trap();

    void onEnter(Character* prsn, Tile* fromTile) override;
    void onLeave(Tile* toTile) override;
    char print() const override;
    virtual bool EnemyAcces() override;


    virtual ~Trap();
private:

};

#endif /* TRAP_H */

