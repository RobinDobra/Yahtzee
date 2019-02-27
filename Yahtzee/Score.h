//
// Created by Robin on 16.02.2019.
//

class Score
{
    private:
        int lowerScore;
        int upperScore;
        int totalScore;

    public:
        Score();

        int getLowerScore() const;

        void setLowerScore(int lowerScore);

        int getUpperScore() const;

        void setUpperScore(int upperScore);

        int getTotalScore() const;

        void setTotalScore(int totalScore);

        ~Score();
};
