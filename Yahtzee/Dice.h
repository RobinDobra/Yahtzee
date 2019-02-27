//
// Created by Robin-Desktop on 18.02.2019.
//

#include <string>

using namespace std;

class Dice {

    private:
        string name;
        int value;
        bool isOnHold;

    public:
        Dice(const string &name);

        const string &getName() const;

        void setName(const string &name);

        int getValue() const;

        void setValue(int value);

        bool getIsOnHold() const;

        void setIsOnHold(bool isOnHold);

        ~Dice();

};
