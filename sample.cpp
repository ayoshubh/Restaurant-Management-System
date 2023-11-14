// #include <iostream>
// #include <thread>
// #include<string>
// using namespace std;

// void test(int x){
//     cout<<"Hello from thread"<<endl;
//     cout<<"argument passed in: "<<x<<endl;
// }

//     enum rate{
//         oneStar=1,
//         twoStar,
//         threeStar,
//         fourStar,
//         fiveStar
//     } ;

// void takeRating(){
//     int choice;
//     cout<<"Enter 1 for Very Bad"<<endl;
//     cout<<"Enter 2 for Dissatisfied"<<endl;
//     cout<<"Enter 3 for Somewhat Good"<<endl;
//     cout<<"Enter 4 for Good"<<endl;
//     cout<<"Enter 5 for Excellent"<<endl;
//     cin>>choice;
    
//     switch(choice){
//         case oneStar: cout<<"We are sorry for your unfavourable experience"<<endl;
//         break;
//         case twoStar: cout<<"Thank you for your feedback. We will try our best to give you a satisfactory service"<<endl;
//         break;
//         case threeStar: cout<<"Thank you for your feedback."<<endl;
//         break;
//         case fourStar: cout<<"We are glad that you liked our service"<<endl;
//         break;
//         case fiveStar: cout<<"Thank you for your positive feedback.It means a lot to us"<<endl;
//         break;
//         default: cout<<"Invalid response. Please try again"<<endl;
//     }


// }

// int main(){
//     thread myThread(&test, 100);
//     myThread.join();
//     cout<<"Hello from my main thread"<<endl;

//     // cout<<oneStar<<endl;
//     takeRating();
    
//     return 0;
// }

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>

// struct MenuItem {
//     std::string id;
//     std::string name;
//     double price;
// };

// // Function to read menu items from file
// std::vector<MenuItem> readMenuFromFile(const std::string& filename) {
//     std::vector<MenuItem> menuItems;
//     std::ifstream file(filename);

//     if (file.is_open()) {
//         std::string line;
//         while (std::getline(file, line)) {
//             size_t dash1 = line.find('-');
//             size_t dash2 = line.rfind('-');

//             if (dash1 != std::string::npos && dash2 != std::string::npos && dash1 < dash2) {
//                 MenuItem item;
//                 item.id = line.substr(0, dash1);
//                 item.name = line.substr(dash1 + 1, dash2 - dash1 - 1);
//                 item.price = std::stod(line.substr(dash2 + 1));
//                 menuItems.push_back(item);
//             }
//         }

//         file.close();
//     } else {
//         std::cerr << "Unable to open file: " << filename << std::endl;
//     }

//     return menuItems;
// }

// // Function to add a new item to the menu file
// void addItemToFile(const std::string& filename, const MenuItem& newItem) {
//     std::ofstream file(filename, std::ios_base::app);

//     if (file.is_open()) {
//         file << std::endl << newItem.id << '-' << newItem.name << '-' << newItem.price << '\n';
//         file.close();
//         std::cout << "Item added successfully.\n";
//     } else {
//         std::cerr << "Unable to open file: " << filename << std::endl;
//     }
// }

// // Function to delete an item from the menu file
// void deleteItemFromFile(const std::string& filename, const std::string& itemId) {
//     std::vector<MenuItem> menuItems = readMenuFromFile(filename);

//     auto it = std::remove_if(menuItems.begin(), menuItems.end(),
//         [itemId](const MenuItem& item) { return item.id == itemId; });

//     menuItems.erase(it, menuItems.end());

//     std::ofstream file(filename);
//     if (file.is_open()) {
//         for (const auto& item : menuItems) {
//             file << item.id << '-' << item.name << '-' << item.price << '\n';
//         }
//         file.close();
//         std::cout << "Item deleted successfully.\n";
//     } else {
//         std::cerr << "Unable to open file: " << filename << std::endl;
//     }
// }

// int main() {
//     const std::string filename = "MainCourseFile.txt";

//     // Example: Adding a new item to the file
//     MenuItem newItem;
//     newItem.id = "m08";
//     newItem.name = "Veg Momos";
//     newItem.price = 120.0;
//     addItemToFile(filename, newItem);

//     // Example: Deleting an item from the file
//     std::string itemIdToDelete = "m05";
//     deleteItemFromFile(filename, itemIdToDelete);

//     return 0;
// }


#include <iostream>
#include <iomanip>
#include <ctime>

int main() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    // Format the current time as a string
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", now);
    string formattedDateTime(buffer);

    // Output the formatted date and time string
    cout << "Current Date and Time: " << formattedDateTime << endl;

    return 0;
}

