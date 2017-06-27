#ifndef LEVER_H
#define LEVER_H
#include "Active.h"

class Lever : public Active
{
public:
    Lever(Passive* brthr);

    void onEnter(Character* prsn, Tile* fromTile) override;
    void onLeave(Tile* toTile) override;
    char print() const override;
    virtual bool EnemyAcces() override;



    virtual ~Lever();
private:
};

#endif /* LEVER_H */

