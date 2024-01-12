/**
 * @file Menu.h
 * @author Shubham Chauhan
 * @brief This header file contains declarations for Menu class.
 * @version 0.1
 * @date 2024-01-08
 * @copyright Copyright (c) 2024
 */

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Menu {
protected:
    std::string singleItemDetail; //this string stores item id, name and price of a single item separated by a '-'
    std::vector<std::vector<std::string>> menuList; //stores details of different items {{itemId1,itemName1,price1},{itemId2,itemName2,price2},..,}

public:
    virtual void display() = 0; //this is a pure virtual function which will be implemented in Menu's child classes.
    std::vector<std::vector<std::string>> getMenu(std::string filename);
};

#endif // MENU_H
