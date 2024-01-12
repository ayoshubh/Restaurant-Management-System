/**
 * @file Rating.h
 * @author Shubham Chauhan
 * @brief This file contains declaration for Rating file.
 * @version 0.1
 * @date 2024-01-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef RATING_H
#define RATING_H

#include <iostream>
#include <fstream>

class Rating {
public:
    std::string feedback;
    int choice;
    enum rate {
        oneStar = 1,
        twoStar,
        threeStar,
        fourStar,
        fiveStar
    };

    void showRatingLevel();
    void setRating(int rate);
    void displayResponse();
    void setFeedback(std::string feedback);
};

#endif // RATING_H
