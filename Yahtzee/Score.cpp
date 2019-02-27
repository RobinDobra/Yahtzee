//
// Created by Robin on 16.02.2019.
//

#include "Score.h"
#include <iostream> //benötigt?

using namespace std;

Score::Score()
{
    this->upperScore = 0;
    this->lowerScore = 0;
    this->totalScore = upperScore + lowerScore;
}

int Score::getLowerScore() const {
    return lowerScore;
}

void Score::setLowerScore(int lowerScore) {
    this->lowerScore = lowerScore;
    setTotalScore(lowerScore + this->getUpperScore());
}

int Score::getUpperScore() const {
    return upperScore;
}

void Score::setUpperScore(int upperScore) {
    this->upperScore = upperScore;
    setTotalScore(upperScore + this->getLowerScore());
}

int Score::getTotalScore() const {
    return totalScore;
}

void Score::setTotalScore(int totalScore) {
    this->totalScore = totalScore;
}

Score::~Score() {
    cout << "Score is being deleted" << endl;
    this->upperScore = 0;
    this->lowerScore = 0;
    this->totalScore = 0;
};