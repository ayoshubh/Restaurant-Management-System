/**
 * @file MainCourse.cpp
 * @author Shubham Chauhan
 * @brief This file contains implementation for MainCourse class which is inherited from Menu class.
 * @version 0.1
 * @date 2024-01-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "MainCourse.h"

/**
 * @brief Construct a new Main Course:: Main Course object
 * data member fileName has been initialised in the constructor.
 */
MainCourse::MainCourse()
{
    this->fileName = "TextFiles/MainCourseFile.txt";
}

/**
 * @brief Setter method to initialise data member menuList.
 */
void MainCourse::setMenuList()
{
    this->menuList = getMenu(fileName);
}

/**
 * @brief getter method to return the menu of the main course.
 * @return std::vector<std::vector<std::string>> 
 */
std::vector<std::vector<std::string>> MainCourse::getMenuList()
{
    return this->menuList;
}

/**
 * @brief This method is used to display the Main course menu in a tabular form.
 */
void MainCourse::display()
{
    std::cout << " _____Main Course Menu_____ \n\n";

    try
    {
        for (int i = 0; i < menuList.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j == 1)
                {
                    std::cout << menuList[i][j];
                    for (int j = menuList[i][1].size(); j < 20; j++)
                    {
                        std::cout << " ";
                    }
                    continue;
                }

                if (j == 2)
                {
                    std::cout << "Rs." << menuList[i][j];
                    continue;
                }
                std::cout << menuList[i][j] << "\t";
            }
            std::cout << "\n\n";
        }
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Out of range exception: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        // Handle other exceptions
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
