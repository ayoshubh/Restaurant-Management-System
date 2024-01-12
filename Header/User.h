/**
 * @file User.h
 * @author Shubham Chauhan
 * @brief This file contains declarations for User file.
 * @version 0.1
 * @date 2024-01-12
 * @copyright Copyright (c) 2024
 */

#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include "Restaurant.h"
class User : protected Restaurant {
private:
    std::string firstName, lastName, fullName; // these strings store the name details of the user

public:
    void setFirstName(std::string name);
    void setLastName(std::string name);
    std::string getFullName() const;
    bool validateName() const;
    static bool validateEntry();
};

#endif  // USER_H
