#include "Menu.h"
std::vector<std::vector<std::string>> Menu::getMenu(std::string filename)
{
    try
    {
        std::ifstream file(filename);
        std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open the file\n");
        }
        file.close();

        for (int i = 0; i < content.size(); i++)
        {
            if (content[i] == '\n')
            {
                singleItemDetail += '-';
                std::vector<std::string> singleItemList;
                std::string word;

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
                singleItemDetail = "";
                continue;
            }
            singleItemDetail += content[i];
        }

        return menuList;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
