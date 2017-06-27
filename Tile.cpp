#include "Tile.h"

Tile::Tile(Character* prsn) {
    this->person = prsn;
}

Character* Tile::getprsn() const {
    return person;
}

void Tile::setprsn(Character* newprsn) {
    this->person = newprsn;
}

bool Tile::hasCharacter() const {
    if (person == nullptr)
        return false;
    else return true;
}

void Tile::onLeave(Tile* toTile) {
    if (toTile->hasCharacter() == false) {
        toTile->onEnter(this->person, & * this);
        this ->person = nullptr;
    } else if (toTile->getprsn() == this->person)
        return;
    else throw "onLeave() error";
}

void Tile::onEnter(Character* prsn, Tile* fromTile) {
    if (hasCharacter() == 0)
        this->person = prsn;
    else fromTile->onEnter(prsn, & * this);
}

Tile::~Tile() {
}

