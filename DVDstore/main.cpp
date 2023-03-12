#include "DVDstore.h"
#include <iostream>
#include <fstream>
using namespace std;

void readFromFile(ifstream& inFile, DVDstore& store);
void writeToFile(ofstream& outFile, DVDstore& store);

void showMenu();
void makeChoice(DVDstore& store);


int main()
{
    DVDstore store;
    ifstream inFile;
    ofstream outFile;

    inFile.open("DVDstore.txt");
    if(!inFile){
         cout << "The input file doesn't exist. Program terminates!" << endl;
        return 1;
    }
    outFile.open("DVDresult.txt");

    readFromFile(inFile, store);
    
    showMenu();
    makeChoice(store);

    writeToFile(outFile, store);
    cout << "Thanks for visiting DVD store." << endl;

    return 0;
}

void readFromFile(ifstream& inFile, DVDstore& store)
{
    store.readFromFile(inFile);
}

void writeToFile(ofstream& outFile, DVDstore& store)
{
    store.writeToFile(outFile);
}

void showMenu()
{
    cout << "Welcome to the DVD store. Here are the menu options: " << endl;
    cout << "1. Check if a DVD exists in the store" << endl;
    cout << "2. Check-out a DVD " << endl;
    cout << "3. Check in a DVD" << endl;
    cout << "4. Check whether a particular DVD is available for borrowing " << endl;
    cout << "5. List all the titles of the DVDs in the store" << endl;
    cout << "6. Print all details of the DVDs in the store" << endl;
    cout << "7. Update details of a particular DVD" << endl;
    cout << "8. Add a new DVD to the list of DVDs" << endl;
    cout << "9. Remove a DVD from the list of DVDs" << endl;
    cout << "10. Search for a DVD, given the title of the DVD and print details" << endl;
    cout << "11. Exit" << endl;
    
    cout << "Enter number 1-10 to choose the menu options, enter any other numers to exit: ";
}

void makeChoice(DVDstore& store)
{
    int command;
    string title;
    cin >> command;
    while(1 <= command && command <= 10){
        switch(command)
        {
        case 5:
            store.listDVDsTitle();
            break;
        case 6:
            store.listDVDsInfo();
            break;
        case 8:
            store.addDVD();
            break;
        default:
            cout << "Please enter the title of the DVD you want to operate on: ";
            getline(cin, title);
            getline(cin, title);
            switch(command){
                case 1:
                    store.checkDVDAvai(title);
                    break;
                case 2:
                    store.checkOutDVD(title);
                    break;
                case 3:
                    store.checkInDVD(title);
                    break;
                case 4:
                    store.checkDVDAvai(title);
                    break;
                case 7:
                    store.updateDVD(title);
                    break;
                case 9:
                    store.removeDVD(title);
                    break;
                case 10:
                    store.searchDVDPrint(title);
                    break;
            }
        }
        cout << "Enter number 1-10 to choose the menu options, enter any other numers to exit: ";
        cin >> command;
    }
}