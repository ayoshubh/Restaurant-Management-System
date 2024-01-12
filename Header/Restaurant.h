/**
 * @file Restaurant.h
 * @author Shubham Chauhan
 * @brief This file contains declaration for Restaurant class.
 * @version 0.1
 * @date 2024-01-10
 * @copyright Copyright (c) 2024
 */
#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>

class Restaurant {
private:
    int openTime; // stores when the restaurant opens
    int closeTime;// stores when the restaurant closes
    std::string restaurantName; // stores the restaurant name
    std::string phone; // stores the phone no. to contact restaurant
    std::string email; // stores the email id to contact restaurant
    std::string location; // stores the location of the restaurant

public:
    // Constructor
    Restaurant();

    // Member function to show restaurant details
    void showDetails();
};

#endif  // RESTAURANT_H
