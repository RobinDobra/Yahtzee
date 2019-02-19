#include "Score.h"
#include "Category.h"
#include "Dice.h"
#include <iostream>
#include <random>
#include <string>
#include <map>
#include <iterator>

using namespace std;

static const int numberOfCategories = 13;
static const int numberOfDices = 6;

void printCategory(Category * categories, Score *score, int numberOfCategories) {
    score->setUpperScore(5);
    score->setLowerScore(14);
    score->setUpperScore(7);
    for (int i = 0; i < numberOfCategories; i++) { //Gesamtanzahl der Bytes in category geteilt durch Größe des Datentyps [Funktioniert möglicheweise nicht bei Pointern]
        //printf()
        cout << categories[i].getName() << endl;
        if (categories[i].getName() == "Sechsen") {
            cout << "Punktestand des oberen Abschnitts: " << score->getUpperScore() << endl << endl;
        }
        else if (categories[i].getName() == "Yahtzee") {
            cout << "Punktestand des unteren Abschnitts: " << score->getLowerScore() << endl << endl;
        }
    }
    cout << "Gesamtpunktestand: " << score->getTotalScore() << endl << endl;
}

Category * populateCategories(Category * categories[numberOfCategories]) {
    categories [0] = new Category("Einsen", "Summe aller geworfenen Einsen", 0);
    categories [1] = new Category("Zweien", "Summe aller geworfenen Zweien", 0);
    categories [2] = new Category("Dreien", "Summe aller geworfenen Dreien", 0);
    categories [3] = new Category("Vieren", "Summe aller geworfenen Vieren", 0);
    categories [4] = new Category("Fuenfen", "Summe aller geworfenen Fuenfen", 0);
    categories [5] = new Category("Sechsen", "Summe aller geworfenen Sechsen", 0);
    categories [6] = new Category("Drei Gleiche", "Summe aller Wuerfel, wobei drei Gleiche enthalten sein müssen", 0);
    categories [7] = new Category("Vier Gleiche", "Summe aller Wuerfel, wobei vier Gleiche enthalten sein müssen", 0);
    categories [8] = new Category("Full House", "Summe aller Wuerfel, wobei zwei Gleiche und drei andere Gleiche enthalten sein müssen - 25 Punkte", 25);
    categories [9] = new Category("Kleine Straße", "Vier aufeinanderfolgende Augenzahlen (z.B. 2-3-4-5) - 30 Punkte", 30);
    categories [10] = new Category("Große Straße", "Fuenf aufeinanderfolgende Augenzahlen (z.B. 2-3-4-5-6) - 40 Punkte", 40);
    categories [11] = new Category("Chance", "Die Summe einer beliebigen Wuerfelkombination", 0);
    categories [12] = new Category("Yahtzee", "Alle fuenf Wuerfel zeigen dieselbe Zahl - 50 Punkte", 50);
    return categories[numberOfCategories];
}

void startScreen() {
    cout << "Willkommen bei Yahtzee/Kniffel!" << endl;
    cout << "1) Partie beginnen" << endl;
    cout << "2) Programm beenden" << endl;
    cout << endl;

}

void showMenu() {
    cout << "Sie haben bereits x von 13 mal gewuerfelt" << endl; //ToDo
    cout << "1) Werfe Wuerfel" << endl;
    cout << "2) Zeige Kategorien" << endl;
    cout << "3) Zeige Kategorien mit Beschreibungen" << endl;
    cout << "4) Partie neustarten" << endl;
    cout << "5) Programm beenden" << endl;
    cout << endl;
}

void populateDices(Dice * dices[numberOfDices]) {
    dices[0] = new Dice("Wuerfel 1");
    dices[1] = new Dice("Wuerfel 2");
    dices[2] = new Dice("Wuerfel 3");
    dices[3] = new Dice("Wuerfel 4");
    dices[4] = new Dice("Wuerfel 5");
    dices[5] = new Dice("Wuerfel 6");
}

void throwDices(mt19937 rng,uniform_int_distribution <mt19937::result_type> limits, Dice * dices[numberOfDices]) {
    for (int i = 0; i < numberOfDices; i++) {
        if (dices[i]->getIsOnHold() == false) {
            dices[i]->setValue(limits(rng));
        }
    }
}

void chooseDicesToHold (Dice * dices[numberOfDices]){
    string input;

    for (int i = 0; i < numberOfDices; i++) {
        if (dices[i]->getIsOnHold() == false) {
            cout << "Wert fuer " << dices[i]->getName() << ": " << dices[i]->getValue() << endl;
        }
    }
    cout << endl;
    cout << "Wenn Sie einen Wuerfel halten moechten, geben Sie dessen Nummer ein. " << endl;
    cout << "Geben Sie ein r ein, um erneut zu rollen." << endl;
    cout << "Geben Sie ein s ein, um den Wurf zu speichern." << endl;
    cout << endl << "Ihre Eingabe: ";
    getline(cin,input);
    cout << endl;

    while( ( atoi(input.c_str()) < 1 || atoi(input.c_str()) > 6 ) && input != "r" && input != "s" ) {
        cout << "Bitte treffen Sie eine gueltige Auswahl: ";
        getline(cin,input);
        cout << endl;
    }


/*
    while (input < 1 || input > 6 ) {
        for (int i = 0; i < 6; i++) {
            if (dices[i]->getIsOnHold() == false) {
                cout << "Wert fuer " << dices[i]->getName() << ": " << dices[i]->getValue() << endl;
            } else if (dices[i]->getIsOnHold() == true) {
                cout << "Wert fuer " << dices[i]->getName() << ": " << dices[i]->getValue() << " # wird gehalten" << endl;
            }
        }
        */

}

void chooseCategory (Category categories[numberOfCategories], Dice * dices[numberOfDices]) {
    cout << "In welcher Kategorie moechten Sie Ihren Wurf speichern?" << endl;
    for ( int i = 0; i < numberOfCategories; i++) {
        cout << categories[i].getName() << endl;
    }
}

int main() {
    // Kategorien
    Category * categories[numberOfCategories];
    categories[numberOfCategories] = populateCategories(categories);

    // Score
    Score *score = new Score(); // initialisiert den Punktestand (upper, lower, total)

    // Zufallszahlen
    mt19937 rng; //Mersenne-Twister Pseudo-Zufallszahlengenerator
    rng.seed(random_device()()); // initialisiere Seed
    uniform_int_distribution <mt19937::result_type> limits(1,6); // Zahlen in den Grenzen von 1 bis 6

    // Wuerfel
    Dice * dices[numberOfDices];
    populateDices(dices);


    // Spiel
    startScreen();

    throwDices(rng, limits, dices);
    chooseDicesToHold(dices);
    chooseCategory(*categories, dices);


    return 0;
}