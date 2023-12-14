#ifndef STARTERS_H
#define STARTERS_H

#include "Menu.h"
#include <iostream>

class Starters : public Menu {
private:
    std::string fileName;

public:
    Starters();
    void setMenuList();
    void display();
};

#endif // STARTERS_H
