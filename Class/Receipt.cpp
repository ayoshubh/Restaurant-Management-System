#include "Receipt.h"
using namespace std;
Receipt::Receipt(std::string cname, std::vector<std::string> starterStr, std::vector<std::string> mainStr, std::vector<std::string> dessertStr, int starterPrice, int mainCoursePrice, int dessertPrice)
{
    this->starterStr = starterStr;
    this->mainStr = mainStr;
    this->dessertStr = dessertStr;
    this->starterPrice = starterPrice;
    this->mainCoursePrice = mainCoursePrice;
    this->dessertPrice = dessertPrice;
    totalCost = starterPrice + mainCoursePrice + dessertPrice;
    customerName = cname;
    itemName = getOrderedItems();
    itemName2 = itemName;
    receiptGenerated = false;
}

std::string Receipt::getOrderedItems()
{
    try
    {
        std::vector<std::vector<std::string>> start = Starters::getMenu("TextFiles/StarterFile.txt");

        for (int i = 0; i < starterStr.size(); i++)
        {
            for (int j = 0; j < start.size(); j++)
            {
                if (starterStr[i] == start[j][0])
                {
                    itemName += start[j][1];
                    for (int k = start[j][1].size(); k < 20; k++)
                    {
                        itemName += '-';
                    }
                    itemName += "Rs.";
                    itemName += start[j][2];
                    itemName += '\n';
                    break;
                }
            }
        }

        start = MainCourse::getMenu("TextFiles/MainCourseFile.txt");
        for (int i = 0; i < mainStr.size(); i++)
        {
            for (int j = 0; j < start.size(); j++)
            {
                if (mainStr[i] == start[j][0])
                {
                    itemName += start[j][1];
                    for (int k = start[j][1].size(); k < 20; k++)
                    {
                        itemName += '-';
                    }
                    itemName += "Rs.";
                    itemName += start[j][2];
                    itemName += '\n';
                    break;
                }
            }
        }

        start = Dessert::getMenu("TextFiles/DessertFile.txt");
        for (int i = 0; i < dessertStr.size(); i++)
        {
            for (int j = 0; j < start.size(); j++)
            {
                if (dessertStr[i] == start[j][0])
                {
                    itemName += start[j][1];
                    for (int k = start[j][1].size(); k < 20; k++)
                    {
                        itemName += '-';
                    }
                    itemName += "Rs.";
                    itemName += start[j][2];
                    itemName += '\n';
                    break;
                }
            }
        }

        return itemName;
    }
    catch (const std::exception &e)
    {
        // Handle other exceptions
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

std::string Receipt::getReceipt()
{
    try
    {
        time_t t = time(nullptr);
        tm *now = localtime(&t);
        // Format the current time as a string
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", now);
        std::string formattedDateTime(buffer);

        receipt += "\n*Customer Name : ";
        receipt += customerName;
        receipt += "\n";
        receipt += "Time: ";
        receipt += formattedDateTime;
        receipt += "\nOrdered Items:\n";
        receipt += itemName;
        receipt += "--------------------------\n";
        receipt += " Total Bill :      Rs.";
        receipt += std::to_string(totalCost);
        receipt += "\n--------------------------\n";

        return receipt;
    }
    catch (const std::invalid_argument &e)
    {
        // Handle invalid argument exception
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        // Handle other exceptions
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Receipt::writeToFile(const std::string &name, const std::string &filename)
{
    std::ofstream file(filename, std::ios::app);
    if (file.is_open())
    {
        file << name << "\n";
        file.close();
        // std::cout << "Thread wrote to file: " << filename << std::endl;
    }
    else
    {
        std::cerr << "Unable to open the file for writing: " << filename << std::endl;
    }
}

void Receipt::addReceiptToFile()
{
    try
    {
        std::ofstream file2("TextFiles/RevenueReceipt.txt", std::ios::app);
        if (!file2.is_open())
        {
            throw std::runtime_error("Failed to open the RevenueReceipt file");
        }
        file2 << totalCost << "\n";
        file2.close();

        time_t t = time(nullptr);
        tm *now = localtime(&t);
        // Format the current time as a string
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%m-%Y", now);
        string formattedDateTime(buffer);
        string fileNamex = "TextFiles/RevenueFiles/RevenueOf:";
        fileNamex += formattedDateTime;
        fileNamex += ".txt";
        writeToFile(to_string(totalCost), fileNamex);
        strftime(buffer, sizeof(buffer), "%Y", now);
        string formattedDateTime2(buffer);
        fileNamex = "TextFiles/RevenueFiles/RevenueOf:";
        fileNamex += formattedDateTime2;
        fileNamex += ".txt";
        writeToFile(to_string(totalCost), fileNamex);
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]
                { return receiptGenerated; });
        writeToFile(receipt, "TextFiles/TotalReceiptFile.txt");
    }
    catch (const std::ios_base::failure &e)
    {
        // Handle file I/O exception
        std::cerr << "File I/O exception: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        // Handle other exceptions
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Receipt::addReceiptToIndividualFile()
{
    // time_t t = time(nullptr);
    // tm *now = localtime(&t);
    // // Format the current time as a string
    // char buffer[20];
    // strftime(buffer, sizeof(buffer), "%d-%m-%Y", now);
    // string formattedDateTime(buffer);
    // string fileNamex = "TextFiles/DatedReceiptFiles/ReceiptFile:";
    // fileNamex += formattedDateTime;
    // fileNamex += ".txt";
    // ofstream file3(fileNamex, ios::app);
    // std::unique_lock<std::mutex> lock(mtx);
    // cv.wait(lock, [this] { return receipt; });
    // file3 << receipt;
    // file3.close();

    time_t t = time(nullptr);
    tm *now = localtime(&t);
    // Format the current time as a string
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", now);
    string formattedDateTime(buffer);
    string fileNamex = "TextFiles/DatedReceiptFiles/ReceiptFile:";
    fileNamex += formattedDateTime;
    fileNamex += ".txt";
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this]
            { return receiptGenerated; });
    // file << receipt;
    writeToFile(receipt, fileNamex);
}

void Receipt::notify(const std::string &name)
{
    std::lock_guard<std::mutex> lock(mtx);
    receipt = name;
    receiptGenerated = true;
    cv.notify_all();
}