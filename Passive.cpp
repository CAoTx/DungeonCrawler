#include "Passive.h"

Passive::Passive(Character* prsn) : Tile(prsn) {
}

void Passive::setstat(bool newstat) {
    this->status = newstat;
}

bool Passive::getstat() const {
    return status;
}

Passive::~Passive() {
}

