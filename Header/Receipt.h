#ifndef RECEIPT_H
#define RECEIPT_H

#include "User.h"
#include "Order.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

class Receipt : public User, public Order {
private:
    std::string itemName, itemName2, customerName, receipt, str;
    std::vector<std::string> starterStr, mainStr, dessertStr;
    int starterPrice, mainCoursePrice, dessertPrice, totalCost;

    std::string getOrderedItems();

public:
    Receipt(std::string cname, std::vector<std::string> starterStr, std::vector<std::string> mainStr, std::vector<std::string> dessertStr, int starterPrice = 0, int mainCoursePrice = 0, int dessertPrice = 0);
    
    std::string getReceipt();
    void addReceiptToFile();
};

#endif // RECEIPT_H
