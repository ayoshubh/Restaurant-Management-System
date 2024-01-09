#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <thread>
#include <ncurses.h>
#include <stdexcept>
#include <mutex>
#include <condition_variable>
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
    try
    {
        string reply;
        while (true)
        {
            system("clear");
            Restaurant r;
            r.showDetails();
            cout << "\nPress A if you are a customer" << endl;
            cout << "Press B if you are an administrator" << endl;
            cout << "Press X to exit\n";
            cout << "Enter your response here : ";
            cin >> reply;
            if (reply == "A" || reply == "a" || reply == "B" || reply == "b")
            {
                break;
            }
            else if (reply == "X" || reply == "x")
            {
                cout << "Are you sure you want to exit?(Y/N)" << endl;
                cin >> reply;
                if (reply == "y" || reply == "Y")
                {
                    break;
                }
                else if (reply == "n" || reply == "N")
                {
                    continue;
                }
                else
                {
                    cout << "Invalid response. Please enter Y for yes and N for no." << endl;
                    usleep(2500000);
                }
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
                    cin >> customerFirstName;
                    u.setFirstName(customerFirstName);
                    cout << "Enter your Last Name : ";
                    cin >> customerLastName;
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
                vector<thread> threads;
                threads.push_back(thread(&Starters::setMenuList, &st));
                threads.push_back(thread(&MainCourse::setMenuList, &main));
                threads.push_back(thread(&Dessert::setMenuList, &sweet));
                for (int i = 0; i < 3; i++)
                {
                    threads[i].join();
                }
                vector<vector<string>> sList = st.getMenuList();
                vector<vector<string>> mList = main.getMenuList();
                vector<vector<string>> dList = sweet.getMenuList();
                bool ratingFlag = false;
                int starterPrice = 0, mainCoursePrice = 0, dessertPrice = 0;
                vector<string> starterOrderList, mainOrderList, dessertOrderList;
                Order mainCourseOrderObj({}, mList, {}), starterOrderObj(sList, {}, {}), dessertOrderObj({}, {}, dList);
                while (true)
                {
                    // cout << "\nPress A to see Restaurant Details" << endl;
                    cout << "\nPress A to see Menu" << endl;
                    cout << "Press B to get food receipt" << endl;
                    cout << "Press C to rate your experience" << endl;
                    cout << "Press X to exit\n\n";
                    string choice;
                    cout << "Enter your choice here : ";
                    cin >> choice;

                    if (choice == "A" || choice == "a")
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
                                    cout << "\nDo you wish to order something from Starters? \n(press Y for Yes or N for No) : ";
                                    cin >> ch;
                                    if (ch == "y" || ch == "Y")
                                    {
                                        Order localObj;
                                        cin.ignore();
                                        string orderInput;
                                        cout << "Enter the item Id of items you wish to order(use comma if you want multiple items): ";
                                        getline(cin, orderInput);
                                        starterOrderObj.setOrderInput(orderInput);
                                        localObj.setOrderInput(orderInput);
                                        vector<string> orderList = starterOrderObj.getOrderList();
                                        for (string i : orderList)
                                        {
                                            starterOrderList.push_back(i);
                                        }
                                        starterPrice += starterOrderObj.getStarterOrderCost();
                                        usleep(2500000);
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
                                    cout << "\nDo you wish to order something from Main course? \n(press Y for Yes or N for No) : ";
                                    cin >> ch;
                                    if (ch == "y" || ch == "Y")
                                    {
                                        cin.ignore();
                                        string orderInput;
                                        cout << "Enter the item Id of items you wish to order(use comma if you want multiple items): ";
                                        getline(cin, orderInput);
                                        mainCourseOrderObj.setOrderInput(orderInput);
                                        vector<string> orderList = mainCourseOrderObj.getOrderList();
                                        for (string i : orderList)
                                        {
                                            mainOrderList.push_back(i);
                                        }
                                        mainCoursePrice += mainCourseOrderObj.getMainCourseOrderCost();
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
                                    cout << "\nDo you wish to order something from Dessert? \n(press Y for Yes or N for No) : ";
                                    cin >> ch;
                                    if (ch == "y" || ch == "Y")
                                    {
                                        cin.ignore();
                                        string orderInput;
                                        cout << "Enter the item Id of items you wish to order(use comma if you want multiple items): ";
                                        getline(cin, orderInput);
                                        dessertOrderObj.setOrderInput(orderInput);
                                        vector<string> orderList = dessertOrderObj.getOrderList();
                                        for (string i : orderList)
                                        {
                                            dessertOrderList.push_back(i);
                                        }
                                        dessertPrice += dessertOrderObj.getDessertOrderCost();
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
                    else if (choice == "B" || choice == "b")
                    {
                        if (!starterPrice && !mainCoursePrice && !dessertPrice)
                        {
                            system("clear");
                            cout << "\nYou have to order atleast one food item to generate a receipt.\n";
                        }
                        else
                        {
                            system("clear");
                            std::string singleReceipt;
                            string customerName = u.getFullName();
                            Receipt bill(customerName, starterOrderList, mainOrderList, dessertOrderList, starterPrice, mainCoursePrice, dessertPrice);
                            std::thread thread1(&Receipt::addReceiptToFile, &bill);
                            std::thread thread2(&Receipt::addReceiptToIndividualFile, &bill);
                            singleReceipt = bill.getReceipt();
                            cout << singleReceipt << endl;
                            bill.notify(singleReceipt);
                            thread1.join();
                            thread2.join();
                            // bill.addReceiptToFile();
                            starterPrice = 0, mainCoursePrice = 0, dessertPrice = 0;
                            starterOrderList.clear(), mainOrderList.clear(), dessertOrderList.clear();
                            starterOrderObj.setOrderList(), mainCourseOrderObj.setOrderList(), dessertOrderObj.setOrderList();
                            ratingFlag = true;
                        }
                    }
                    else if (choice == "C" || choice == "c")
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
                            char feedbackChoice;
                            std::string feedbackString;
                            std::cout<<"Do you wish to write us a feedback too?(Y/N)\n";
                            std::cin>>feedbackChoice;
                            if(feedbackChoice=='y' || feedbackChoice=='Y'){
                                cout<<"Please input how you feel about our service below:\n";
                                cin.ignore();
                                getline(cin,feedbackString);
                                r.setFeedback(feedbackString);
                            }
                            return 0;
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
                            cout << "Are you sure you want to exit?(Y/N)" << endl;
                            cin >> reply;
                            if (reply == "y" || reply == "Y")
                            {
                                system("clear");
                                break;
                            }
                            else if (reply == "n" || reply == "N")
                            {
                                system("clear");
                                continue;
                            }
                            else
                            {
                                cout << "Invalid response. Please enter Y for yes and N for no." << endl;
                                continue;
                            }
                        }
                        else
                        {
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
                // Initialize ncurses
                initscr();
                // cbreak(); // Line buffering disabled, pass on everything
                // Ask for user input
                printw("\n");
                printw("Enter username: ");
                refresh();
                echo();
                char username[100];
                getnstr(username, sizeof(username));
                // Ask for password with masking
                printw("Enter password: ");
                refresh();
                char password[100];
                noecho();
                int ch;
                int i = 0;
                while ((ch = getch()) != '\n')
                {
                    if (ch == 127 && i > 0)
                    {
                        // Handle backspace to erase the last character
                        printw("\b \b");
                        refresh();
                        i--;
                    }
                    else if (isprint(ch))
                    {
                        // Mask the character with asterisk and store in the password
                        printw("*");
                        refresh();
                        password[i] = ch;
                        i++;
                    }
                }
                password[i] = '\0'; // Null-terminate the password
                // End ncurses
                endwin();
                sysUname = admin.getUsername();
                sysPwd = admin.getPassword();
                if (sysUname != username || sysPwd != password)
                {
                    tries--;
                    cout << "You have entered the wrong credentials" << endl;
                    cout << "You have " << tries << " more tries left\n";
                    usleep(2000000);
                }
                else
                {
                    break;
                }
            }

            if (!tries)
            {
                return 0;
            }

            cout << "\nYou are inside the Administrator portal\n\n";
            system("clear");

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
                    int date, month, year;
                    std::cout<<"Input the date, month number and year: ";
                    std::cin >> date >> month >> year;
                    string log = admin.getLogbook(date,month,year);
                    cout << log << endl;
                }
                else if (choice == "B" || choice == "b")
                {
                    system("clear");
                    float average = admin.avgRating();
                    cout << "\nThe average rating of the restaurant is : " << average << "\n\n";
                }
                else if (choice == "C" || choice == "c")
                {
                    system("clear");
                    int totalRev = admin.totalRevenue();
                    cout << "\nThe total revenue collection of the restaurant is Rs." << totalRev << "\n\n";
                }
                else if (choice == "X" || choice == "x")
                {
                    cout << "Are you sure you want to exit?(Y/N)" << endl;
                    cin >> reply;
                    if (reply == "y" || reply == "Y")
                    {
                        system("clear");
                        break;
                    }
                    else if (reply == "n" || reply == "N")
                    {
                        system("clear");
                        continue;
                    }
                    else
                    {
                        cout << "Invalid response. Please enter Y for yes and N for no." << endl;
                        continue;
                    }
                }
                else
                {
                    cout << "Invalid response" << endl;
                }
            }
            // }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception in main: " << e.what() << std::endl;
    }
    return 0;
}
