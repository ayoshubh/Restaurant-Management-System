#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <cctype>
#include "Restaurant.h"
class User : protected Restaurant {
private:
    int visitTime;
    std::string firstName, lastName, fullName;

public:
    void setFirstName(std::string name);
    void setLastName(std::string name);
    std::string getFullName() const;
    bool validateName() const;
    static bool validateEntry();
};

#endif  // USER_H
