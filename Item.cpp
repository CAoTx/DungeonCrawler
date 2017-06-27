#include "Item.h"

Item::Item() {
}

char Item::print() const {
    return sign;
}

Item::~Item() {
}

ArmingSword::ArmingSword() : Item() {
}

int ArmingSword::modifyStamina(const int& stam) const {
    return 0;
}

int ArmingSword::modifyStrength(const int& strn) const {
    return 3;
}

ArmingSword::~ArmingSword()  {
}

GreatSword::GreatSword(): Item() {
}

int GreatSword::modifyStamina(const int& stam) const {
    return -1;
}

int GreatSword::modifyStrength(const int& strn) const {
    return 5;
}

GreatSword::~GreatSword() {
}

Club::Club() : Item() {
}

int Club::modifyStamina(const int& stam) const {
    return 0;
}

int Club::modifyStrength(const int& strn) const {
    return 1;
}

Club::~Club() {
}

RapierNDagger::RapierNDagger() : Item() {
}

int RapierNDagger::modifyStamina(const int& stam) const {
    int var;
    var = (stam * 1.5) - stam;
    return var;
}

int RapierNDagger::modifyStrength(const int& strn) const {
    return 2;
}

RapierNDagger::~RapierNDagger() {
}

Gambeson::Gambeson() : Item() {
}

int Gambeson::modifyStamina(const int& stam) const {
    return 1;
}

int Gambeson::modifyStrength(const int& strn) const {
    return 0;
}

Gambeson::~Gambeson() {
}

MailArmour::MailArmour() : Item() {
}

int MailArmour::modifyStamina(const int& stam) const {
    return 3;
}

int MailArmour::modifyStrength(const int& strn) const {
    return 0;
}

MailArmour::~MailArmour() {
}

Shield::Shield() : Item() {
}

int Shield::modifyStamina(const int& stam) const {
    return (stam * 2);
}

int Shield::modifyStrength(const int& strn) const {
    return -1;
}

Shield::~Shield() {
}

FullPlateArmour::FullPlateArmour() : Item() {
}

int FullPlateArmour::modifyStamina(const int& stam) const {
    return 6;
}

int FullPlateArmour::modifyStrength(const int& strn) const {
    return -2;
}

FullPlateArmour::~FullPlateArmour() {

}
