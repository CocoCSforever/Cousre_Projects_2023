#include "DVD.h"
#include <iostream>
#include <fstream>

DVD::DVD()
{
    name = "Default Name";
    stars[0] = "Default Star";
    producer = "Default Producer";
    director = "Default Director";
    proCompany = "Default Production Company";
    copies = 10;
    numOfStars = 1;
}

DVD::DVD(string name, string stars[], string producer, string director, string proCompany, int copies, int numOfStars)
{
    setInfo(name, stars, producer, director, proCompany, copies, numOfStars);
}

DVD::~DVD()
{


}

void DVD::setInfo(string name, string stars[], string producer, string director, string proCompany, int copies, int numOfStars)
{
    this->name = name;
    setStars(stars, numOfStars);
    this->producer = producer;
    this->director = director;
    this->proCompany = proCompany;
    this->copies = copies;
}

void DVD::setName(string name)
{
    this->name = name;
}

// should not call it with numOfStars< 0 || >4
void DVD::setStars(string stars[], int numOfStars)
{   
    setNumOfStars(numOfStars);
    for(int i = 0; i < this->numOfStars; i++){
        this->stars[i] = stars[i];
    }
}

void DVD::setProducer(string producer)
{
    this->producer = producer;
}

void DVD::setDirector(string director)
{
    this->director = director;
}

void DVD::setProCompany(string proCompany)
{
    this->proCompany = proCompany;
}

void DVD::setCopies(int copies)
{
    if(copies > 0){
        this->copies = copies;
    }else{
        this->copies = 0;
    }
    
}

// we have a maximum number of 4 and minimum number of 0
void DVD::setNumOfStars(int numOfStars)
{
    if(numOfStars > 4){
        this->numOfStars = 4;
    }else if(numOfStars < 0){
        this->numOfStars = 0;
    }else{
        this->numOfStars = numOfStars;
    }
}

void DVD::showInfo() const
{
    cout << "-------------------" << endl;
    showName();
    showStars();
    showProducer();
    showDirector();
    showProCompany();
    showCopies();
    cout << "-------------------" << endl;
}

void DVD::showName() const
{
    cout << "Title: " << name << endl;
}

void DVD::showStars() const
{
    cout << this->numOfStars << " Star(s): " << endl;
    for(int i = 0; i < numOfStars; i ++){
        cout << stars[i] << endl;
    }
}

void DVD::showProducer() const
{
    cout << "Producer: " << producer << endl;
}

void DVD::showDirector() const
{
    cout << "Director: " << director << endl;
}

void DVD::showProCompany() const
{
    cout << "ProCompany: " << proCompany << endl;
}

void DVD::showCopies() const
{
    cout << "Copies: " << copies << endl;
}

void DVD::showNumOfStars() const
{
    cout << "NumOfStars: " << numOfStars << endl;
}

// check out if available, else print out error info
void DVD::checkOut()
{
    if(checkAvailability()){
        changeCopies(-1);
        cout << "Checked out DVD with title: " << name << endl;
    }else{
        cout << name << " is out of stock. Cannot be checked out." << endl;
    }
}

// can only be called when store has this DVD to check-in
void DVD::checkIn()
{
    changeCopies(1);
    cout << "Checked in DVD with title: " << name << endl;
}

bool DVD::checkAvailability() const
{
    return copies > 0;
}

string DVD::getName() const
{
    return name;
}

string DVD::getProducer() const
{
    return producer;
}

string DVD::getDirector() const
{
    return director;
}

string DVD::getProCompany() const
{
    return proCompany;
}

int DVD::getCopies() const
{
    return copies;
}

int DVD::getNumOfStars() const
{
    return numOfStars;
}

// we consider two DVDs are the same if they have the same name
bool DVD::operator==(const DVD& otherDVD) const
{
    return name == otherDVD.getName();
}

bool DVD::operator!=(const DVD& otherDVD) const
{
    return !(*this == otherDVD);
}

void DVD::changeCopies(int i)
{
    
    if(copies+i < 0){
        cout << "Copies cannot be below 0. Change failed." << endl;
    }else{
        copies += i;
    }
}

// cout << DVDobj
ostream& operator<<(ostream& os, const DVD& DVDobj)
{
    os << "Name: " << DVDobj.name << "-" << endl;
    os << DVDobj.numOfStars << " Stars: " << endl;
    for(int i = 0; i < DVDobj.numOfStars; i++){
        os << DVDobj.stars[i] << endl;
    }
    os << "Producer: " << DVDobj.producer << endl;
    os << "Director: " << DVDobj.director << endl;
    os << "ProCompany: " << DVDobj.proCompany << endl;
    os << "Copies: " << DVDobj.copies << endl;
    return os;
}

// write info of a DVD object to output file
ofstream& operator<<(ofstream& outFile, const DVD& DVDobj)
{
    outFile << DVDobj.name << endl;
    outFile << DVDobj.numOfStars << endl;
    for(int i = 0; i < DVDobj.numOfStars; i++){
        outFile << DVDobj.stars[i] << endl;
    }
    outFile << DVDobj.producer << endl;
    outFile << DVDobj.director << endl;
    outFile << DVDobj.proCompany << endl;
    outFile << DVDobj.copies << endl;
    return outFile;
}

// read data from file to an DVD object
ifstream& operator>>(ifstream& inFile, DVD& DVDobj)
{
    string line, title, producer, director, proCompany;
    int n, copies;

    getline(inFile, line);
    getline(inFile, DVDobj.name);
    inFile >> DVDobj.numOfStars;
    getline(inFile, line);
    for(int i = 0; i < DVDobj.numOfStars; i++){
        getline(inFile, DVDobj.stars[i]);
    }
    getline(inFile, DVDobj.producer);
    getline(inFile, DVDobj.director);
    getline(inFile, DVDobj.proCompany);
    inFile >> DVDobj.copies;
    getline(inFile, line);
    return inFile;
}