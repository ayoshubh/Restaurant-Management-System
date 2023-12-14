#include "Dessert.h"

Dessert::Dessert() {
    this->fileName = "TextFiles/DessertFile.txt";
}

void Dessert::setMenuList() {
    this->menuList = getMenu(fileName);
}

void Dessert::display() {
    std::cout << " _____Dessert Menu_____ \n\n";

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
