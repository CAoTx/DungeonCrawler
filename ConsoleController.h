#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H

#include "Controller.h" 

class ConsoleController :virtual public Controller
{
public:
    ConsoleController();
    int move() override;
    virtual ~ConsoleController();
private:

};

#endif /* CONSOLECONTROLLER_H */

