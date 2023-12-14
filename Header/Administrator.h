#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "Order.h"
#include <iostream>
#include <fstream>

class Administrator : public Order {
private:
    std::string username;
    std::string password;
    std::string customerDetail;

public:
    Administrator();
    std::string getUsername();
    std::string getPassword();
    std::string getLogbook();
    int totalRevenue();
    float avgRating();
};

#endif // ADMINISTRATOR_H
