#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>

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
        closeTime = 12;
        restaurantName = "Food Villa";
        location = "Vadodara, Gujarat";
    }

    void showDetails()
    {
        cout << " \n**********  Welcome to our Restaurant " << restaurantName << "  ********** "<<endl;
        cout << "We are located in " << location << endl;
        cout << "We are open all the 7 days of the week from " << openTime << "am to " << closeTime << "pm" << endl;
        cout << "Have a nice day :) \n" << endl;
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
            if (ch == ' ')
            {
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
        auto now = chrono::system_clock::now();
        time_t current_time = chrono::system_clock::to_time_t(now);

        // Convert the current time to a tm struct for local time
        tm local_time = *localtime(&current_time);

        // Extract the current hour from the tm struct
        int current_hour = local_time.tm_hour;

        if (10 <= current_hour && 22 > current_hour)
        {
            cout << "Welcome to Food Villa \n";
            return true;
        }
        else
        {
            cout << "Sorry we are not open right now \n";
            return true;
        }
    }
};

class Menu
{
protected:
    int itemId;
    string itemName;
    int itemPrice;
    string singleItemDetail;         // For storing itemId, itemName and price of a single item in a string
    vector<string> singleItemList;   // separating itemId, itemName and price from singleItemDetail and storing it in a vector ["itemId", ["itemName"], ["price"]]
    vector<vector<string>> menuList; // nested vector stores the list of menu items [["itemid","itemName","price"],[..],[..]]

    vector<vector<string>> getMenu(string filename)
    {
        ifstream file(filename);

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

    virtual void display(){
        cout<<"Displaying menu \n";
    }
};

class Starters : public Menu
{
public:

    void display()
    {
        vector<vector<string>> menuList = getMenu("StarterFile.txt");
        cout << " _____Starters Menu_____ \n\n";

        for (int i = 0; i < menuList.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << menuList[i][j] << "  ";
            }
            cout <<"\n\n";
        }

    }
};

class MainCourse : public Menu
{
public:
    void display()
    {
        vector<vector<string>> menuList = getMenu("MainCourseFile.txt");
        cout << " _____Main Course Menu_____ \n\n";

        for (int i = 0; i < menuList.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << menuList[i][j] << "  ";
            }
            cout << "\n\n";
        }
    }
};

class Dessert : public Menu
{
public:
    void display()
    {
        vector<vector<string>> menuList = getMenu("DessertFile.txt");
        cout << " _____Dessert Menu_____ \n\n";

        for (int i = 0; i < menuList.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << menuList[i][j] << "  ";
            }
            cout <<"\n\n";
        }

    }
};

class Order : public Starters, public MainCourse, public Dessert
{
public:
    string orderInput;
    vector<string> orderList;
    vector<string> EmptyOrderList;
    int totalCost;

    Order(string orderInp){
        this->orderInput=orderInp;
    }
    
    vector<string> orderItem()
    {
        bool flag = false;

        for (int i = 0; i < orderInput.size(); i++)
        {
            if (!(orderInput[i] == ',' || orderInput[i] == 's' || orderInput[i] == 'm' || orderInput[i] == 'd' || (orderInput[i] >= char(48) && orderInput[i] <= char(57))))
            {
                cout << "Invalid Food Order Input" << endl;
                // flag=true;
                return EmptyOrderList;
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
        // for(auto i: orderList){
        //     cout<<i<<endl;
        // }
        return orderList;
    }

    int getStarterOrderCost(vector<string> orderL)
    {

        vector<vector<string>> start = Starters::getMenu("StarterFile.txt");
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
            if (!flag){
                cout << "\nItem id " << orderL[i] << " does not exist and hence won't be included in the order." << endl;
                usleep(3000000);
            }
        }
        // cout << "Cost of starters is : " << starterPrice << endl;
        return starterPrice;
    }

    int getMainCourseOrderCost(vector<string> orderL)
    {

        vector<vector<string>> start = MainCourse::getMenu("MainCourseFile.txt");
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
            if (!flag){
                cout << "\nItem id " << orderL[i] << " does not exist and hence won't be included in the order." << endl;
                usleep(3000000);
            }
        }

        // cout << "Cost of main course is : " << mainCoursePrice << endl;
        return mainCoursePrice;
    }

