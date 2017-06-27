#ifndef STANIONARYCONTROLLER_H
#define STANIONARYCONTROLLER_H
#include "Controller.h"

class StanionaryController : public Controller {
public:
    StanionaryController();

    int move() override;;
    virtual ~StanionaryController();
private:
};

#endif /* STANIONARYCONTROLLER_H */

