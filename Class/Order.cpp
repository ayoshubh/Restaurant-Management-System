#include "Order.h"
using namespace std;
void Order::setOrderInput(std::string orderInp) {
    orderInput = orderInp;
}

void Order::setOrderList() {
    this->orderList.clear();
}

std::vector<std::string> Order::getOrderList() {
    bool flag = false;
    std::string singleId;
    
    for (int i = 0; i < orderInput.size(); i++) {
        if (orderInput[i] == ',') {
            orderList.push_back(singleId);
            singleId = "";
        } else {
            singleId += orderInput[i];
            if (i == orderInput.size() - 1) {
                orderList.push_back(singleId);
            }
        }
    }
    return orderList;
}

int Order::getStarterOrderCost() {
    int starterPrice = 0;

    for (int i = 0; i < orderList.size(); i++) {
        bool flag = false;

        for (int j = 0; j < Starters::menuList.size(); j++) {
            if (orderList[i] == Starters::menuList[j][0]) {
                int singleCost = std::stoi(Starters::menuList[j][2]);
                starterPrice += singleCost;
                flag = true;
                break;
            }
        }

        if (!flag) {
            std::cout << "\nItem id " << orderList[i] << " does not exist and hence won't be included in the order." << std::endl;
            usleep(2500000);
        }
    }
    return starterPrice;
}

int Order::getMainCourseOrderCost() {
    int mainCoursePrice = 0;

    for (int i = 0; i < orderList.size(); i++) {
        bool flag = false;

        for (int j = 0; j < MainCourse::menuList.size(); j++) {
            if (orderList[i] == MainCourse::menuList[j][0]) {
                int singleCost = std::stoi(MainCourse::menuList[j][2]);
                mainCoursePrice += singleCost;
                flag = true;
                break;
            }
        }

        if (!flag) {
            std::cout << "\nItem id " << orderList[i] << " does not exist and hence won't be included in the order." << std::endl;
            usleep(2500000);
        }
    }
    return mainCoursePrice;
}

int Order::getDessertOrderCost() {
    int dessertPrice = 0;

    for (int i = 0; i < orderList.size(); i++) {
        bool flag = false;

        for (int j = 0; j < Dessert::menuList.size(); j++) {
            if (orderList[i] == Dessert::menuList[j][0]) {
                int singleCost = std::stoi(Dessert::menuList[j][2]);
                dessertPrice += singleCost;
                flag = true;
                break;
            }
        }

        if (!flag) {
            std::cout << "\nItem id " << orderList[i] << " does not exist and hence won't be included in the order." << std::endl;
            usleep(2500000);
        }
    }
    return dessertPrice;
}
