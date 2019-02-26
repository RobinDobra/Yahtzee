#include "Score.h"
#include "Category.h"
#include "Dice.h"
#include <iostream>
#include <random>

using namespace std;

static const int numberOfCategories = 13;
static const int numberOfDices = 5;

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
    categories [0] = new Category("Einsen", "Summe aller geworfenen Einsen");
    categories [1] = new Category("Zweien", "Summe aller geworfenen Zweien");
    categories [2] = new Category("Dreien", "Summe aller geworfenen Dreien");
    categories [3] = new Category("Vieren", "Summe aller geworfenen Vieren");
    categories [4] = new Category("Fuenfen", "Summe aller geworfenen Fuenfen");
    categories [5] = new Category("Sechsen", "Summe aller geworfenen Sechsen");
    categories [6] = new Category("Drei Gleiche", "Summe aller Wuerfel, wobei drei Gleiche enthalten sein muessen");
    categories [7] = new Category("Vier Gleiche", "Summe aller Wuerfel, wobei vier Gleiche enthalten sein muessen");
    categories [8] = new Category("Full House", "Summe aller Wuerfel, wobei zwei Gleiche und drei andere Gleiche enthalten sein muessen - 25 Punkte");
    categories [9] = new Category("Kleine Strasse", "Vier aufeinanderfolgende Augenzahlen (z.B. 2-3-4-5) - 30 Punkte");
    categories [10] = new Category("Grosse Strasse", "Fuenf aufeinanderfolgende Augenzahlen (z.B. 2-3-4-5-6) - 40 Punkte");
    categories [11] = new Category("Chance", "Die Summe einer beliebigen Wuerfelkombination");
    categories [12] = new Category("Yahtzee", "Alle fuenf Wuerfel zeigen dieselbe Zahl - 50 Punkte");
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
}

void throwDices(Dice * dices[numberOfDices]) {
    mt19937 rng; //Mersenne-Twister Pseudo-Zufallszahlengenerator
    rng.seed(random_device()()); // initialisiere Seed
    uniform_int_distribution <mt19937::result_type> limits(1,6); // Zahlen in den Grenzen von 1 bis 6
    for (int i = 0; i < numberOfDices; i++) {
        if (dices[i]->getIsOnHold() == false) {
            dices[i]->setValue(limits(rng));
        } else if (dices[i]->getIsOnHold() == true) {
            //cout << "Wert fuer " << dices[i]->getName() << ": " << dices[i]->getValue() << " # wird gehalten" << endl;
        }
    }
}

string chooseDicesToHold (Dice * dices[numberOfDices], int anzahlWuerfe){
    string userInput;
    // Zurücksetzen nach jedem Wurf

    bool isInLimits;

    do {
        // cout << "----------------------------------------------" << endl;
        cout << "### Dies ist Wurf " << anzahlWuerfe << " von 3 ###" << endl << endl;
        for (int i = 0; i < numberOfDices; i++) {
            if (dices[i]->getIsOnHold() == false) {
                cout << "Wert fuer " << dices[i]->getName() << ": " << dices[i]->getValue() << endl;
            } else if (dices[i]->getIsOnHold() == true) {
                cout << "Wert fuer " << dices[i]->getName() << ": " << dices[i]->getValue() << " # wird gehalten" << endl;
            }
        }


        cout << endl;
        if (anzahlWuerfe < 20) {
            cout << "Wenn Sie einen Wuerfel halten moechten, geben Sie dessen Nummer ein. " << endl;
            cout << "Geben Sie ein r ein, um erneut zu rollen." << endl;
        }
        cout << "Geben Sie ein s ein, um den Wurf zu speichern." << endl;
        cout << endl << "Ihre Eingabe: ";

        getline(cin, userInput);
        isInLimits = atoi(userInput.c_str()) > 0 && atoi(userInput.c_str()) < 7;

        while (!isInLimits && userInput != "r" && userInput != "s") {
            cout << "Bitte treffen Sie eine gueltige Auswahl: ";
            getline(cin, userInput);
            cout << endl;
            isInLimits = atoi(userInput.c_str()) > 0 && atoi(userInput.c_str()) < 7;
        }

        if (isInLimits && anzahlWuerfe < 20) {
            if (dices[atoi(userInput.c_str()) - 1]->getIsOnHold() == false) {
                dices[atoi(userInput.c_str()) - 1]->setIsOnHold(true);
            } else {
                dices[atoi(userInput.c_str()) - 1]->setIsOnHold(false);
            }

        }
    } while (isInLimits);

    return userInput;
}

