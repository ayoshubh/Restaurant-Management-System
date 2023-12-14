#include "Receipt.h"
using namespace std;
Receipt::Receipt(std::string cname, std::vector<std::string> starterStr, std::vector<std::string> mainStr, std::vector<std::string> dessertStr, int starterPrice, int mainCoursePrice, int dessertPrice) {
    this->starterStr = starterStr;
    this->mainStr = mainStr;
    this->dessertStr = dessertStr;
    this->starterPrice = starterPrice;
    this->mainCoursePrice = mainCoursePrice;
    this->dessertPrice = dessertPrice;
    totalCost = starterPrice + mainCoursePrice + dessertPrice;
    customerName = cname;
    itemName = getOrderedItems();
    itemName2 = itemName;
}

std::string Receipt::getOrderedItems() {
    std::vector<std::vector<std::string>> start = Starters::getMenu("TextFiles/StarterFile.txt");

    for (int i = 0; i < starterStr.size(); i++) {
        for (int j = 0; j < start.size(); j++) {
            if (starterStr[i] == start[j][0]) {
                itemName += start[j][1];
                for (int k = start[j][1].size(); k < 20; k++) {
                    itemName += '-';
                }
                itemName += "Rs.";
                itemName += start[j][2];
                itemName += '\n';
                break;
            }
        }
    }

    start = MainCourse::getMenu("TextFiles/MainCourseFile.txt");
    for (int i = 0; i < mainStr.size(); i++) {
        for (int j = 0; j < start.size(); j++) {
            if (mainStr[i] == start[j][0]) {
                itemName += start[j][1];
                for (int k = start[j][1].size(); k < 20; k++) {
                    itemName += '-';
                }
                itemName += "Rs.";
                itemName += start[j][2];
                itemName += '\n';
                break;
            }
        }
    }

    start = Dessert::getMenu("TextFiles/DessertFile.txt");
    for (int i = 0; i < dessertStr.size(); i++) {
        for (int j = 0; j < start.size(); j++) {
            if (dessertStr[i] == start[j][0]) {
                itemName += start[j][1];
                for (int k = start[j][1].size(); k < 20; k++) {
                    itemName += '-';
                }
                itemName += "Rs.";
                itemName += start[j][2];
                itemName += '\n';
                break;
            }
        }
    }

    return itemName;
}

std::string Receipt::getReceipt() {
    time_t t = time(nullptr);
    tm *now = localtime(&t);
    // Format the current time as a string
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", now);
    std::string formattedDateTime(buffer);

    receipt += "\n*Customer Name : ";
    receipt += customerName;
    receipt += "\n";
    receipt += "Time: ";
    receipt += formattedDateTime;
    receipt += "\nOrdered Items:\n";
    receipt += itemName;
    receipt += "--------------------------\n";
    receipt += " Total Bill :      Rs.";
    receipt += std::to_string(totalCost);
    receipt += "\n--------------------------\n";

    return receipt;
}

void Receipt::addReceiptToFile() {
    std::ofstream file("TextFiles/TotalReceiptFile.txt", std::ios::app);
    file << receipt;
    file.close();
    
    std::ofstream file2("TextFiles/RevenueReceipt.txt", std::ios::app);
    file2 << totalCost << "\n";
    file2.close();
}
