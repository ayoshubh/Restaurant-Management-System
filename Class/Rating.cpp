/**
 * @file Rating.cpp
 * @author Shubham Chauhan
 * @brief This file contains implementation for Rating class
 * @version 0.1
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Rating.h"

/**
 * @brief This method displays the type of rating users can give.
 */
void Rating::showRatingLevel()
{
    try
    {
        std::cout << "\nEnter 1 for Very Bad Experience" << std::endl;
        std::cout << "Enter 2 for Dissatisfied Experience" << std::endl;
        std::cout << "Enter 3 for Somewhat Good Experience" << std::endl;
        std::cout << "Enter 4 for Good Experience" << std::endl;
        std::cout << "Enter 5 for Excellent Experience\n"<< std::endl;
    }
    catch (const std::exception &e)
    {
        // Handle other exceptions
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

/**
 * @brief Setter method to set the choice data member with the rating input given by the user
 * @param rate 
 */
void Rating::setRating(int rate)
{
    choice = rate;
}

/**
 * @brief Setter method to set the feedback string with the user feedback and to write it to external file. 
 * @param feedback 
 */
void Rating::setFeedback(std::string feedback){
    this->feedback=feedback;
    std::ofstream file("TextFiles/Feedback.txt", std::ios::app);
    file<<this->feedback;
    file<<"\n\n";
    file.close();
}

/**
 * @brief This method is used to display the response after user gives rating and 
 * saves the user rating to external file
 */
void Rating::displayResponse()
{
    try
    {
        switch (choice)
        {
        case oneStar:
            std::cout << "We are sorry for your unfavorable experience" << std::endl;
            break;
        case twoStar:
            std::cout << "Thank you for your feedback. We will try our best to give you a satisfactory service" << std::endl;
            break;
        case threeStar:
            std::cout << "Thank you for your feedback." << std::endl;
            break;
        case fourStar:
            std::cout << "We are glad that you liked our service" << std::endl;
            break;
        case fiveStar:
            std::cout << "Thank you for your positive feedback. It means a lot to us" << std::endl;
            break;
        default:
            std::cout << "Invalid response. Please try again" << std::endl;
        }

        std::ofstream file("TextFiles/RatingFile.txt", std::ios::app);
        file << choice << "\n";
        file.close();
    }
    catch (const std::exception &e)
    {
        // Handle other exceptions
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