int saveToCategory (Category * categories[numberOfCategories], Dice * dices[numberOfDices]) {
    string userInput;
    bool isInLimits = false;

    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

    for (int i = 0; i < numberOfCategories; i++) {
        string resizedName = categories[i]->getName();
        string resizedCounter = to_string(i + 1) + ": ";
        resizedName.resize(14);
        resizedCounter.resize(4);
        cout << resizedCounter << resizedName << " | " << categories[i]->getDescription();
        if (categories[i]->getHasBeenRolled() == true) {
            cout << ": <- Wurf:  " << categories[i]->getPoints() << " Punkte.";
        }
        cout << endl;
    }
    while (!isInLimits) {
        cout << "### Geben Sie die Nummer der Kategorie an, in der Sie ihren Wurf speichern wollen: ###" << endl;
        cin >> userInput;
        isInLimits = atoi(userInput.c_str()) > 0 && atoi(userInput.c_str()) <= numberOfCategories;
    }
    int categoryNumber = atoi(userInput.c_str());

    return categoryNumber;

}

void calculatePointsForCategory(Category * categories[numberOfCategories], Dice * dices[numberOfDices], int categoryNumber) {
    int countPoints = 0;
    // ### calculateRound
    if (categoryNumber >= 1 && categoryNumber <=6 ) {   // Einses, Zweien ... Sechsen
        for (int i = 0; i < numberOfDices; i++) {
            if (categoryNumber == dices[i]->getValue()) {
                countPoints++;
            }
        }
        countPoints = countPoints * categoryNumber;
        categories[categoryNumber - 1]->setPoints(countPoints);
    }
    else if (categoryNumber == 7) {   // Drei Gleiche
        int occurences1 = dices[0]->getValue(); int counter1 = 0;
        int occurences2 = dices[1]->getValue(); int counter2 = 0;
        int occurences3 = dices[2]->getValue(); int counter3 = 0;
        int occurences4 = dices[3]->getValue(); int counter4 = 0;
        int totalValue = 0;
        for (int i = 0; i < numberOfDices; i++) {
            if (occurences1 == dices[i]->getValue()) {
                counter1++;
            } else if (occurences2 == dices[i]->getValue()){
                counter2++;
            } else if (occurences3 == dices[i]->getValue()){
                counter3++;
            } else if (occurences4 == dices[i]->getValue()){
                counter4++;
            }

            totalValue += dices[i]->getValue();
        }

        if (counter1 >= 3 || counter2 >= 3|| counter3 >= 3 || counter4 >= 3) {
            categories[categoryNumber - 1]->setPoints(totalValue);
        }
        else {
            cout << "### Leider keine drei Gleichen. ###" << endl;
        }

        cout << "Punkte insgesamt: " << categories[categoryNumber - 1]->getPoints() << endl;
    }
    else if (categoryNumber == 8) {  // Vier Gleiche
        int occurences1 = dices[0]->getValue(); int counter1 = 0;
        int occurences2 = dices[1]->getValue(); int counter2 = 0;
        int totalValue = 0;
        cout << "occ1: " << occurences1 << endl;
        cout << "occ2: " << occurences1 << endl;
        for (int i = 0; i < numberOfDices; i++) {
            if (occurences1 == dices[i]->getValue()) {

                counter1++;
                cout << "counter1: " << counter1 << endl;
            } else if (occurences2 == dices[i]->getValue()) {
                counter2++;
                cout << "counter2: " << counter2 << endl;
            }
            totalValue += dices[i]->getValue();


        }
        if (counter1 >= 4 || counter2 >= 4) {
            categories[categoryNumber - 1]->setPoints(totalValue);

        }
        else {
            cout << "### Leider keine vier Gleichen. ###" << endl;
        }
        cout << "Punkte insgesamt: " << categories[categoryNumber - 1]->getPoints() << endl;
    }

    else if (categoryNumber == 9) {  // Full House
        cout << "a" << endl;

        int occurences1 = dices[0]->getValue(); int counter1 = 0;
        int occurences2 = dices[1]->getValue(); int counter2 = 0;
        for (int i = 0; i < numberOfDices; i++) {
            cout << "b" << i << endl;
            if (occurences1 == dices[i]->getValue()) {
                counter1++;
            } else if (occurences2 == dices[i]->getValue()) {
                counter2++;
            }
        }
        if ( (counter1 == 3 && counter2 == 2) || (counter1 == 2 && counter2 == 3) ) {
            cout << "c" << endl;
            cout << "### Full House! ###" << endl;
            categories[categoryNumber - 1]->setPoints(25);
        }
        else {
            cout << "### Leider kein Full House. ###" << endl;
        }

        cout << "###############################################" << endl;
        cout << endl << endl;


    }

    else if (categoryNumber == 10) { // Kleine Straße
        int occurences[] = {0, 0, 0, 0, 0, 0};
        for (int i = 0; i < numberOfDices; i++) {
            occurences[dices[i]->getValue() - 1]++; // Zaehlt die Vorkommen aller Zahlen und zählt hoch
        }
        if (    (occurences[0] >= 1 && occurences[1] >= 1 && occurences[2] >= 1 && occurences[3] >= 1) ||  // 1, 2, 3, 4
                (occurences[1] >= 1 && occurences[2] >= 1 && occurences[3] >= 1 && occurences[4] >= 1) ||  // 2, 3, 4, 5
                (occurences[2] >= 1 && occurences[3] >= 1 && occurences[4] >= 1 && occurences[5] >= 1)  )  // 3, 4, 5, 6
        {
            cout << "e" << endl;
            cout << "### Kleine Strasse! ###" << endl;
            categories[categoryNumber - 1]->setPoints(30);
        }
        else {
            cout << "### Leider keine kleine Strasse. ###" << endl;
        }
    }
    else if (categoryNumber == 11) {
        int occurences[] = {0, 0, 0, 0, 0, 0};

        for (int i = 0; i < numberOfDices; i++) {
            occurences[dices[i]->getValue() - 1]++; // Zaehlt die Vorkommen aller Zahlen und zählt hoch
        }
        if (    (occurences[0] >= 1 && occurences[1] >= 1 && occurences[2] >= 1 && occurences[3] >= 1 && occurences[4] >= 1) ||  // 1, 2, 3, 4, 5
                (occurences[1] >= 1 && occurences[2] >= 1 && occurences[3] >= 1 && occurences[4] >= 1 && occurences[5] >= 1)       )  // 2, 3, 4, 5, 6
        {
            cout << "### Grosse Strasse! ###" << endl;
            categories[categoryNumber - 1]->setPoints(40);
        }
        else {
            cout << "### Leider keine grosse Strasse. ###" << endl;
        }
    }

    else if (categoryNumber == 12) {
        int sum = 0;
        for (int i = 0; i < numberOfDices; i++) {
            sum += dices[i]->getValue();
        }
        categories[categoryNumber - 1]->setPoints(sum);
        cout << "Ihre Chance hat " << sum << "Punkte eingebracht!";
    }

    else if(categoryNumber == 13) {
        int v1 = 0, v2 = 0, v3 = 0, v4 = 0, v5 = 0, v6 = 0;
        for (int i = 0; i < numberOfDices; i++) {
            int tempValue = dices[i]->getValue();
            if (tempValue == 1) {
                v1++;
            } else if (tempValue == 2) {
                v2++;
            } else if (tempValue == 3) {
                v3++;
            } else if (tempValue == 4) {
                v4++;
            } else if (tempValue == 5) {
                v5++;
            } else if (tempValue == 6) {
                v6++;
            }
           //v1 =  occurences[(dices[i]->getValue())] + 1 ; // Zaehlt die Vorkommen aller Zahlen und zählt hoch
         /*   occurences[dices[5-1]] = occurences[5-1];
            occurences[dices]*/
        }
        if (v1 == 5 || v2 == 5 || v3 == 5 || v4 == 5 || v5 ==5 || v6 == 5) {
            cout << "### Yahtzee! ###" << endl;
            categories[categoryNumber - 1]->setPoints(40);
        }
        else {
            cout << "### Leider kein Yahtzee ###" << endl;
        }
    }
    categories[categoryNumber - 1]->setHasBeenRolled(true);
}

