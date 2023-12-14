#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <unistd.h>
#include <thread>
#include <stdio.h>
// #include  <curses.h> 
#include "Restaurant.h"
#include "User.h"
#include "Menu.h"
#include "MainCourse.h"
#include "Starters.h"
#include "Dessert.h"
#include "Order.h"
#include "Receipt.h"
#include "Rating.h"
#include "Administrator.h"
using namespace std;



int main()
{
    system("clear");
    string reply;
    while (true)
    {
        cout << "\nPress A if you are a customer" << endl;
        cout << "Press B if you are an administrator" << endl;
        cout << "Press X to exit\n";
        cout << "Enter your response here : ";
        cin >> reply;
        if (reply == "A" || reply == "a" || reply == "B" || reply == "b" || reply == "X" || reply == "x")
        {
            break;
        }
        else
        {
            cout << "Invalid response. Try again";
        }
    }

    if (reply == "A" || reply == "a")
    {
        system("clear");
        if (User::validateEntry())
        {
            User u;
            string customerFirstName, customerLastName;
            bool flag = true;
            while (flag)
            {
                cout << "Enter your First Name : ";
                cin>>customerFirstName;
                u.setFirstName(customerFirstName);
                cout << "Enter your Last Name : ";
                cin>>customerLastName;
                u.setLastName(customerLastName);
                if (u.validateName())
                {
                    flag = false;
                }
                else
                {
                    cout << "\n(Your fullname should atleast contain 6 letters without any special characters or numbers)\n";
                }
            }

            Starters st;
            MainCourse main;
            Dessert sweet;
            thread t1(&Starters::setMenuList, &st);
            thread t2(&MainCourse::setMenuList, &main);
            thread t3(&Dessert::setMenuList, &sweet);
            t1.join();
            t2.join();
            t3.join();

            bool ratingFlag = false;
            int starterPrice = 0, mainCoursePrice = 0, dessertPrice = 0;
            vector<string> starterOrderList, mainOrderList, dessertOrderList;
            Order mainCourseOrderObj, starterOrderObj, dessertOrderObj;
            thread t4(&Order::Starters::setMenuList, &starterOrderObj);
            thread t5(&Order::MainCourse::setMenuList, &mainCourseOrderObj);
            thread t6(&Order::Dessert::setMenuList, &dessertOrderObj);
            t4.join();
            t5.join();
            t6.join();

            while (true)
            {

                cout << "\nPress A to see Restaurant Details" << endl;
                cout << "Press B to see Menu" << endl;
                cout << "Press C to get food receipt" << endl;
                cout << "Press D to rate your experience" << endl;
                cout << "Press X to exit\n\n";
                string choice;
                cout << "Enter your choice here : ";
                cin >> choice;

                if (choice == "A" || choice == "a")
                {
                    system("clear");
                    Restaurant r;
                    r.showDetails();
                }
                else if (choice == "B" || choice == "b")
                {
                    // Menu m;

                    while (true)
                    {
                        // system("clear");
                        cout << "\nPress S to see Starters Menu." << endl;
                        cout << "Press M to see Main Course Menu." << endl;
                        cout << "Press D to see Dessert Menu." << endl;
                        cout << "Press X to return to previous Menu." << endl;
                        cout << "\nEnter your choice here : ";
                        string menuChoice;
                        cin >> menuChoice;
                        if (menuChoice == "S" || menuChoice == "s")
                        {
                            system("clear");
                            // Starters st;
                            st.display();
                            string ch;
                            while (true)
                            {
                                cout << "\nDo you wish to order something from Starters? \n(press Y for Yes or any other key for No) : ";
                                cin >> ch;
                                if (ch == "y" || ch == "Y")
                                {
                                    cin.ignore();
                                    string orderInput;
                                    cout << "Enter the item Id of items you wish to order(use comma if you want multiple items): ";
                                    getline(cin, orderInput);
                                    starterOrderObj.setOrderInput(orderInput);
                                    starterOrderList = starterOrderObj.getOrderList();
                                    starterPrice = starterOrderObj.getStarterOrderCost();
                                    system("clear");
                                    break;
                                }
                                else if (ch == "n" || ch == "N")
                                {
                                    system("clear");
                                    break;
                                }
                                else
                                {
                                    cout << "Please select Y for Yes and N for No only \n";
                                }
                            }
                        }
                        else if (menuChoice == "M" || menuChoice == "m")
                        {
                            system("clear");
                            // MainCourse main;
                            main.display();
                            cout << endl;
                            string ch;
                            while (true)
                            {
                                cout << "\nDo you wish to order something from Main course? \n(press Y for Yes or any other key for No) : ";
                                cin >> ch;
                                if (ch == "y" || ch == "Y")
                                {
                                    cin.ignore();
                                    string orderInput;
                                    cout << "Enter the item Id of items you wish to order(use comma if you want multiple items): ";
                                    getline(cin, orderInput);
                                    mainCourseOrderObj.setOrderInput(orderInput);
                                    mainOrderList = mainCourseOrderObj.getOrderList();
                                    mainCoursePrice = mainCourseOrderObj.getMainCourseOrderCost();
                                    break;
                                }
                                else if (ch == "n" || ch == "N")
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "Please select Y for Yes and N for No only \n";
                                }
                            }
                        }
                        else if (menuChoice == "D" || menuChoice == "d")
                        {
                            system("clear");
                            // Dessert sweet;
                            sweet.display();
                            cout << endl;
                            string ch;
                            while (true)
                            {
                                cout << "\nDo you wish to order something from Dessert? \n(press Y for Yes or any other key for No) : ";
                                cin >> ch;
                                if (ch == "y" || ch == "Y")
                                {
                                    cin.ignore();
                                    string orderInput;
                                    cout << "Enter the item Id of items you wish to order(use comma if you want multiple items): ";
                                    getline(cin, orderInput);
                                    dessertOrderObj.setOrderInput(orderInput);
                                    dessertOrderList = dessertOrderObj.getOrderList();
                                    dessertPrice = dessertOrderObj.getDessertOrderCost();
                                    break;
                                }
                                else if (ch == "n" || ch == "N")
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "Please select Y for Yes and N for No only \n";
                                }
                            }
                        }
                        else if (menuChoice == "X" || menuChoice == "x")
                        {
                            system("clear");
                            break;
                        }
                        else
                        {
                            system("clear");
                            cout << "Invalid Response" << endl;
                        }
                    }
                }
                else if (choice == "C" || choice == "c")
                {
                    if (!starterPrice && !mainCoursePrice && !dessertPrice)
                    {
                        system("clear");
                        cout << "\nYou have to order atleast one food item to generate a receipt.\n";
                    }
                    else
                    {
                        system("clear");
                        string customerName = u.getFullName();
                        Receipt bill(customerName, starterOrderList, mainOrderList, dessertOrderList, starterPrice, mainCoursePrice, dessertPrice);
                        string singleReceipt = bill.getReceipt();
                        // bill.getReceipt();
                        // thread t1(&Receipt::getReceipt, &bill);
                        // std::future<string> result = std::async(std::launch::async,&Receipt::getReceipt, &bill);
                        // string singleReceipt = result.get();
                        // thread t2(&Receipt::addReceiptToFile, &bill);
                        // t1.join();
                        // t2.join();
                        cout << singleReceipt << endl;
                        bill.addReceiptToFile();
                        starterPrice = 0, mainCoursePrice = 0, dessertPrice = 0;
                        starterOrderList.clear(), mainOrderList.clear(), dessertOrderList.clear();
                        starterOrderObj.setOrderList(), mainCourseOrderObj.setOrderList(), dessertOrderObj.setOrderList();
                        ratingFlag = true;
                    }
                }
                else if (choice == "D" || choice == "d")
                {
                    Rating r;
                    int choice;
                    if (ratingFlag)
                    {
                        system("clear");
                        ratingFlag = false;
                        while (true)
                        {
                            r.takeRating();
                            
                            cout << "Enter your response here: ";
                            if (cin >> choice)
                            {
                                if (choice > 0 && choice < 6)
                                {
                                    // Input is valid, break out of the loop
                                    break;
                                }
                                else
                                {
                                    cout << "Please rate from 1-5. \n";
                                }
                            }
                            else
                            {
                                // Input is not an integer, clear the input buffer and ignore invalid input
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                std::cout << "Invalid input. Please enter a valid integer." << std::endl;
                            }
                        }
                        r.setRating(choice);
                        r.displayRating();
                        usleep(2500000);
                        system("clear");
                    }
                    else
                    {
                        system("clear");
                        cout << "\nPlease order food and generate food receipt before rating your experience. \n";
                    }
                }
                else if (choice == "X" || choice == "x")
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
                    system("clear");
                    cout << " Invalid Response" << endl;
                }
            }
        }
    }
    else if (reply == "B" || reply == "b")
    {
        system("clear");
        string uname, pwd;
        string sysUname, sysPwd;
        cout << "Welcome to Administrator Login portal" << endl;
        Administrator admin;
        int tries = 3;
        while (tries)
        {
            cout << "Username : ";
            cin >> uname;
            cout << "Password : ";
            char ch;
            // ch=getch();
            // while(ch!=13){
            //     pwd.push_back(ch);
            //     cout<<'*';
            //     ch=getch();
            // }
            cin >> pwd;

            sysUname = admin.getUsername();
            sysPwd = admin.getPassword();
            if (sysUname != uname || sysPwd != pwd)
            {
                tries--;
                cout << "You have entered the wrong credentials" << endl;
                cout << "You have " << tries << " more tries left\n";
            }
            else
            {
                break;
            }
        }
        if (!tries){
            return 0;
        }

        cout << "\nYou are inside the Administrator portal\n\n";
        while (true)
        {
            cout << "Press A to access Transaction logbook." << endl;
            cout << "Press B to see average rating of the restaurant" << endl;
            cout << "Press C to access Total revenue of the restaurant" << endl;
            cout << "Press X to Exit" << endl;
            string choice;
            cin >> choice;
            if (choice == "A" || choice == "a")
            {
                system("clear");
                string log = admin.getLogbook();
                cout << log << endl;
            }
            else if (choice == "B" || choice == "b")
            {
                system("clear");
                float average = admin.avgRating();
                cout << "\nThe average rating of the restaurant is : " << average <<"\n\n";
            }
            else if (choice == "C" || choice == "c")
            {
                system("clear");
                int totalRev = admin.totalRevenue();
                cout << "\nThe total revenue collection of the restaurant is Rs." << totalRev << "\n\n";
            }
            else if (choice == "X" || choice == "x")
            {
                return 0;
            }
            else
            {
                cout << "Invalid response" << endl;
            }
        }
        // }
    }
    return 0;
}
