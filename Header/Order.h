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
    std::string orderInput;
    std::string fileName;
    std::vector<std::string> orderList;
    std::vector<std::string> EmptyOrderList;
    int starterPrice, mainCoursePrice, dessertPrice, totalCost;

public:
    Order(std::vector<std::vector<std::string>> sList = {}, std::vector<std::vector<std::string>> mList = {}, std::vector<std::vector<std::string>> dList = {});
    void setOrderInput(std::string orderInp);
    void setOrderList();
    std::vector<std::string> getOrderList();
    int getStarterOrderCost();
    int getMainCourseOrderCost();
    int getDessertOrderCost();
};

#endif // ORDER_H