void calculateScore(Category * categories[numberOfCategories], Score * score) {
    int updatedScore;
    for (int i = 0; i < 6; i++) {
        updatedScore = score->getUpperScore() + categories[i]->getPoints();
        score->setUpperScore(updatedScore);
    }
    for (int i = 6; i < numberOfCategories; i++) {
        updatedScore = score->getLowerScore() + categories[i]->getPoints();
        score->setLowerScore(updatedScore);
    }
}


void endScreen(Category * categories[numberOfCategories], Score * score) {
    for (int i = 0; i < numberOfCategories; i++) {
        string resizedCounter = to_string(i + 1) + ": ";
        string resizedName = categories[i]->getName();
        string resizedPoint = to_string(categories[i]->getPoints());
        resizedCounter.resize(4);
        resizedName.resize(22);
        resizedPoint.resize(10);
        cout << resizedCounter << resizedName << " | " << resizedPoint << " | " << categories[i]->getDescription() << endl;

        if (i == 5) {
            cout << "__________________________________________________________________________________" << endl;
            cout << "Punktestand oberes Segment: " << score->getUpperScore() << endl << endl;

        } else if (i == 12) {
            cout << "__________________________________________________________________________________" << endl;
            cout << "Punktestand unteres Segment: " << score->getLowerScore() << endl << endl << endl;

        }
    }
    cout << "Ihre Gesamtpunktzahl betraegt: " << score->getTotalScore() << " Punkte." << endl;
}

