/**
 * @file Starters.h
 * @author Shubham Chauhan
 * @brief This header file contains declarations for Starters class which is inherited from Menu class.
 * @version 0.1
 * @date 2024-01-08
 * @copyright Copyright (c) 2024
 */

#ifndef STARTERS_H
#define STARTERS_H

#include "Menu.h"
#include <iostream>
#include <vector>

class Starters : public Menu {
private:
    std::string fileName; // string used to store the name of the file where menu data is stored.

public:
    Starters();
    void setMenuList();
    std::vector<std::vector<std::string>> getMenuList();
    void display();
};

#endif // STARTERS_H
