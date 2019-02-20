//
// Created by Robin on 16.02.2019.
//

#include <string>

using namespace std;

class Category {
    private:
        string name;
        string description;
        int points;
        bool hasBeenRolled;

public:
        Category(const string &name, const string &description, int points);

        const string &getName() const;

        void setName(const string &name);

        const string &getDescription() const;

        void setDescription(const string &description);

        const int &getPoints() const;

        void setPoints(const int &points);

        bool getHasBeenRolled() const;

        void setHasBeenRolled(bool hasBeenRolled);

};

