#ifndef MAINCOURSE_H
#define MAINCOURSE_H

#include "Menu.h"
#include <iostream>

class MainCourse : public Menu {
private:
    std::string fileName;

public:
    MainCourse();
    void setMenuList();
    std::vector<std::vector<std::string>> getMenuList();
    void display();
};

#endif // MAINCOURSE_H