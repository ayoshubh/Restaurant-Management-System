/**
 * @file Order.cpp
 * @author Shubham Chauhan
 * @brief This file contains implementation for Order class
 * @version 0.1
 * @date 2024-01-10
 * @copyright Copyright (c) 2024
 */
#include "Order.h"

/**
 * @brief Construct a new Order:: Order object
 * @param sList
 * @param mList
 * @param dList
 */
Order::Order(std::vector<std::vector<std::string>> sList, std::vector<std::vector<std::string>> mList, std::vector<std::vector<std::string>> dList)
{
    Starters::menuList = sList;
    MainCourse::menuList = mList;
    Dessert::menuList = dList;
}

/**
 * @brief A setter method used to initialise the data member orderInput string with the input given by the user
 * which includes the itemId of item(s) they want to order.
 * @param orderInp 
 */
void Order::setOrderInput(std::string orderInp)
{
    orderInput = orderInp;
}

/**
 * @brief setter method to clear orderList
 */
void Order::setOrderList()
{
    this->orderList.clear();
}

/**
 * @brief This method does string interpolation and stores each itemId in orderInput as a vector
 * of string and returns it.
 * @return std::vector<std::string> 
 */
std::vector<std::string> Order::getOrderList()
{
    try
    {
        bool flag = false;
        std::string singleId;
        orderList.clear();
        for (int i = 0; i < orderInput.size(); i++)
        {
            if (orderInput[i] == ',')
            {
                orderList.push_back(singleId);
                singleId = "";
            }
            else
            {
                singleId += orderInput[i];
                if (i == orderInput.size() - 1)
                {
                    orderList.push_back(singleId);
                }
            }
        }
        return orderList;
    }
    catch (const std::exception &e)
    {
        // Handle other exceptions
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

/**
 * @brief This member function calculates the cost of starters ordered by the user.
 * @return int 
 */
int Order::getStarterOrderCost()
{
    try
    {
        int starterPrice = 0;
        int errCount = 0;
        for (int i = 0; i < orderList.size(); i++)
        {
            bool flag = false;

            for (int j = 0; j < Starters::menuList.size(); j++)
            {
                if (orderList[i] == Starters::menuList[j][0])
                {
                    int singleCost = std::stoi(Starters::menuList[j][2]);
                    starterPrice += singleCost;
                    flag = true;
                    break;
                }
            }

            if (!flag)
            {
                std::cout << "\nItem id " << orderList[i] << " does not exist and hence won't be included in the order." << std::endl;
                usleep(2500000);
            }
        }
        if (orderList.size() != errCount)
        {
            std::cout << "Your order has been successfully placed \n";
        }
        return starterPrice;
    }
    catch (const std::exception &e)
    {
        // Handle other exceptions
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

/**
 * @brief This member function calculates the cost of main course ordered by the user.
 * @return int 
 */
int Order::getMainCourseOrderCost()
{
    try
    {
        int mainCoursePrice = 0;
        int errCount = 0;
        for (int i = 0; i < orderList.size(); i++)
        {
            bool flag = false;

            for (int j = 0; j < MainCourse::menuList.size(); j++)
            {
                if (orderList[i] == MainCourse::menuList[j][0])
                {
                    int singleCost = std::stoi(MainCourse::menuList[j][2]);
                    mainCoursePrice += singleCost;
                    flag = true;
                    break;
                }
            }

            if (!flag)
            {
                std::cout << "\nItem id " << orderList[i] << " does not exist and hence won't be included in the order." << std::endl;
                usleep(2500000);
            }
        }

        if (orderList.size() != errCount)
        {
            std::cout << "Your order has been successfully placed \n";
        }
        return mainCoursePrice;
    }
    catch (const std::exception &e)
    {
        // Handle other exceptions
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

/**
 * @brief This member function calculates the cost of dessert ordered by the user.
 * @return int 
 */
int Order::getDessertOrderCost()
{
    try
    {
        int dessertPrice = 0;
        int errCount = 0;
        for (int i = 0; i < orderList.size(); i++)
        {
            bool flag = false;

            for (int j = 0; j < Dessert::menuList.size(); j++)
            {
                if (orderList[i] == Dessert::menuList[j][0])
                {
                    int singleCost = std::stoi(Dessert::menuList[j][2]);
                    dessertPrice += singleCost;
                    flag = true;
                    break;
                }
            }

            if (!flag)
            {
                std::cout << "\nItem id " << orderList[i] << " does not exist and hence won't be included in the order." << std::endl;
                usleep(2500000);
            }
            if (orderList.size() != errCount)
            {
                std::cout << "Your order has been successfully placed \n";
            }
        }
        return dessertPrice;
    }
    catch (const std::exception &e)
    {
        // Handle other exceptions
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
