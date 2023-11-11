#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

class Restaurant
{
protected:
    int openTime;
    int closeTime;
    string restaurantName;
    string location;

public:
    Restaurant()
    {
        openTime = 10;
        closeTime = 22;
        restaurantName = "Food Villa";
        location = "Vadodara, Gujarat";
    }
};

struct Menu
{
protected:
    int itemId;
    string itemName;
    int itemPrice;
    string singleItemDetail;         // For storing itemId, itemName and price of a single item in a string
    vector<string> singleItemList;   // separating itemId, itemName and price from singleItemDetail and storing it in a vector ["itemId", ["itemName"], ["price"]]
    vector<vector<string>> menuList; // nested vector stores the list of menu items [["itemid","itemName","price"],[..],[..]]

    virtual void display() = 0;
};

class Starters : public Menu
{
public:
    vector<vector<string>> getMenu()
    {
        ifstream file("starterFile.txt");

        string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>())); // Read the entire file

        file.close(); // Close the file

        for (int i = 0; i < content.size(); i++)
        {
            if (content[i] == '\n')
            {
                singleItemDetail += '-';
                vector<string> singleItemList;
                string word;

                for (int i = 0; i < singleItemDetail.size(); i++)
                {
                    if (singleItemDetail[i] == '-')
                    {
                        singleItemList.push_back(word);
                        word = "";
                        continue;
                    }
                    word += singleItemDetail[i];
                }
                menuList.push_back(singleItemList);
                // cout<<singleItemDetail<<endl;
                singleItemDetail = "";
                // break;
                continue;
            }
            singleItemDetail += content[i];
        }

        return menuList;
    }

    void display()
    {
        vector<vector<string>> menuList = getMenu();
        cout << "DISPLAYING MENU" << endl;

        for (int i = 0; i < menuList.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << menuList[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
    }
};

class MainCourse : public Menu
{
public:
    vector<vector<string>> getMenu()
    {
        ifstream file("MainCourseFile.txt");

        string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>())); // Read the entire file

        file.close(); // Close the file

        for (int i = 0; i < content.size(); i++)
        {
            if (content[i] == '\n')
            {
                singleItemDetail += '-';
                vector<string> singleItemList;
                string word;

                for (int i = 0; i < singleItemDetail.size(); i++)
                {
                    if (singleItemDetail[i] == '-')
                    {
                        singleItemList.push_back(word);
                        word = "";
                        continue;
                    }
                    word += singleItemDetail[i];
                }
                menuList.push_back(singleItemList);
                // cout<<singleItemDetail<<endl;
                singleItemDetail = "";
                // break;
                continue;
            }
            singleItemDetail += content[i];
        }

        return menuList;
    }

    void display()
    {
        vector<vector<string>> menuList = getMenu();
        cout << "DISPLAYING MENU" << endl;

        for (int i = 0; i < menuList.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << menuList[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
    }
};

class Dessert : public Menu
{
public:
    vector<vector<string>> getMenu()
    {
        ifstream file("DessertFile.txt");

        string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>())); // Read the entire file

        file.close(); // Close the file

        for (int i = 0; i < content.size(); i++)
        {
            if (content[i] == '\n')
            {
                singleItemDetail += '-';
                vector<string> singleItemList;
                string word;

                for (int i = 0; i < singleItemDetail.size(); i++)
                {
                    if (singleItemDetail[i] == '-')
                    {
                        singleItemList.push_back(word);
                        word = "";
                        continue;
                    }
                    word += singleItemDetail[i];
                }
                menuList.push_back(singleItemList);
                // cout<<singleItemDetail<<endl;
                singleItemDetail = "";
                // break;
                continue;
            }
            singleItemDetail += content[i];
        }

        return menuList;
    }

    void display()
    {
        vector<vector<string>> menuList = getMenu();
        cout << "DISPLAYING MENU" << endl;

        for (int i = 0; i < menuList.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << menuList[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
    }
};

class Order : public Starters, public MainCourse, public Dessert
{
public:
    string orderInput;
    vector<string> orderList;
    vector<string> EmptyOrderList;
    int totalCost;

    vector<string> orderItem()
    {
        
        cout << "Enter the item Id of items you wish to order: ";
        cin >> orderInput;

        for (int i = 3; i < orderInput.size() - 1; i += 4)
        {
            if (orderInput[i] != ',')
            {
                cout << "Invalid Food Order Input" << endl;
                break;
            }
        }
        string singleId;
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

    int getStarterOrderCost(vector<string> orderL)
    {
        
        vector<vector<string>> start = Starters::getMenu();
        int starterPrice = 0;
        for (int i = 0; i < orderL.size(); i++)
        {
            for (int j = 0; j < start.size(); j++)
            {
                if (start[j][0] == orderL[i])
                {
                    int singleCost = stoi(start[j][2]);
                    starterPrice += singleCost;
                    break;
                }
            }
        }

        // cout << "Cost of starters is : " << starterPrice << endl;
        return starterPrice;
    }

    int getMainCourseOrderCost(vector<string> orderL)
    {
        int mainCoursePrice = 0;
        vector<vector<string>> start = MainCourse::getMenu();
        for (int i = 0; i < orderL.size(); i++)
        {
            for (int j = 0; j < start.size(); j++)
            {
                if (start[j][0] == orderL[i])
                {
                    int singleCost = stoi(start[j][2]);
                    mainCoursePrice += singleCost;
                    break;
                }
            }
        }

        cout << "Cost of main course is : " << mainCoursePrice << endl;
        return mainCoursePrice;
    }

    int getDessertOrderCost(vector<string> orderL)
    {
        int dessertPrice = 0;
        vector<vector<string>> start = Dessert::getMenu();
        for (int i = 0; i < orderL.size(); i++)
        {
            for (int j = 0; j < start.size(); j++)
            {
                if (start[j][0] == orderL[i])
                {
                    int singleCost = stoi(start[j][2]);
                    dessertPrice += singleCost;
                    break;
                }
            }
        }

        cout << "Cost of Dessert is : " << dessertPrice << endl;
        return dessertPrice;
    }

    void calculateCost()
    {

        int starterPrice = getStarterOrderCost(orderList);
        int mainCoursePrice = getMainCourseOrderCost(orderList);
        int dessertPrice = getDessertOrderCost(orderList);
        totalCost = starterPrice + mainCoursePrice + dessertPrice;

        cout << "Total bill is of : " << totalCost << endl;
    }
};

class Receipt: public Order{
    public:
    void displayItem(vector<string> StarterStr, vector<string> MainStr, vector<string> DessertStr){
        for(auto i: StarterStr){
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i: MainStr){
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i: DessertStr){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    void showReceipt(int starterPrice=0, int mainCoursePrice=0,int dessertPrice=0){
        int totalCost = starterPrice+mainCoursePrice+dessertPrice;
        cout<<"Receipt is : "<<totalCost<<endl;
    }
};

class User : protected Restaurant
{
protected:
    int visitTime;
    string review;

public:

    static bool validateEntry()
    {
        // Get the current time
        auto now = std::chrono::system_clock::now();
        std::time_t current_time = std::chrono::system_clock::to_time_t(now);

        // Convert the current time to a tm struct for local time
        std::tm local_time = *std::localtime(&current_time);

        // Extract the current hour from the tm struct
        int current_hour = local_time.tm_hour;

        if (10 <= current_hour && 22 > current_hour)
        {
            cout << "Welcome to Food Villa" << endl;
            return true;
        }
        else
        {
            cout << "Sorry we are not open right now"<<endl;
            return true;
        }
    }
};

int main()
{
    Restaurant r;
    if (User::validateEntry())
    {
        User u;
        int starterPrice=0;
        int mainCoursePrice=0;
        int dessertPrice=0;
        vector<string> starterOrderList={}, mainOrderList={}, dessertOrderList={};
        Order mainCourseOrderObj,starterOrderObj, dessertOrderObj;
        while (true)
        {

            cout << "Press A to see Menu" << endl;
            cout<<"Press C to see Restaurant Details"<<endl;
            cout << "Press B to get food receipt" << endl;

            cout << "Press X to exit" << endl;
            char choice;
            cin >> choice;

            if (choice == 'A')
            {
                // Menu m;
                while (true)
                {

                    cout << "Press S to see Starters Menu." << endl;
                    cout << "Press M to see Main Course Menu." << endl;
                    cout << "Press D to see Dessert Menu." << endl;
                    cout << " Press X to return to previous Menu." << endl;

                    cin >> choice;

                    if (choice == 'S')
                    {
                        Starters st;
                        st.display();
                        cout<<endl;
                        char ch;
                        cout<<"Do you wish to order something from starters? (y/n) : ";
                        cin>>ch;
                        if(ch=='y' || ch=='Y'){
                            starterOrderList = starterOrderObj.orderItem();
                            starterPrice += starterOrderObj.getStarterOrderCost(starterOrderList);
                        }
                    }
                    else if (choice == 'M')
                    {
                        MainCourse main;
                        main.display();
                        cout<<endl;
                        char ch;
                        cout<<"Do you wish to order something from main course? (y/n) : ";
                        cin>>ch;
                        if(ch=='y' || ch=='Y'){
                            mainOrderList=mainCourseOrderObj.orderItem();
                            mainCoursePrice = mainCourseOrderObj.getMainCourseOrderCost(mainOrderList);
                        }
                    }
                    else if (choice == 'D')
                    {
                        Dessert sweet;
                        sweet.display();
                        cout<<endl;
                        char ch;
                        cout<<"Do you wish to order something from Dessert? (y/n) : ";
                        cin>>ch;
                        if(ch=='y' || ch=='Y'){
                            dessertOrderList=dessertOrderObj.orderItem();
                            dessertPrice = dessertOrderObj.getDessertOrderCost(dessertOrderList);
                        }
                    }
                    else if (choice == 'X')
                    {
                        break;
                    }
                    else
                    {
                        cout << " Invalid Response " << endl;
                    }
                }
            }
            else if (choice == 'B')
            {
                if(!starterPrice && !mainCoursePrice && !dessertPrice){
                    cout<<"You have to order atleast one food item to generate a receipt"<<endl;
                }else{
                Receipt bill;
                bill.showReceipt(starterPrice,mainCoursePrice,dessertPrice);
                cout<<endl;
                bill.displayItem(starterOrderList, mainOrderList, dessertOrderList);
                starterPrice=0,mainCoursePrice=0,dessertPrice=0;
                }
                
            }else if(choice=='X'){
                if(!starterPrice && !mainCoursePrice && !dessertPrice){
                    return 0;
                }else{
                    cout<<"You cannot exit without generating the food receipt"<<endl;
                }
            }
            else
            {
                cout << " Invalid Response" << endl;
            }
        }
    }
    return 0;
}