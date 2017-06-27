#ifndef ATTACKCONTROLLER_H
#define ATTACKCONTROLLER_H

#include "Controller.h"



class AttackController :virtual public Controller
{
public:
    AttackController();
    int move() override;
    virtual ~AttackController();
private:

};

#endif /* ATTACKCONTROLLER_H */

