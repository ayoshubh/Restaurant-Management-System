#include "Administrator.h"

Administrator::Administrator() {
    username = "ad12";
    password = "pwd12";
}

std::string Administrator::getUsername() {
    return username;
}

std::string Administrator::getPassword() {
    return password;
}

std::string Administrator::getLogbook() {
    std::ifstream file("TextFiles/TotalReceiptFile.txt");

    std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>())); // Read the entire file

    file.close(); // Close the file

    return content;
}

int Administrator::totalRevenue() {
    std::ifstream inputFile("TextFiles/RevenueReceipt.txt"); // Assuming the file is named "RevenueReceipt.txt"

    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return -1; // Return an error code
    }

    int number;
    int sum = 0;
    while (inputFile >> number) {
        sum += number;
    }

    inputFile.close();
    return sum;
}

float Administrator::avgRating() {
    std::ifstream inputFile("TextFiles/RatingFile.txt"); // Assuming the file is named "RatingFile.txt"

    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return -1.0f; // Return an error code
    }

    float number;
    float sum = 0.0f;
    float count = 0.0f;

    while (inputFile >> number) {
        sum += number;
        count += 1.0f;
    }

    float avg = sum / count;
    inputFile.close();
    return avg;
}
