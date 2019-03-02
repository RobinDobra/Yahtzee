//
// Created by Robin-Desktop on 18.02.2019.
//

#include "Dice.h"
#include <iostream>

Dice::Dice(const string &name) {
    this->name = name;
    this->value = -1;
    this->isOnHold = false;
}

const string &Dice::getName() const {
    return name;
}

void Dice::setName(const string &name) {
    this->name = name;
}

int Dice::getValue() const {
    return value;
}

void Dice::setValue(int value) {
    this->value = value;
}

bool Dice::getIsOnHold() const {
    return isOnHold;
}

void Dice::setIsOnHold(bool isOnHold) {
    this->isOnHold = isOnHold;
}

Dice::~Dice() {
    cout << "Dice is being deleted" << endl;
    this->name="";
    this->value = -1;
    this->isOnHold = false;
}
