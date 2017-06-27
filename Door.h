#ifndef DOOR_H
#define DOOR_H

#include "Passive.h"
#include "Switch.h"

class Door : public Passive {
public:

    Door(Character* prsn);

    char print() const override;
    void onLeave(Tile* toTile) override;
    void onEnter(Character* prsn, Tile* fromTile) override;
    bool isTransparent() override {if (print()=='X')return false; return true;};
    virtual bool EnemyAcces() override;


    
    virtual ~Door();
private:

};

#endif /* DOOR_H */

