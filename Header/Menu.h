#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Menu {
protected:
    int itemId;
    std::string itemName;
    int itemPrice;
    std::string singleItemDetail;
    std::vector<std::string> singleItemList;
    std::vector<std::vector<std::string>> menuList;

public:
    virtual void display() = 0;
    std::vector<std::vector<std::string>> getMenu(std::string filename);
};

#endif // MENU_H
