#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <map>
using namespace std;

// int totalCost=0;

class Menu
{
protected:
    int itemId;
    string itemName;
    int itemPrice;
    vector<vector<string>> starterList;

    virtual void display()
    {
        cout << "Menu";
    };

public:
    Menu()
    {
    }
};

class Starters : public Menu
{
public:
    vector<vector<string>> getMenu()
    {
        ifstream file("starterFile.txt");

        string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>())); // Read the entire file

        file.close(); // Close the file

        string singleItemDetail; // For storing itemName and price of single item in a string

        for (int i = 0; i < content.size(); i++)
        {
            if (content[i] == '\n')
            {
                singleItemDetail += '-';

                vector<string> starter; // For storing single starter item

                string word;

                for (int i = 0; i < singleItemDetail.size(); i++)
                {
                    if (singleItemDetail[i] == '-')
                    {
                        starter.push_back(word);
                        word = "";
                        continue;
                    }
                    word += singleItemDetail[i];
                }
                starterList.push_back(starter);
                // cout<<singleItemDetail<<endl;
                singleItemDetail = "";
                // break;
                continue;
            }
            singleItemDetail += content[i];
        }
        return starterList;
    }

    void display()
    {
        vector<vector<string>> starterList2 = getMenu();
        cout << "DISPLAYING MENU" << endl;

        cout << endl;

        for (int i = 0; i < starterList2.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << starterList2[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
    }
};

class Order : public Starters
{
public:
    string orderInput;
    vector <string> orderList; 
    int totalCost;

    Order()
    {
    }

    vector<string> orderItem()
    {
        cout<<"Enter the item Id of items you wish to order: ";
        cin >> orderInput;

        for(int i=3; i<orderInput.size()-1; i+=4){
            if(orderInput[i]!=','){
                cout<<"Invalid Food Order Input"<<endl;
                break;
            }
        }
        string singleId;
        for(int i=0; i<orderInput.size(); i++){
            if(orderInput[i]==','){
                orderList.push_back(singleId);
                singleId="";
            }else{
                singleId+=orderInput[i];
                if(i==orderInput.size()-1){
                    orderList.push_back(singleId);
                }

            }

        }
        for(auto i: orderList){
            cout<<i<<endl;
        }
        return orderList;
    }

    void calculateCost(){

        vector<string> orderL = orderItem();
        vector<vector<string>> start = getMenu();
        for(int i=0; i<orderL.size(); i++){
            for(int j=0; j<start.size(); j++){
                if(start[j][0]==orderL[i]){
                    int singleCost = stoi(start[j][2]);
                    totalCost+=singleCost;
                    break;
                }
            }
        }

        cout<<totalCost<<endl;
    }
};

int main()
{

    char choice;
    while (true)
    {

        cout << "Press S to see Starters Menu." << endl;
        cout << "Press M to see Main Course Menu." << endl;
        cout << "Press D to see Dessert Menu." << endl;
        cout << "Press O to order Food." << endl;
        cout << " Press X to return to previous Menu." << endl;

        cin >> choice;

        if (choice == 'S')
        {
            Starters st;
            st.display();
        }
        else if (choice == 'M')
        {
            Starters st;
            st.display();
        }
        else if (choice == 'D')
        {
            Starters st;
            st.display();
        }
        else if (choice == 'O')
        {
            Order o;
            // o.orderItem();
            o.calculateCost();
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
    // Starters st;
    // st.display();

    return 0;
}
