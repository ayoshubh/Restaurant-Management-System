#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <ctime>
#include <iomanip>
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

    void showDetails()
    {
        cout << "Welcome to our Restaurant " << restaurantName << endl;
        cout << "We are located in " << location << endl;
        cout << "We are open all the 7 days of the week from " << openTime << " am to " << closeTime << " pm" << endl;
        cout << "Have a nice day :)" << endl;
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
        bool flag = false;
        // while (!flag)
        // {
        cout << "Enter the item Id of items you wish to order: ";
        getline(cin, orderInput);
        getline(cin, orderInput);

        for (int i = 0; i < orderInput.size(); i++)
        {
            if (!(orderInput[i] == ',' || orderInput[i] == 's' || orderInput[i] == 'm' || orderInput[i] == 'd' || (orderInput[i] >= char(48) && orderInput[i] <= char(57))))
            {
                cout << "Invalid Food Order Input" << endl;
                // flag=true;
                return EmptyOrderList;
            }
        }

        // if(flag) continue;

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
            bool flag = false;
            for (int j = 0; j < start.size(); j++)
            {
                if (start[j][0] == orderL[i])
                {
                    int singleCost = stoi(start[j][2]);
                    starterPrice += singleCost;
                    flag = true;
                    break;
                }
            }
            if (!flag)
                cout << "Item id " << orderL[i] << " does not exist and hence won't be included in the order" << endl;
        }

        // cout << "Cost of starters is : " << starterPrice << endl;
        return starterPrice;
    }

    int getMainCourseOrderCost(vector<string> orderL)
    {

        vector<vector<string>> start = MainCourse::getMenu();
        int mainCoursePrice = 0;
        for (int i = 0; i < orderL.size(); i++)
        {
            bool flag = false;
            for (int j = 0; j < start.size(); j++)
            {
                if (start[j][0] == orderL[i])
                {
                    int singleCost = stoi(start[j][2]);
                    mainCoursePrice += singleCost;
                    flag = true;
                    break;
                }
            }
            if (!flag)
                cout << "Item id " << orderL[i] << " does not exist and hence won't be included in the order" << endl;
        }

        // cout << "Cost of main course is : " << mainCoursePrice << endl;
        return mainCoursePrice;
    }

    int getDessertOrderCost(vector<string> orderL)
    {
        vector<vector<string>> start = Dessert::getMenu();
        int dessertPrice = 0;
        for (int i = 0; i < orderL.size(); i++)
        {
            bool flag = false;
            for (int j = 0; j < start.size(); j++)
            {
                if (orderL[i] == start[j][0])
                {
                    int singleCost = stoi(start[j][2]);
                    dessertPrice += singleCost;
                    flag = true;
                    break;
                }
            }
            if (!flag)
                cout << "Item id " << orderL[i] << " does not exist and hence won't be included in the order" << endl;
        }

        // cout << "Cost of Dessert is : " << dessertPrice << endl;
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

class Receipt : public Order
{
public:
    string itemName;
    void displayItem(vector<string> starterStr, vector<string> mainStr, vector<string> dessertStr)
    {

        vector<vector<string>> start = Starters::getMenu();
        for (int i = 0; i < starterStr.size(); i++)
        {
            for (int j = 0; j < start.size(); j++)
            {
                if (start[j][0] == starterStr[i])
                {
                    cout << start[j][1] << endl;
                    itemName += start[j][1];
                    itemName += "\t";
                    itemName += start[j][2];
                    itemName += "\n";
                    break;
                }
            }
        }

        start = MainCourse::getMenu();
        for (int i = 0; i < mainStr.size(); i++)
        {
            for (int j = 0; j < start.size(); j++)
            {
                if (start[j][0] == mainStr[i])
                {
                    cout << start[j][1] << endl;
                    itemName += start[j][1];
                    itemName += "\t";
                    itemName += start[j][2];
                    itemName += "\n";
                    break;
                }
            }
        }

        start = Dessert::getMenu();
        for (int i = 0; i < dessertStr.size(); i++)
        {
            for (int j = 0; j < start.size(); j++)
            {
                if (start[j][0] == dessertStr[i])
                {
                    cout << start[j][1] << endl;
                    itemName += start[j][1];
                    itemName += "\t";
                    itemName += start[j][2];
                    itemName += "\n";
                    break;
                }
            }
        }
    }
    void showReceipt(int starterPrice = 0, int mainCoursePrice = 0, int dessertPrice = 0)
    {
        int totalCost = starterPrice + mainCoursePrice + dessertPrice;
        cout << "Total price of your food is : " << totalCost << endl;
    }

    void addReceiptToFile()
    {
        ofstream file("TotalReceiptFile.txt");
        file << itemName;
        file.close();
    }
};

class Rating
{
public:
    string name;

    enum rate
    {
        oneStar = 1,
        twoStar,
        threeStar,
        fourStar,
        fiveStar
    };

    void takeRating()
    {
        int choice;
        cout << "Enter 1 for Very Bad Experience" << endl;
        cout << "Enter 2 for Dissatisfied Experience" << endl;
        cout << "Enter 3 for Somewhat Good Experience" << endl;
        cout << "Enter 4 for Good Experience" << endl;
        cout << "Enter 5 for Excellent Experience" << endl;
        cin >> choice;

        switch (choice)
        {
        case oneStar:
            cout << "We are sorry for your unfavourable experience" << endl;
            break;
        case twoStar:
            cout << "Thank you for your feedback. We will try our best to give you a satisfactory service" << endl;
            break;
        case threeStar:
            cout << "Thank you for your feedback." << endl;
            break;
        case fourStar:
            cout << "We are glad that you liked our service" << endl;
            break;
        case fiveStar:
            cout << "Thank you for your positive feedback.It means a lot to us" << endl;
            break;
        default:
            cout << "Invalid response. Please try again" << endl;
        }
    }
};

class User : protected Restaurant
{
protected:
    int visitTime;
    string name;

public:
    bool validateName(string str)
    {
        for (char ch : str)
        {
            if(ch==' '){
                continue;
            }
            if (!isalpha(ch))
            {
                cout << "You cannot enter numbers or special characters in your name " << endl;
                return false;
            }
        }
        return true;
    }
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
                cout << "Sorry we are not open right now" << endl;
                return true;
            }
        }
    };

    class Administrator
    {
    private:
        string username = "ad12";
        string password = "pwd12";

    public:
        Administrator()
        {
        }

        string getUsername()
        {
            return username;
        }

        string getPassword()
        {
            return password;
        }

        // static authentication(){
        //     string sysUname, sysPwd;
        //     sysUname = getUsername();
        //     sysPwd = getPassword();
        // }

        void totalRevenue()
        {
            cout << "The total Revenue Generated is :" << endl;
        }
    };

    int main()
    {
        // Restaurant r;
        string reply;
        cout << "Are you a customer? (y/n)" << endl;
        cin >> reply;
        if (reply == "y" || reply == "Y")
        {
            if (User::validateEntry())
            {
                string customerName;
                bool flag=true;
                User u;
                cout<<"Please Enter your Name : ";
                getline(cin,customerName);
                getline(cin,customerName);
                while(flag){
                    if(u.validateName(customerName)){
                        flag=false;
                    }
                }
                int starterPrice = 0, mainCoursePrice = 0, dessertPrice = 0;
                vector<string> starterOrderList = {}, mainOrderList = {}, dessertOrderList = {};
                Order mainCourseOrderObj, starterOrderObj, dessertOrderObj;
                while (true)
                {

                    cout << "Press A to see Restaurant Details" << endl;
                    cout << "Press B to see Menu" << endl;
                    cout << "Press C to get food receipt" << endl;
                    cout << "Press D to rate your experience" << endl;
                    cout << "Press X to exit" << endl;
                    char choice;
                    cin >> choice;

                    if (choice == 'A')
                    {
                        Restaurant r;
                        r.showDetails();
                    }
                    else if (choice == 'B')
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
                                cout << endl;
                                string ch;
                                cout << "Do you wish to order something from starters? (y/n) : ";
                                cin >> ch;
                                if (ch == "y" || ch == "Y")
                                {
                                    starterOrderList = starterOrderObj.orderItem();
                                    starterPrice = starterOrderObj.getStarterOrderCost(starterOrderList);
                                }
                            }
                            else if (choice == 'M')
                            {
                                MainCourse main;
                                main.display();
                                cout << endl;
                                string ch;
                                cout << "Do you wish to order something from Main course? (y/n) : ";
                                cin >> ch;
                                if (ch == "y" || ch == "Y")
                                {
                                    mainOrderList = mainCourseOrderObj.orderItem();
                                    mainCoursePrice = mainCourseOrderObj.getMainCourseOrderCost(mainOrderList);
                                }
                            }
                            else if (choice == 'D')
                            {
                                Dessert sweet;
                                sweet.display();
                                cout << endl;
                                string ch;
                                cout << "Do you wish to order something from Dessert? (y/n) : ";
                                cin >> ch;
                                if (ch == "y" || ch == "Y")
                                {
                                    dessertOrderList = dessertOrderObj.orderItem();
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
                    else if (choice == 'C')
                    {
                        if (!starterPrice && !mainCoursePrice && !dessertPrice)
                        {
                            cout << "You have to order atleast one food item to generate a receipt" << endl;
                        }
                        else
                        {
                            Receipt bill;
                            bill.displayItem(starterOrderList, mainOrderList, dessertOrderList);
                            cout << endl;
                            bill.showReceipt(starterPrice, mainCoursePrice, dessertPrice);
                            bill.addReceiptToFile();
                            starterPrice = 0, mainCoursePrice = 0, dessertPrice = 0;
                            starterOrderList = {}, mainOrderList = {}, dessertOrderList = {};
                        }
                    }
                    else if (choice == 'D')
                    {
                        Rating r;
                        r.takeRating();
                    }
                    else if (choice == 'X')
                    {
                        if (!starterPrice && !mainCoursePrice && !dessertPrice)
                        {
                            return 0;
                        }
                        else
                        {
                            cout << "You cannot exit without generating the food receipt" << endl;
                        }
                    }
                    else
                    {
                        cout << " Invalid Response" << endl;
                    }
                }
            }
        }
        else
        {
            string uname, pwd;
            string sysUname, sysPwd;
            cout << "Welcome to Administrator Login portal" << endl;
            cout << "Username : ";
            cin >> uname;
            cout << "Password : ";
            cin >> pwd;
            Administrator admin;
            sysUname = admin.getUsername();
            sysPwd = admin.getPassword();
            int tries = 1;

            if (sysUname != uname || sysPwd != pwd)
            {
                cout << "You have entered the wrong credentials" << endl;
            }
            else
            {
                cout << "You are inside the admin portal" << endl;
            }
        }

        return 0;
    }