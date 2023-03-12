#include <iostream>
#include <string>
#include<fstream>
using namespace std;
// define constants: 8 items in the menu and tax rate: 5%
const int NO_OF_ITEMS = 8;
const double TAX_RATE = 5;

struct menuItemType
{
    string menuItem;
    double menuPrice;
};

void getData(ifstream& inFile, menuItemType menu[], int size);
void testReading(menuItemType menu[], int size);
void showMenu(menuItemType menu[], int size);
void makechoice(int orders[]);
void printCheck(menuItemType menu[], int orders[], int size);

int main()
{
    menuItemType menu[NO_OF_ITEMS];
    ifstream inFile;
    int orders[NO_OF_ITEMS] = {};

    inFile.open("menu.txt");
    cout << fixed << showpoint << setprecision(2);
    if(!inFile){
        cout << "The input file doesn't exist. Program terminates!" << endl;
        return 1;
    }

    getData(inFile, menu, NO_OF_ITEMS);
    // testReading(menu, NO_OF_ITEMS);
    showMenu(menu, NO_OF_ITEMS);
    makechoice(orders);
    printCheck(menu, orders, NO_OF_ITEMS);
    return 0;
}

// read data line by line and store info in menu
void getData(ifstream& inFile, menuItemType menu[], int size)
{
    char ch;
    for(int i = 0; i < size; i++){
        getline(inFile, menu[i].menuItem); // get multiple words as string
        // cout << "getting " << i << menu[i].menuItem << endl;
        inFile >> menu[i].menuPrice; // get int menu price
        inFile.get(ch); // or inFile.get();
    }
}

// print out memu info to test whether we read data right
void testReading(menuItemType menu[], int size)
{
    for(int i = 0; i < size; i++){
        cout << menu[i].menuItem << " with " << menu[i].menuPrice << endl;
    }
}

// After reading the data from file, show the menu to user
void showMenu(menuItemType menu[], int size)
{
    cout << "Welcome to Johnny's Restaurant" << endl;
    cout << "Today's menu: " << endl;
    for(int i = 0; i < size; i++){
        cout << i+1 << ": " << left << setw(15) << menu[i].menuItem << right << " $" << menu[i].menuPrice << endl;
    }
    cout << endl;
}

// user can enter number:1-8 to make one choice every time
// and order multiple items until the user enter other numbers
void makechoice(int orders[])
{
    int num;
    cout << "Enter item 1-8 to order, otherwise to checkout: ";
    cin >> num;
    while(num >= 1 && num <= 8){
        orders[num-1] += 1;
        cout << "Enter item 1-10 to order, otherwise to checkout: ";
        cin >> num;
    }
}

// After the user have done ordering, print the check for user to review
// print the ordered item and numbers, total price for the item
// calculate and print out net price, tax, total price
void printCheck(menuItemType menu[], int orders[], int size)
{
    double total = 0;
    cout << endl << "Welcome to Johnny's Restaurant" << endl;
    cout << "Here is your bill:" << endl;
    cout << left << setw(15) << "Item" << setw(16) << "Number" << "Price" << endl;
    for(int i = 0; i < size; i++){
        if(orders[i] != 0){
            double curPirce = menu[i].menuPrice * orders[i];
            total += curPirce;
            cout << left << setw(15) << menu[i].menuItem << setw(15) << orders[i] << right << " $" << curPirce << endl;
        }
    }
    cout << left << setw(15) << "Tax:" << setw(15) << "" << right << " $" << total*TAX_RATE/100 << endl;
    cout << left << setw(15) << "Amount Due:" << setw(15) << "" << right << " $" << total*(1+TAX_RATE/100) << endl;
}