// #include <ctime>
// #include <iostream>
// // #include <chrono>
// using namespace std;

// class Restaurant{
//     public:
//     Restaurant(){
//         cout<<"Inside restaurant";
//     }
// };

// int main() {
//     // Restaurant r;

//     time_t now = time(0);
   
//    // convert now to string form
//    char* dt = ctime(&now);

//    cout << "The local date and time is: " << dt << endl;

//     cout<<endl<<"hello qoels"<<endl;

//     // Get the current time
//     auto now1 = std::chrono::system_clock::now();
//     std::time_t current_time = std::chrono::system_clock::to_time_t(now1);

//     // Convert the current time to a tm struct for local time
//     std::tm local_time = *std::localtime(&current_time);

//     // Extract the current hour from the tm struct
//     int current_hour = local_time.tm_hour;

//     // Output the current hour
//     std::cout << "Current hour: " << current_hour << std::endl;
//     return 0;
// }

 User()
    {
        bool enter = validateEntry();
        char choice;
        while (true)
        {

            cout << "Press A to see Menu" << endl;
            // cout << "Press B to order Food" << endl;
            cout << "Press X to exit" << endl;

            cin >> choice;

            if (choice == 'A')
            {
                // Menu m;
                while (true)
                {

                    cout << "Press S to see Starters Menu." << endl;
                    cout << "Press M to see Main Course Menu." << endl;
                    cout << "Press D to see Dessert Menu." << endl;
                    cout << " Press X to return to previous Menu." << endl;

                    cin >> choice;

                    if (choice == 'S')
                    {
                        Starters st;
                        st.display();
                    }
                    else if (choice == 'M')
                    {
                        MainCourse main;
                        main.display();
                    }
                    else if (choice == 'D')
                    {
                        Dessert sweet;
                        sweet.display();
                    }
                    else if (choice == 'X')
                    {
                        break;
                    }
                    else
                    {
                        cout << " Invalid Response " << endl;
                    }
                }
            }
            else if (choice == 'X')
            {
                return;
            }
            else if (choice == 'B')
            {
                Order o;
                // o.orderItem();
                o.calculateCost();
            }
            else
            {
                cout << " Invalid Response" << endl;
            }
        }
    }