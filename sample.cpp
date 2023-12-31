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

// #include <iostream>
// // #include <iomanip>
// #include <ctime>
#include <fstream>
// #include<vector>
#include <string>
// using namespace std;
// int main() {
//     time_t t = time(nullptr);
//     tm* now = localtime(&t);

//     // Format the current time as a string
//     char buffer[20];
//     strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", now);
//     string formattedDateTime(buffer);

//     // Output the formatted date and time string
//     cout << "Current Date and Time: " << formattedDateTime << endl;

//     ifstream file("TotalReceiptFile.txt");
//     // string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
//     // cout<<content;

//     vector<vector<string>> str;
//     vector<string> s;
//     int cnt=0;
//     string word;

//     while (std::getline(file, word)) {
//         s.push_back(word);
//     }

//     for(auto i: s){
//         cout<<i<<endl;
//     }
//     return 0;
// }

#include <iostream>
// #include <ncurses.h>
// int main() {
//     initscr(); // initialize the library
//     noecho(); // don't echo input characters
//     // curs_set(0); // hide the cursor

//     printw("Enter your password: ");

//     std::string password;
//     char ch;

//     while (true) {
//         ch = getch();

//         if (ch == 10 || ch == 13) { // Enter key
//             break;
//         } else if (ch == 127 || ch == 8) { // Backspace or Delete key
//             if (!password.empty()) {
//                 printw("\b \b"); // Move cursor back, erase, move cursor back
//                 password.pop_back();
//             }
//         } else {
//             password.push_back(ch);
//             printw("*");
//         }

//         refresh(); // refresh the screen
//     }
//     std::cout << "Password entered: " << password << std::endl;
//     getch();
//     endwin(); // clean up and close the library
#include<ncurses.h>
using namespace std;
// string username;
// string password;
// std::ifstream file("AdminCredential.txt");
// string content;
// int strCount = 0;
// while(!file.eof()){
//     getline(file,content);
//     strCount++;
//     cout<<content<<endl;
//     if(strCount==1){
//         username=content;
//     }else{
//         password=content;
//         break;
//     }
// }

// cout<<"hello";

// std::cout << std::endl;
// cout<<username<<endl;

// return 0;
// }
bool isLoggedIn = false;

void logout()
    {
        if (isLoggedIn)
        {
            system("clear");
            cout << "Logout successful.\n";
            isLoggedIn = false;
        }
        else
        {
            system("clear");
            cout << "No user is currently logged in.\n";
        }
    }

    bool authenticate(const string &username, const string &password)
    {
        const string correctUsername = "simant";
        const string correctPassword = "sim123@";

        return (username == correctUsername && password == correctPassword);
    }

    string getHiddenInput()
    {
        string input;
        char ch;
        while ((ch = _getch()) != 13)
        { // 13 is the ASCII code for Enter
            if (ch == 8)
            { // 8 is the ASCII code for Backspace
                if (!input.empty())
                {
                    cout << "\b \b"; // Move the cursor back, print a space, move back again
                    input.pop_back();
                }
            }
            else
            {
                cout << '*'; // Print asterisk instead of the actual character
                input.push_back(ch);
            }
        }
        cout << endl; // Move to the next line after input
        return input;
    }

int main()
{
// #ifdef _WIN32
    // Function to get hidden input on Windows
    
// #endif
    
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
// #ifdef _WIN32
    password = getHiddenInput();
// #else
    cin >> password;
// #endif

    if (authenticate(username, password))
    {
        system("clear");
        cout << "Login successful.\n";
        isLoggedIn = true;
    }
    else
    {
        system("clear");
        cout << "Login failed. Invalid credentials.\n";
    }
}
