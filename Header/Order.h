/**
 * @file Order.h
 * @author Shubham Chauhan
 * @brief This file contains declarations for Order Class.
 * @version 0.1
 * @date 2024-01-09
 * @copyright Copyright (c) 2024
 */

#ifndef ORDER_H
#define ORDER_H

#include "Starters.h"
#include "MainCourse.h"
#include "Dessert.h"
#include <iostream>
#include <vector>
#include <unistd.h>  // for usleep

class Order : public Starters, public MainCourse, public Dessert {
protected:
    std::string orderInput; // this string stores itemId separated by comma ordered by user
    std::vector<std::string> orderList; // this vector stores itemId of items ordered by user
    int starterPrice, mainCoursePrice, dessertPrice, totalCost;

public:
    Order(std::vector<std::vector<std::string>> sList = {}, std::vector<std::vector<std::string>> mList = {}, std::vector<std::vector<std::string>> dList = {});
    void setOrderInput(std::string orderInp);
    void clearOrderList();
    std::vector<std::string> getOrderList();
    int getStarterOrderCost();
    int getMainCourseOrderCost();
    int getDessertOrderCost();
};

#endif // ORDER_H
