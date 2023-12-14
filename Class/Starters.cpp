#include "Starters.h"
using namespace std;
Starters::Starters() {
    this->fileName = "TextFiles/StarterFile.txt";
}

void Starters::setMenuList() {
    this->menuList = getMenu(fileName);
}

void Starters::display() {
    std::cout << " _____Starters Menu_____ \n\n";

    for (int i = 0; i < menuList.size(); i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 1) {
                std::cout << menuList[i][j];
                for (int j = menuList[i][1].size(); j < 20; j++) {
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
