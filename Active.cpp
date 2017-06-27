#include "Active.h"

Active::Active(Passive* brthr) : Tile(nullptr) {
    this->active = false;
    this->brother = brthr;
}

void Active::setstat(const bool& newstat) {
    this->active = newstat;
}

bool Active::getstat() const {
    return active;
}

void Active::setbrother(Passive* newbrthr) {
    this->brother = newbrthr;
}

Active::~Active() {
}

