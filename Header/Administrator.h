/**
 * @file Administrator.h
 * @author Shubham Chauhan
 * @brief This header file contains declarations for Administrator class.
 * @version 0.1
 * @date 2024-01-08
 * @copyright Copyright (c) 2024
 */

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "Order.h"
#include <iostream>
#include <fstream>
#include <string>

class Administrator {
private:
    std::string username; // this string will contain the username of the admin
    std::string password; // this string will contain the password of the admin

public:
    Administrator();
    std::string getUsername();
    std::string getPassword();
    std::string getLogbook(std::string date, std::string month, std::string year);
    int totalRevenue(std::string month="", std::string year="");
    float avgRating();
};

#endif // ADMINISTRATOR_H
