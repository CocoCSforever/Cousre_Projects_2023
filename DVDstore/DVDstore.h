#ifndef DVDSTORE_H
#define DVDSTORE_H
#include "DVD.h"
#include <map>

#pragma once

class DVDstore
{
public:
    DVDstore();
    DVDstore(int);
    ~DVDstore();

    bool checkHasDVD(string) const;
    void checkDVDAvai(string);

    void checkOutDVD(string);
    void checkInDVD(string);

    void addDVD();
    void addDVD(DVD);
    void removeDVD(string);

    void updateDVD(string);
    void showUpdateMenu() const;
    void searchDVDPrint(string);

    void listDVDsTitle();
    void listDVDsInfo();
    void writeToFile(ofstream&);
    void readFromFile(ifstream&);

    int getSize() const;

private:
    map<string, DVD> m;
    map<string, DVD>::iterator it;
    int size;
};

#endif