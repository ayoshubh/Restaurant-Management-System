#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>

class Restaurant {
private:
    int openTime;
    int closeTime;
    std::string restaurantName;
    std::string phone;
    std::string email;
    std::string location;

public:
    // Constructor
    Restaurant();

    // Member function to show restaurant details
    void showDetails();
};

#endif  // RESTAURANT_H
