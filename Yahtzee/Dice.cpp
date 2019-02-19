//
// Created by Robin-Desktop on 18.02.2019.
//

#include "Dice.h"

Dice::Dice(const string &name) {
    Dice::name = name;
    Dice::value = -1;
    Dice::isOnHold = false;
}

const string &Dice::getName() const {
    return name;
}

void Dice::setName(const string &name) {
    Dice::name = name;
}

int Dice::getValue() const {
    return value;
}

void Dice::setValue(int value) {
    Dice::value = value;
}

bool Dice::getIsOnHold() const {
    return isOnHold;
}

void Dice::setIsOnHold(bool isOnHold) {
    Dice::isOnHold = isOnHold;
}