    int getDessertOrderCost(vector<string> orderL)
    {
        vector<vector<string>> start = Dessert::getMenu("DessertFile.txt");
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
            if (!flag){
                cout << "\nItem id " << orderL[i] << " does not exist and hence won't be included in the order." << endl;
                usleep(3000000);
            }
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

class Receipt :public User,public Starters, public MainCourse,public Dessert
{
private:
    string itemName;
    string customerName;
    string receipt;
    vector<string> starterStr,mainStr,dessertStr;
    int starterPrice, mainCoursePrice,dessertPrice;

    string getOrderedItems()
    {
        // string itemNameF, itemNameStr, itemNameMain, itemNameDessert;
        vector<vector<string>> start = Starters::getMenu("StarterFile.txt");
        for (int i = 0; i < starterStr.size(); i++)
        {
            for (int j = 0; j < start.size(); j++)
            {
                if (starterStr[i]==start[j][0])
                {
                    // cout << start[j][1] << endl;
                    itemName += start[j][1];
                    for (int k = start[j][1].size(); k < 20; k++)
                    {
                        itemName += '-';
                    }
                    // itemName += "Rs.";
                    itemName += start[j][2];
                    itemName += '\n';
                    break;
                }
            }
        }

        start = MainCourse::getMenu("MainCourseFile.txt");
        for (int i = 0; i < mainStr.size(); i++)
        {
            for (int j = 0; j < start.size(); j++)
            {
                if (mainStr[i]==start[j][0])
                {
                    // cout << start[j][1] << endl;
                    itemName += start[j][1];
                    for (int k = start[j][1].size(); k < 20; k++)
                    {
                        itemName += '-';
                    }
                    // itemName += "Rs.";
                    itemName += start[j][2];
                    itemName += '\n';
                    break;
                }
            }
        }

        start = Dessert::getMenu("DessertFile.txt");
        for (int i = 0; i < dessertStr.size(); i++)
        {
            for (int j = 0; j < start.size(); j++)
            {
                if (dessertStr[i] == start[j][0])
                {
                    // cout << start[j][1] << endl;
                    itemName += start[j][1];
                    for (int k = start[j][1].size(); k < 20; k++)
                    {
                        itemName += '-';
                    }
                    // itemName += "Rs.";
                    itemName += start[j][2];
                    itemName += '\n';
                    break;
                }
            }
        }

        return itemName;
    }
    
    public:
    Receipt(string name, vector<string> starterStr, vector<string> mainStr, vector<string> dessertStr,int starterPrice = 0, int mainCoursePrice = 0, int dessertPrice = 0){
        this->starterStr=starterStr;
        this->mainStr=mainStr;
        this->dessertStr=dessertStr;
        this->starterPrice = starterPrice;
        this->mainCoursePrice = mainCoursePrice;
        this->dessertPrice = dessertPrice;
        customerName=name;
        // itemName=getOrderedItems();
        // receipt=getReceipt();

    }

    string getReceipt()
    {
        // ofstream file("TotalReceiptFile.txt",ios::app);
        itemName=getOrderedItems();
        time_t t = time(nullptr);
        tm *now = localtime(&t);
        // Format the current time as a string
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", now);
        string formattedDateTime(buffer);
        int totalCost = starterPrice + mainCoursePrice + dessertPrice;
        receipt += "\n*Customer Name : ";
        receipt += customerName;
        receipt += "\n";
        receipt += "Time: ";
        receipt += formattedDateTime;
        receipt += "\nOrdered Items:\n";
        receipt += itemName;
        receipt += "--------------------------\n";
        receipt += " Total Bill :      Rs.";
        receipt += to_string(totalCost);
        receipt += "\n--------------------------\n";
        // cout << receipt;
        return receipt;
    }

    void addReceiptToFile()
    {
        // this->receipt=getReceipt();
        ofstream file("TotalReceiptFile.txt", ios::app);
        file << this->receipt;
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
class Administrator
{
private:
    string username = "ad12";
    string password = "pwd12";
    string customerDetail;

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

    string getLogbook()
    {
        ifstream file("TotalReceiptFile.txt");

        string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>())); // Read the entire file

        file.close(); // Close the file

        return content;
    }

    int findSubstringIndex(const std::string &largerString, const std::string &smallerString)
    {
        size_t found = largerString.find(smallerString);
        if (found != std::string::npos)
        {
            return static_cast<int>(found);
        }
        else
        {
            return -1; // Return -1 if the substring is not found
        }
    }

    string searchCustomer(string name)
    {
        string tempContent = getLogbook();
        // std::string largerString = "This is a larger string.";
        // std::string smallerString = "larger";

        int index = findSubstringIndex(tempContent, name);
        for (int i = index; i < tempContent.size(); i++)
        {
            if (tempContent[i] == '*')
            {
                break;
            }
            customerDetail.push_back(tempContent[i]);
        }
        return customerDetail;
    }

    void totalRevenue()
    {
        cout << "The total Revenue Generated is :" << endl;
    }
};

int main()
{
    // Restaurant r;
    // system("clear");
    string reply;
    cout << "Are you a customer? \n(press Y for Yes or any other key to login as Administrator): ";
    cin >> reply;
    if (reply == "y" || reply == "Y")
    {
        // system("clear");
        if (User::validateEntry())
        {
            string customerName;
            bool flag = true;
            User u;
            cout << "Please Enter your Name : ";
            cin.ignore();
            getline(cin,customerName);
            // getline(cin, customerName);
            while (flag)
            {
                if (u.validateName(customerName))
                {
                    flag = false;
                }
            }
            bool ratingFlag = false;
            int starterPrice = 0, mainCoursePrice = 0, dessertPrice = 0;
            vector<string> starterOrderList, mainOrderList, dessertOrderList;
            // Order mainCourseOrderObj, starterOrderObj, dessertOrderObj;
            while (true)
            {

                cout << "\nPress A to see Restaurant Details" << endl;
                cout << "Press B to see Menu" << endl;
                cout << "Press C to get food receipt" << endl;
                cout << "Press D to rate your experience" << endl;
                cout << "Press X to exit\n" << endl;
                char choice;
                cout<<"Enter your choice here : ";
                cin >> choice;

                if (choice == 'A')
                {
                    // system("clear"); 
                    Restaurant r;
                    r.showDetails();
                }
                else if (choice == 'B')
                {
                    // Menu m;
                    while (true)
                    {
                        // system("clear"); 
                        cout << "\nPress S to see Starters Menu." << endl;
                        cout << "Press M to see Main Course Menu." << endl;
                        cout << "Press D to see Dessert Menu." << endl;
                        cout << "Press X to return to previous Menu." << endl;
                        cout<<"\nEnter your choice here : ";
                        cin >> choice;
                        if (choice == 'S')
                        {
                            // system("clear"); 
                            Starters st;
                            st.display();
                            string ch;
                            cout << "Do you wish to order something from Starters? \n(press Y for Yes or any other key for No) : ";
                            cin >> ch;
                            if (ch == "y" || ch == "Y")
                            {
                                cin.ignore();
                                string orderInput;
                                cout << "Enter the item Id of items you wish to order(use comma if you want multiple items): ";
                                getline(cin, orderInput);
                                Order starterOrderObj(orderInput);
                                starterOrderList = starterOrderObj.orderItem();
                                starterPrice = starterOrderObj.getStarterOrderCost(starterOrderList);

                            }
                        }
                        else if (choice == 'M')
                        {
                            // system("clear"); 
                            MainCourse main;
                            main.display();
                            cout << endl;
                            string ch;
                            cout << "Do you wish to order something from Main course? \n(press Y for Yes or any other key for No) : ";
                            cin >> ch;
                            if (ch == "y" || ch == "Y")
                            {
                                cin.ignore();
                                string orderInput;
                                cout << "Enter the item Id of items you wish to order(use comma if you want multiple items): ";
                                getline(cin, orderInput);
                                Order mainCourseOrderObj(orderInput);
                                mainOrderList = mainCourseOrderObj.orderItem();
                                mainCoursePrice = mainCourseOrderObj.getMainCourseOrderCost(mainOrderList);
                            }
                        }
                        else if (choice == 'D')
                        {
                            // system("clear"); 
                            Dessert sweet;
                            sweet.display();
                            cout << endl;
                            string ch;
                            cout << "Do you wish to order something from Dessert ? \n(press Y for Yes or any other key for No) : ";
                            cin >> ch;
                            if (ch == "y" || ch == "Y")
                            {
                                cin.ignore();
                                string orderInput;
                                cout << "Enter the item Id of items you wish to order(use comma if you want multiple items): ";
                                getline(cin, orderInput);
                                Order dessertOrderObj(orderInput);
                                dessertOrderList = dessertOrderObj.orderItem();
                                dessertPrice = dessertOrderObj.getDessertOrderCost(dessertOrderList);
                            }
                        }
                        else if (choice == 'X')
                        {
                            // system("clear");
                            break;
                        }
                        else
                        {
                            // system("clear");
                            cout << " Invalid Response " << endl;
                        }
                    }
                }
                else if (choice == 'C')
                {
                    if (!starterPrice && !mainCoursePrice && !dessertPrice)
                    {
                        // system("clear");
                        cout << "\nYou have to order atleast one food item to generate a receipt.\n";
                    }
                    else
                    {
                        // system("clear");
                        Receipt bill(customerName,starterOrderList, mainOrderList, dessertOrderList,starterPrice, mainCoursePrice, dessertPrice);
                        string singleReceipt = bill.getReceipt();
                        cout<<singleReceipt<<endl;
                        int totalCost = starterPrice + mainCoursePrice + dessertPrice;
                        bill.addReceiptToFile();
                        starterPrice = 0, mainCoursePrice = 0, dessertPrice = 0;
                        starterOrderList = {}, mainOrderList = {}, dessertOrderList = {};
                        ratingFlag = true;
                    }
                }
                else if (choice == 'D')
                {
                    if (ratingFlag)
                    {
                        // system("clear");
                        Rating r;
                        r.takeRating();
                        ratingFlag = false;
                    }
                    else
                    {
                        // system("clear");
                        cout << "\nPlease order food and generate food receipt before rating your experience. \n";
                    }
                }
                else if (choice == 'X')
                {
                    if (!starterPrice && !mainCoursePrice && !dessertPrice)
                    {
                        return 0;
                    }
                    else
                    {
                        // system("clear");
                        cout << "\nYou cannot exit without generating the food receipt.\n";
                    }
                }
                else
                {
                    // system("clear");
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
            while (true)
            {
                cout << "Press A to access Transaction logbook." << endl;
                cout << "Press B to access Customer details" << endl;
                cout << "Press C to access Total revenue of the restaurant"<<endl;
                cout << "Press X to Exit" << endl;
                char ch;
                cin >> ch;
                if (ch == 'A')
                {
                    string log = admin.getLogbook();
                    cout << log << endl;
                }
                else if (ch == 'B')
                {
                    string cname;
                    cin>>cname;
                    string details=admin.searchCustomer(cname);
                    cout<<details;
                }
                else if (ch == 'X')
                {
                    return 0;
                }
                else
                {
                    cout << "Invalid response" << endl;
                }
            }
        }
    }
    return 0;
}