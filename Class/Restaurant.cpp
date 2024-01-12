/**
 * @file Restaurant.cpp
 * @author Shubham Chauhan
 * @brief This file contains the implementation details for the Restaurant file
 * @version 0.1
 * @date 2024-01-10
 * @copyright Copyright (c) 2024
 */
#include "Restaurant.h"

/**
 * @brief Construct a new Restaurant:: Restaurant object
 */
Restaurant::Restaurant() {
    openTime = 10;
    closeTime = 12;
    restaurantName = "Food Villa";
    location = "Vadodara, Gujarat";
    phone = "+91 9009009001";
    email = "foodvilla@gmail.com";
}

/**
 * @brief Member function definition to show restaurant details
 */
void Restaurant::showDetails() {
    std::cout << " \n**********  Welcome to our Restaurant " << restaurantName << "  ********** " << std::endl;
    std::cout << "We are located in " << location << std::endl;
    std::cout << "We are open all the 7 days of the week from " << openTime << "am to " << closeTime << "pm" << std::endl;
    std::cout << "You can reach us out on " << phone << " by phone or email us at " << email << "\n";
    std::cout << "We have multiple chains across Gujarat.\n";
    std::cout << "Have a nice day :) \n";
}
