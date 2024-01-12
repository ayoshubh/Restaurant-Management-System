/**
 * @file User.cpp
 * @author Shubham Chauhan
 * @brief This file contains implementation for the User class
 * @version 0.1
 * @date 2024-01-10
 * @copyright Copyright (c) 2024
 */

#include "User.h"

/**
 * @brief a setter method to set the firstName of the user before validating the user input 
 * @param name 
 */
void User::setFirstName(std::string name) {
    if (name.size() >= 3 && name.size() <= 20) {
        for (char ch : name) {
            if (!isalpha(ch)) {
                return;
            }
        }
        for (int i = 0; i < name.size(); i++) {
            name[i] = tolower(name[i]);
        }
        firstName = name;
    }
}

/**
 * @brief a setter method to set the lastName of the user before validating the user input 
 * @param name 
 */
void User::setLastName(std::string name) {
    if (name.size() >= 3 && name.size() <= 30) {
        for (char ch : name) {
            if (!isalpha(ch)) {
                return;
            }
        }
        for (int i = 0; i < name.size(); i++) {
            name[i] = tolower(name[i]);
        }
        lastName = name;
        fullName = firstName + " " + lastName;
    }
}

/**
 * @brief Getter method to return full name
 * @return std::string 
 */
std::string User::getFullName() const {
    return fullName;
}

/**
 * @brief method to validate name of the user
 * @return true 
 * @return false 
 */
bool User::validateName() const {
    return !(firstName.empty() || lastName.empty());
}

/**
 * @brief A static method to validate entry of the user in the system.
 * 
 * @return true 
 * @return false 
 */
bool User::validateEntry() {
    auto now = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);
    tm local_time = *std::localtime(&current_time);
    int current_hour = local_time.tm_hour;

    if (10 <= current_hour && current_hour < 22) {
        std::cout << "Welcome to Food Villa \n";
        return true;
    } else {
        std::cout << "Sorry, we are not open right now \n";
        return false;
    }
}
