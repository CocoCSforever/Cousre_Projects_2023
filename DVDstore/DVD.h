#ifndef DVD_H
#define DVD_H
#include <string>
using namespace std;

#pragma once

class DVD
{
    friend ostream& operator<<(ostream&, const DVD&);
    friend ofstream& operator<<(ofstream& outFile, const DVD& DVDobj);
    friend ifstream& operator>>(ifstream&, DVD&);
public:
    DVD();
    DVD(string, string[], string, string, string, int, int);
    ~DVD();

    void setInfo(string, string[], string, string, string, int, int);
    void setName(string);
    void setStars(string[], int);
    void setProducer(string);
    void setDirector(string);
    void setProCompany(string);
    void setNumOfStars(int);
    void setCopies(int);
    
    void showInfo() const;
    void showName() const;
    void showStars() const;
    void showProducer() const;
    void showDirector() const;
    void showProCompany() const;
    void showCopies() const;
    void showNumOfStars() const;

    void checkOut();
    void checkIn();
    bool checkAvailability() const;

    string getName() const;
    string getProducer() const;
    string getDirector() const;
    string getProCompany() const;
    int getCopies() const;
    int getNumOfStars() const;

    bool operator==(const DVD& otherDVD) const; 
    bool operator!=(const DVD& otherDVD) const; 

private:
    void changeCopies(int);
    
    string name;
    // max number of stars is 4
    string stars[4];
    string producer;
    string director;
    string proCompany;
    int copies;
    int numOfStars;
};

#endif