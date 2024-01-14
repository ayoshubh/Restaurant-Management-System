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

int main()
{
    try
    {
        std::string reply;
        while (true)
        {
            system("clear");
            Restaurant r;
            r.showDetails();
            std::cout << "\nPress A if you are a customer" << std::endl;
            std::cout << "Press B if you are an administrator" << std::endl;
            std::cout << "Press X to exit\n";
            std::cout << "Enter your response here : ";
            std::cin >> reply;
            if (reply == "A" || reply == "a" || reply == "B" || reply == "b")
            {
                break;
            }
            else if (reply == "X" || reply == "x")
            {
                std::cout << "Are you sure you want to exit?(Y/N)" << std::endl;
                std::cin >> reply;
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
                    std::cout << "Invalid response. Please enter Y for yes and N for no." << std::endl;
                    usleep(2500000);
                }
            }
            else
            {
                std::cout << "Invalid response. Try again";
            }
        }
        if (reply == "A" || reply == "a")
        {
            system("clear");
            if (User::validateEntry())
            {
                User u;
                std::string customerFirstName, customerLastName;
                bool flag = true;
                while (flag)
                {
                    std::cout << "Enter your First Name : ";
                    std::cin >> customerFirstName;
                    u.setFirstName(customerFirstName);
                    std::cout << "Enter your Last Name : ";
                    std::cin >> customerLastName;
                    u.setLastName(customerLastName);
                    if (u.validateName())
                    {
                        flag = false;
                    }
                    else
                    {
                        std::cout << "\n(Your fullname should atleast contain 6 letters without any special characters or numbers)\n";
                    }
                }
                Starters st;
                MainCourse main;
                Dessert sweet;
                std::vector<std::thread> threads;
                threads.push_back(std::thread(&Starters::setMenuList, &st));
                threads.push_back(std::thread(&MainCourse::setMenuList, &main));
                threads.push_back(std::thread(&Dessert::setMenuList, &sweet));
                for (int i = 0; i < 3; i++)
                {
                    threads[i].join();
                }
                std::vector<std::vector<std::string>> sList = st.getMenuList();
                std::vector<std::vector<std::string>> mList = main.getMenuList();
                std::vector<std::vector<std::string>> dList = sweet.getMenuList();
                bool ratingFlag = false;
                int starterPrice = 0, mainCoursePrice = 0, dessertPrice = 0;
                std::vector<std::string> starterOrderList, mainOrderList, dessertOrderList;
                Order mainCourseOrderObj({}, mList, {}), starterOrderObj(sList, {}, {}), dessertOrderObj({}, {}, dList);
                while (true)
                {
                    // cout << "\nPress A to see Restaurant Details" << endl;
                    std::cout << "\nPress A to see Menu" << std::endl;
                    std::cout << "Press B to get food receipt" << std::endl;
                    std::cout << "Press C to rate your experience" << std::endl;
                    std::cout << "Press X to exit\n\n";
                    std::string choice;
                    std::cout << "Enter your choice here : ";
                    std::cin >> choice;

                    if (choice == "A" || choice == "a")
                    {
                        // Menu m;
                        while (true)
                        {
                            // system("clear");
                            std::cout << "\nPress S to see Starters Menu." << std::endl;
                            std::cout << "Press M to see Main Course Menu." << std::endl;
                            std::cout << "Press D to see Dessert Menu." << std::endl;
                            std::cout << "Press X to return to previous Menu." << std::endl;
                            std::cout << "\nEnter your choice here : ";
                            std::string menuChoice;
                            std::cin >> menuChoice;
                            if (menuChoice == "S" || menuChoice == "s")
                            {
                                system("clear");
                                // Starters st;
                                st.display();
                                std::string ch;
                                while (true)
                                {
                                    std::cout << "\nDo you wish to order something from Starters? \n(press Y for Yes or N for No) : ";
                                    std::cin >> ch;
                                    if (ch == "y" || ch == "Y")
                                    {
                                        std::cin.ignore(); //to clear the input buffer
                                        std::string orderInput;
                                        std::cout << "Enter the item Id of items you wish to order(use comma if you want multiple items): ";
                                        std::getline(std::cin, orderInput);
                                        starterOrderObj.setOrderInput(orderInput);
                                        std::vector<std::string> orderList = starterOrderObj.getOrderList();
                                        for (std::string i : orderList)
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
                                        std::cout << "Please select Y for Yes and N for No only \n";
                                    }
                                }
                            }
                            else if (menuChoice == "M" || menuChoice == "m")
                            {
                                system("clear");
                                // MainCourse main;
                                main.display();
                                std::cout << std::endl;
                                std::string ch;
                                while (true)
                                {
                                    std::cout << "\nDo you wish to order something from Main course? \n(press Y for Yes or N for No) : ";
                                    std::cin >> ch;
                                    if (ch == "y" || ch == "Y")
                                    {
                                        std::cin.ignore();
                                        std::string orderInput;
                                        std::cout << "Enter the item Id of items you wish to order(use comma if you want multiple items): ";
                                        std::getline(std::cin, orderInput);
                                        mainCourseOrderObj.setOrderInput(orderInput);
                                        std::vector<std::string> orderList = mainCourseOrderObj.getOrderList();
                                        for (std::string i : orderList)
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
                                        std::cout << "Please select Y for Yes and N for No only \n";
                                    }
                                }
                            }
                            else if (menuChoice == "D" || menuChoice == "d")
                            {
                                system("clear");
                                // Dessert sweet;
                                sweet.display();
                                std::cout << std::endl;
                                std::string ch;
                                while (true)
                                {
                                    std::cout << "\nDo you wish to order something from Dessert? \n(press Y for Yes or N for No) : ";
                                    std::cin >> ch;
                                    if (ch == "y" || ch == "Y")
                                    {
                                        std::cin.ignore();
                                        std::string orderInput;
                                        std::cout << "Enter the item Id of items you wish to order(use comma if you want multiple items): ";
                                        getline(std::cin, orderInput);
                                        dessertOrderObj.setOrderInput(orderInput);
                                        std::vector<std::string> orderList = dessertOrderObj.getOrderList();
                                        for (std::string i : orderList)
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
                                        std::cout << "Please select Y for Yes and N for No only \n";
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
                                std::cout << "Invalid Response" << std::endl;
                            }
                        }
                    }
                    else if (choice == "B" || choice == "b")
                    {
                        if (!starterPrice && !mainCoursePrice && !dessertPrice)
                        {
                            system("clear");
                            std::cout << "\nYou have to order atleast one food item to generate a receipt.\n";
                        }
                        else
                        {
                            system("clear");
                            std::string singleReceipt;
                            std::string customerName = u.getFullName();
                            Receipt bill(customerName, starterOrderList, mainOrderList, dessertOrderList, starterPrice, mainCoursePrice, dessertPrice);
                            std::thread thread1(&Receipt::addReceiptToFile, &bill);
                            std::thread thread2(&Receipt::addReceiptToIndividualFile, &bill);
                            singleReceipt = bill.getReceipt();
                            std::cout << singleReceipt << std::endl;
                            bill.notify(singleReceipt);
                            thread1.join();
                            thread2.join();
                            // bill.addReceiptToFile();
                            starterPrice = 0, mainCoursePrice = 0, dessertPrice = 0;
                            starterOrderList.clear(), mainOrderList.clear(), dessertOrderList.clear();
                            starterOrderObj.clearOrderList(), mainCourseOrderObj.clearOrderList(), dessertOrderObj.clearOrderList();
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
                                r.showRatingLevel();

                                std::cout << "Enter your response here: ";
                                if (std::cin >> choice)
                                {
                                    if (choice > 0 && choice < 6)
                                    {
                                        // Input is valid, break out of the loop
                                        break;
                                    }
                                    else
                                    {
                                        std::cout << "Please rate from 1-5. \n";
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
                            r.displayResponse();
                            usleep(2500000);
                            char feedbackChoice;
                            std::string feedbackString;
                            std::cout << "Do you wish to write us a feedback too?(Y/N)\n";
                            std::cin >> feedbackChoice;
                            if (feedbackChoice == 'y' || feedbackChoice == 'Y')
                            {
                                std::cout << "Please input how you feel about our service below:\n";
                                std::cin.ignore();
                                std::getline(std::cin, feedbackString);
                                r.setFeedback(feedbackString);
                            }
                            return 0;
                            system("clear");
                        }
                        else
                        {
                            system("clear");
                            std::cout << "\nPlease order food and generate food receipt before rating your experience. \n";
                        }
                    }
                    else if (choice == "X" || choice == "x")
                    {
                        if (!starterPrice && !mainCoursePrice && !dessertPrice)
                        {
                            std::cout << "Are you sure you want to exit?(Y/N)" << std::endl;
                            std::cin >> reply;
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
                                std::cout << "Invalid response. Please enter Y for yes and N for no." << std::endl;
                                continue;
                            }
                        }
                        else
                        {
                            std::cout << "\nYou cannot exit without generating the food receipt.\n";
                        }
                    }
                    else
                    {
                        system("clear");
                        std::cout << " Invalid Response" << std::endl;
                    }
                }
            }
        }
        else if (reply == "B" || reply == "b")
        {
            system("clear");
            std::string uname, pwd;
            std::string sysUname, sysPwd;
            std::cout << "Welcome to Administrator Login portal" << std::endl;
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
                    std::cout << "You have entered the wrong credentials" << std::endl;
                    std::cout << "You have " << tries << " more tries left\n";
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

            std::cout << "\nYou are inside the Administrator portal\n\n";
            system("clear");

            while (true)
            {
                std::cout << "Press A to access Transaction logbook." << std::endl;
                std::cout << "Press B to see average rating of the restaurant" << std::endl;
                std::cout << "Press C to access Total revenue of the restaurant" << std::endl;
                std::cout << "Press X to Exit" << std::endl;
                std::string choice;
                std::cin >> choice;
                if (choice == "A" || choice == "a")
                {
                    system("clear");
                    std::string date, month, year;
                    std::cout << "Input the date, month number and year: ";
                    std::cin >> date >> month >> year;
                    std::string log = admin.getLogbook(date, month, year);
                    std::cout << log << std::endl;
                }
                else if (choice == "B" || choice == "b")
                {
                    system("clear");

                    float average = admin.avgRating();
                    std::cout << "\nThe average rating of the restaurant is : " << average << "\n\n";
                }
                else if (choice == "C" || choice == "c")
                {
                    system("clear");
                    char ch;
                    std::cout << "Press A if you want to see yearly revenue of the restaurant. \n";
                    std::cout << "Press B if you want to see monthly revenue of the restaurant. \n";
                    std::cin >> ch;
                    std::string month, year;
                    int totalRev;
                    switch (ch)
                    {
                    case 'B':
                        std::cout << "Enter the month(1-12) and the year(yyyy): ";
                        std::cin >> month >> year;
                        totalRev = admin.totalRevenue(month, year);
                        break;
                    case 'A':
                        std::cout << "Enter the year(yyyy): ";
                        std::cin >> year;
                        totalRev = admin.totalRevenue("",year);
                        break;
                    }
                    std::cout << "\nThe total revenue collection of the restaurant is Rs." << totalRev << "\n\n";

                }
                else if (choice == "X" || choice == "x")
                {
                    std::cout << "Are you sure you want to exit?(Y/N)" << std::endl;
                    std::cin >> reply;
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
                        std::cout << "Invalid response. Please enter Y for yes and N for no." << std::endl;
                        continue;
                    }
                }
                else
                {
                    std::cout << "Invalid response" << std::endl;
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
