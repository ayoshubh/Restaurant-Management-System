#include "Administrator.h"

Administrator::Administrator()
{
    std::ifstream file("TextFiles/AdminCredential.txt");
    std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
    int strCount = 0;
    for (int i = 0; i < content.size(); i++)
    {
        if (content[i] == '\n')
        {
            strCount = i;
            break;
        }
        this->username += content[i];
    }

    for (int i = strCount + 1; i < content.size(); i++)
    {
        this->password += content[i];
    }
}

std::string Administrator::getUsername()
{
    return username;
}

std::string Administrator::getPassword()
{
    return password;
}

std::string Administrator::getLogbook()
{
    try
    {
        std::ifstream file("TextFiles/TotalReceiptFile.txt");

        std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>())); // Read the entire file

        file.close(); // Close the file

        return content;
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

int Administrator::totalRevenue()
{
    try
    {

        std::ifstream inputFile("TextFiles/RevenueReceipt.txt");

        if (!inputFile.is_open())
        {
            std::cerr << "Unable to open the file." << std::endl;
            return -1; // Return an error code
        }

        int number;
        int sum = 0;
        while (inputFile >> number)
        {
            sum += number;
        }

        inputFile.close();
        return sum;
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

float Administrator::avgRating()
{
    try
    {
        std::ifstream inputFile("TextFiles/RatingFile.txt"); // Assuming the file is named "RatingFile.txt"

        if (!inputFile.is_open())
        {
            std::cerr << "Unable to open the file." << std::endl;
            return -1.0f; // Return an error code
        }

        float number;
        float sum = 0.0f;
        float count = 0.0f;

        while (inputFile >> number)
        {
            sum += number;
            count += 1.0f;
        }

        float avg = sum / count;
        inputFile.close();
        return avg;
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
