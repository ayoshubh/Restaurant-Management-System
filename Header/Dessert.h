/**
 * @file Dessert.h
 * @author Shubham Chauhan
 * @brief This header file contains declarations for Dessert class.
 * @version 0.1
 * @date 2024-01-08
 * @copyright Copyright (c) 2024
 */

#ifndef DESSERT_H
#define DESSERT_H

#include "Menu.h"
#include <iostream>

class Dessert : public Menu {
private:
    std::string fileName; // string used to store the name of the file where menu data is stored.

public:
    Dessert();
    void setMenuList();
    std::vector<std::vector<std::string>> getMenuList();
    void display();
};

#endif // DESSERT_H
