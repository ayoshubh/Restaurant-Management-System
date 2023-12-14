#include "Rating.h"
using namespace std;
void Rating::takeRating() {
    std::cout << "\nEnter 1 for Very Bad Experience" << std::endl;
    std::cout << "Enter 2 for Dissatisfied Experience" << std::endl;
    std::cout << "Enter 3 for Somewhat Good Experience" << std::endl;
    std::cout << "Enter 4 for Good Experience" << std::endl;
    std::cout << "Enter 5 for Excellent Experience\n" << std::endl;
}

void Rating::setRating(int rate) {
    choice = rate;
}

void Rating::displayRating() {
    switch (choice) {
        case oneStar:
            std::cout << "We are sorry for your unfavorable experience" << std::endl;
            break;
        case twoStar:
            std::cout << "Thank you for your feedback. We will try our best to give you a satisfactory service" << std::endl;
            break;
        case threeStar:
            std::cout << "Thank you for your feedback." << std::endl;
            break;
        case fourStar:
            std::cout << "We are glad that you liked our service" << std::endl;
            break;
        case fiveStar:
            std::cout << "Thank you for your positive feedback. It means a lot to us" << std::endl;
            break;
        default:
            std::cout << "Invalid response. Please try again" << std::endl;
    }

    std::ofstream file("TextFiles/RatingFile.txt", std::ios::app);
    file << choice << "\n";
    file.close();
}
