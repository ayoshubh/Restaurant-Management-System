/**
 * @file Starters.cpp
 * @author Shubham Chauhan
 * @brief This file contains implementation for Starters class which is inherited from Menu class.
 * @version 0.1
 * @date 2024-01-08
 * @copyright Copyright (c) 2024
 */
#include "Starters.h"

/**
 * @brief Construct a new Starters:: Starters object
 * data member fileName has been initialised in the constructor.
 */
Starters::Starters()
{
    this->fileName = "TextFiles/StarterFile.txt";
}

/**
 * @brief Setter method to initialise data member menuList.
 */
void Starters::setMenuList()
{
    this->menuList = getMenu(fileName);
}

/**
 * @brief getter method to return the menu of the starters.
 * @return std::vector<std::vector<std::string>> 
 */
std::vector<std::vector<std::string>> Starters::getMenuList()
{
    return this->menuList;
}

/**
 * @brief This method is used to display the starters' menu in a tabular form.
 */
void Starters::display()
{
    std::cout << " _____Starters Menu_____ \n\n";
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
