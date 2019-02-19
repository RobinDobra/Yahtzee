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

void Score::Output() {
    cout
    << "Punktestand oberer Abschnitt: " << this->upperScore
    << "Punktestand unterer Abschnitt: " << this->lowerScore
    << "Punktestand insgesamt: " << this->totalScore
    << endl;
}

int Score::getLowerScore() const {
    return lowerScore;
}

void Score::setLowerScore(int lowerScore) {
    Score::lowerScore = lowerScore;
    setTotalScore(lowerScore + Score::getUpperScore());
}

int Score::getUpperScore() const {
    return upperScore;
}

void Score::setUpperScore(int upperScore) {
    Score::upperScore = upperScore;
    setTotalScore(upperScore + Score::getLowerScore());
}

int Score::getTotalScore() const {
    return totalScore;
}

void Score::setTotalScore(int totalScore) {
    Score::totalScore = totalScore;
}
