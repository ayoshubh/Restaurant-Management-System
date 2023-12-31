#ifndef DESSERT_H
#define DESSERT_H

#include "Menu.h"
#include <iostream>

class Dessert : public Menu {
private:
    std::string fileName;

public:
    Dessert();
    void setMenuList();
    std::vector<std::vector<std::string>> getMenuList();
    void display();
};

#endif // DESSERT_H
