#include "Controller.h"

Controller::Controller()
{

}

void Controller::setprsn(Character* brthr)
{
    this->brother = brthr;
}

Character* Controller::getprsn() const
{
    return brother;
}

Controller::~Controller()
{
//    delete brother;
}

