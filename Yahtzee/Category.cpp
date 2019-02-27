//
// Created by Robin on 16.02.2019.
//

#include "Category.h"
#include <iostream>

Category::Category(const string &name, const string &description) {
    this->name = name;
    this->description = description;
    this->points = 0;
    this->hasBeenRolled = false;
}

const string &Category::getName() const {
    return name;
}

void Category::setName(const string &name) {
    this->name = name;
}

const string &Category::getDescription() const {
    return description;
}

void Category::setDescription(const string &description) {
    this->description = description;
}

const int &Category::getPoints() const {
    return points;
}

void Category::setPoints(const int &points) {
    this->points = points;
}

bool Category::getHasBeenRolled() const {
    return hasBeenRolled;
}

void Category::setHasBeenRolled(bool hasBeenRolled) {
    this->hasBeenRolled = hasBeenRolled;
}
/*
Category::~Category() {
    cout << "Category is being deleted" << endl;
    this->name.clear();
    this->description.clear();
    this->points = 0;
    this->hasBeenRolled = false;
}
*/



