#ifndef STARTERS_H
#define STARTERS_H

#include "Menu.h"
#include <iostream>
#include <vector>

class Starters : public Menu {
private:
    std::string fileName;

public:
    Starters();
    void setMenuList();
    std::vector<std::vector<std::string>> getMenuList();
    void display();
};

#endif // STARTERS_H
