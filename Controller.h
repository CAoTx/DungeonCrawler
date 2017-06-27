#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

class Character;

class Controller {
public:
    Controller();

    void setprsn(Character* brthr);
    Character* getprsn() const;

    virtual int move() = 0;

    virtual ~Controller();
private:
    Character* brother;
};

#endif /* CONTROLLER_H */

