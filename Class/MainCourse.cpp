#include "MainCourse.h"

MainCourse::MainCourse()
{
    this->fileName = "TextFiles/MainCourseFile.txt";
}

void MainCourse::setMenuList()
{
    this->menuList = getMenu(fileName);
}

std::vector<std::vector<std::string>> MainCourse::getMenuList()
{
    return this->menuList;
}

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
