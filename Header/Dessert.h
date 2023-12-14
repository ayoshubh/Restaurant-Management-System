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
    void display();
};

#endif // DESSERT_H
