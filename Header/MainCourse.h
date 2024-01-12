/**
 * @file MainCourse.h
 * @author Shubham Chauhan
 * @brief This header file contains declarations for MainCourse class which is inherited from Menu class.
 * @version 0.1
 * @date 2024-01-08
 * @copyright Copyright (c) 2024
 */

#ifndef MAINCOURSE_H
#define MAINCOURSE_H

#include "Menu.h"
#include <iostream>

class MainCourse : public Menu {
private:
    std::string fileName; // string used to store the name of the file where menu data is stored.

public:
    MainCourse();
    void setMenuList();
    std::vector<std::vector<std::string>> getMenuList();
    void display();
};

#endif // MAINCOURSE_H
