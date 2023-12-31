#include "Order.h"
using namespace std;

Order::Order(vector<vector<string>> sList, vector<vector<string>> mList, vector<vector<string>> dList)
    {
        Starters::menuList = sList;
        MainCourse::menuList = mList;
        Dessert::menuList = dList;
    }
void Order::setOrderInput(std::string orderInp)
{
    orderInput = orderInp;
}

void Order::setOrderList()
{
    this->orderList.clear();
}

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
            cout << "Your order has been successfully placed \n";
        }
        return starterPrice;
    }
    catch (const std::exception &e)
    {
        // Handle other exceptions
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

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
                cout << "Your order has been successfully placed \n";
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
