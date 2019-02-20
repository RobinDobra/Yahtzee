//
// Created by Robin on 16.02.2019.
//

#include "Category.h"

Category::Category(const string &name, const string &description, int points) {
    Category::name = name;
    Category::description = description;
    Category::points = points;
    Category::hasBeenRolled = false;
}

const string &Category::getName() const {
    return name;
}

void Category::setName(const string &name) {
    Category::name = name;
}

const string &Category::getDescription() const {
    return description;
}

void Category::setDescription(const string &description) {
    Category::description = description;
}

const int &Category::getPoints() const {
    return points;
}

void Category::setPoints(const int &points) {
    Category::points = points;
}

bool Category::getHasBeenRolled() const {
    return hasBeenRolled;
}

void Category::setHasBeenRolled(bool hasBeenRolled) {
    Category::hasBeenRolled = hasBeenRolled;
}




