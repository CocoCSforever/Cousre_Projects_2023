#include "DVDstore.h"
#include <iostream>
#include <fstream>
DVDstore::DVDstore()
{
    size = 0;
}

DVDstore::DVDstore(int size)
{
    if(size <= 0){ return; }
    // insert default DVD
    DVD d;
    m.insert(pair<string, DVD>(d.getName(), d));

    // insert 5 more DVD with diff info
    for(int i = 1; i < size; i++){
        string stars[1] = {"Star"+to_string(i)};
        DVD d("Name"+to_string(i), stars, "Producer"+to_string(i), "Director"+to_string(i), "ProComapny"+to_string(i), i, 1);
        m.insert(pair<string, DVD>(d.getName(), d));
    }
    size = 6;
}


DVDstore::~DVDstore()
{

}


bool DVDstore::checkHasDVD(string title) const
{
    return m.find(title) != m.end();
}

void DVDstore::checkDVDAvai(string title)
{
    it = m.find(title);
    if(it != m.end()){
        if(it->second.checkAvailability()){
            cout << "Store has DVD with title: " << title << ": " << it->second.getCopies() << " copies." << endl;
        }else{
            cout << "DVD with title: " << title << " is out of stock. Not available for borrowing. " << endl;
        }
    }else{
        cout << "We don't have DVD with title: " << title << endl;
    }
}

void DVDstore::checkOutDVD(string title)
{
    if(checkHasDVD(title)){
        m.at(title).checkOut();
        cout << "Currrent Info: " << endl;
        m.at(title).showInfo();
    }else{
        cout << "We don't have DVD with title: " << title << ". Cannot Check out." << endl;
    }
}

void DVDstore::checkInDVD(string title)
{
    if(checkHasDVD(title)){
        m.at(title).checkIn();
        cout << "Currrent Info: " << endl;
        m.at(title).showInfo();
    }else{
        cout << "We don't have DVD with title: " << title << endl
             << "Please add it to the store first." << endl;
    }
}

void DVDstore::addDVD()
{
    int num;
    cout << "Please enter the number of new DVD(s) you want to add: ";
    cin >> num;
    for(int i = 0; i < num; i++){
        string title, producer, director, proCompany;
        int n, copies;
        cout << "Please enter the title: ";
        getline(cin, title);
        getline(cin, title);
        cout << "Please enter the number of stars: ";
        cin >> n;
        cin.get();
        string stars[4];
        for(int i = 0; i < n; i++){
            cout << "Please enter star " << i+1 << ": ";
            getline(cin, stars[i]);
        }
        cout << "Please enter the producer: ";
        getline(cin, producer);
        cout << "Please enter the director: ";
        getline(cin, director);
        cout << "Please enter the proCompany: ";
        getline(cin, proCompany);
        cout << "Please enter the Copies: ";
        cin >> copies;
        DVD d(title, stars, producer, director, proCompany, copies, n);
        m.insert(pair<string, DVD>(d.getName(), d));
        size++;
        d.showInfo();
    }
}

void DVDstore::addDVD(DVD ob)
{
    m.insert(pair<string, DVD>(ob.getName(), ob));
    size++;
}

void DVDstore::removeDVD(string title)
{
    if(m.erase(title) > 0){
        cout << "Removed Successfully. " << title << endl;
        size--;
    }else{
        cout << "We don't have DVD with title: " << title << ". Cannot Remove." << endl;
    }
}

void DVDstore::updateDVD(string title)
{
    if(checkHasDVD(title)){
        cout << "You are going to update the info of the DVD below: " << endl;
        DVD cur = m.find(title)->second;
        cur.showInfo();
        
        int command;
        showUpdateMenu();
        cin >> command;
        
        string ans;
        int n;
        string stars[4];
        while(0 <= command && command <= 6){
            switch (command)
            {
            case 0:
                cout << "Since you are trying to override all the information of the DVD." << endl
                     << "We've removed the related info. Please add DVD as a new one." << endl;
                removeDVD(title);
                addDVD();
                return;
            case 1:
                cout << "Please enter the title: ";
                getline(cin, ans);
                getline(cin, ans);
                cur.setName(ans);
                break;
            case 2:
                cout << "Please enter the number of stars: ";
                cin >> n;
                cin.get();
                cur.setNumOfStars(n);
                for(int i = 0; i < cur.getNumOfStars(); i++){
                    cout << "Please enter star " << i+1 << ": ";
                    getline(cin, stars[i]);
                }
                cur.setStars(stars, cur.getNumOfStars());
                break;
            case 3:
                cout << "Please enter the producer: ";
                getline(cin, ans);
                getline(cin, ans);
                cur.setProducer(ans);
                break;
            case 4:
                cout << "Please enter the director: ";
                getline(cin, ans);
                getline(cin, ans);
                cur.setDirector(ans);
                break;
            case 5:
                cout << "Please enter the production company: ";
                getline(cin, ans);
                getline(cin, ans);
                cur.setProCompany(ans);
                break;
            case 6:
                cout << "Please enter the copies: ";
                cin >> n;
                cur.setCopies(n);
                break;
            }
            showUpdateMenu();
            cin >> command;
        }
        m.erase(title);
        m.insert(pair<string, DVD>(cur.getName(), cur));
        cout << "After Updating: " << endl;
        cur.showInfo();
    }else{
        cout << "We don't have DVD with title: " << title << endl;
    }
}

void DVDstore::showUpdateMenu() const
{
    cout << "0. Change all the info." << endl;
    cout << "1. Change title" << endl;
    cout << "2. Change stars" << endl;
    cout << "3. Change producer" << endl;
    cout << "4. Change director" << endl;
    cout << "5. Change proCompany" << endl;
    cout << "6. Change copies" << endl;
    cout << "Please enter a number 0-6 to choose from these options, other numbers stop to change." << endl;
}

void DVDstore::searchDVDPrint(string title)
{
    it = m.find(title); 
    if(it != m.end()){
        it->second.showInfo();
        return;
    }
    cout << "We don't have DVD with title: " << title << endl;
}

void DVDstore::listDVDsTitle()
{
    for(it = m.begin(); it != m.end(); it++){
        it->second.showName();
    }
}

void DVDstore::listDVDsInfo()
{
    for(it = m.begin(); it != m.end(); it++){
        it->second.showInfo();
    }
}

int DVDstore::getSize() const
{
    return size;
}

void DVDstore::readFromFile(ifstream& inFile)
{
    int num;
    string line;
    inFile >> num;
    getline(inFile, line);

    for(int i = 0; i < num; i++){
        DVD cur;
        inFile >> cur;
        addDVD(cur);
    }
}

void DVDstore::writeToFile(ofstream& outFile)
{
    outFile << size << endl << endl;
    for(it = m.begin(); it != m.end(); it++){
        outFile << it->second;
        outFile << endl;
    }
}