#include "User.h"
using namespace std;
void User::setFirstName(std::string name) {
    if (name.size() >= 3 && name.size() <= 20) {
        for (char ch : name) {
            if (!isalpha(ch)) {
                return;
            }
        }
        for (int i = 0; i < name.size(); i++) {
            name[i] = tolower(name[i]);
        }
        firstName = name;
    }
}

void User::setLastName(std::string name) {
    if (name.size() >= 3 && name.size() <= 30) {
        for (char ch : name) {
            if (!isalpha(ch)) {
                return;
            }
        }
        for (int i = 0; i < name.size(); i++) {
            name[i] = tolower(name[i]);
        }
        lastName = name;
        fullName = firstName + " " + lastName;
    }
}

std::string User::getFullName() const {
    return fullName;
}

bool User::validateName() const {
    return !(firstName.empty() || lastName.empty());
}

bool User::validateEntry() {
    auto now = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);
    tm local_time = *std::localtime(&current_time);
    int current_hour = local_time.tm_hour;

    if (10 <= current_hour && current_hour < 22) {
        std::cout << "Welcome to Food Villa \n";
        return true;
    } else {
        std::cout << "Sorry, we are not open right now \n";
        return true;
    }
}
