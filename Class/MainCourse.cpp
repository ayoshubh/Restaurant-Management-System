#include "MainCourse.h"

MainCourse::MainCourse() {
    this->fileName = "TextFiles/MainCourseFile.txt";
}

void MainCourse::setMenuList() {
    this->menuList = getMenu(fileName);
}

void MainCourse::display() {
    std::cout << " _____Main Course Menu_____ \n\n";

    for (int i = 0; i < menuList.size(); i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 1) {
                std::cout << menuList[i][j];
                for (int k = menuList[i][1].size(); k < 20; k++) {
                    std::cout << " ";
                }
                continue;
            }

            if (j == 2) {
                std::cout << "Rs." << menuList[i][j];
                continue;
            }
            std::cout << menuList[i][j] << "\t";
        }
        std::cout << "\n\n";
    }
}
