/**
 * @file Receipt.h
 * @author Shubham Chauhan
 * @brief This file contains declaration for Receipt file.
 * @version 0.1
 * @date 2024-01-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef RECEIPT_H
#define RECEIPT_H

#include "User.h"
#include "Order.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <thread>
#include <mutex>
#include <condition_variable>

class Receipt : public User, public Order {
private:
    std::string itemName, customerName, receipt;
    std::vector<std::string> starterStr, mainStr, dessertStr;
    int totalCost;
    std::mutex mtx;
    std::condition_variable cv;
    bool receiptGenerated;
    std::string getOrderedItems();

public:
    Receipt(std::string cname, std::vector<std::string> starterStr, std::vector<std::string> mainStr, std::vector<std::string> dessertStr, int starterPrice = 0, int mainCoursePrice = 0, int dessertPrice = 0);
    
    std::string getReceipt();
    void addReceiptToFile();
    void writeToFile(const std::string& content, const std::string& filename);
    void addReceiptToIndividualFile();
    void notify(const std::string& name);
};

#endif // RECEIPT_H