int main() {

    // Konstanten
    string userInput = "unset";
    int chosenCategory;
    int anzahlWuerfe = 0;

    // Kategorien
    Category * categories[numberOfCategories];
    categories[numberOfCategories] = populateCategories(categories);

    // Score
    Score *score = new Score(); // initialisiert den Punktestand (upper, lower, total)

    // Wuerfel
    Dice * dices[numberOfDices];
    populateDices(dices);

    // Spiel
    startScreen();
    calculateScore(categories, score);
    endScreen(categories, score);

    for (int rundenNummer = 1; rundenNummer <= 13; rundenNummer++) {
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Das ist Runde Nummer " << rundenNummer << "! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        while (userInput != "s" && anzahlWuerfe < 20) {

            anzahlWuerfe++;
            throwDices(dices);
            userInput = chooseDicesToHold(dices, anzahlWuerfe);
        }

        chosenCategory = saveToCategory(categories, dices);
        calculatePointsForCategory(categories, dices, chosenCategory);

        userInput = "unset";
        anzahlWuerfe = 0;
        for (int i = 0; i < numberOfDices; i++) {
            dices[i]->setIsOnHold(false); // Nach jeder Runde die festgehaltenen Wuerfel zuruecksetzen
        }

    }
    calculateScore(categories, score);
    endScreen(categories, score);
    return 0;
}