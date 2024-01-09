#ifndef RATING_H
#define RATING_H

#include <iostream>
#include <fstream>

class Rating {
public:
    std::string name;
    std::string feedback;
    int choice;
    enum rate {
        oneStar = 1,
        twoStar,
        threeStar,
        fourStar,
        fiveStar
    };

    void takeRating();
    void setRating(int rate);
    void displayRating();
    void setFeedback(std::string feedback);
};

#endif // RATING_H
