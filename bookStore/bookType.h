#ifndef BOOKTYPE_H
#define BOOKTYPE_H
#include <string>
using namespace std;

#pragma once

class bookType
{
public:
    bookType();
    bookType(string, string,
             string, int, double,
             int, string [], int);
    ~bookType();

    void setInfo(string, string,
             string, int, double,
             int, string [], int);
    void setTitle(string);
    void setAuthors(string [], int);
    void setPublisher(string);
    void setISBN(string);
    void setPrice(double);
    void setCopies(int);
    void addCopies(int);
    
    void showInfo() const;
    void showTitle() const;
    void showAuthors() const;
    void showPublisher() const;
    void showISBN() const;
    void showPrice() const;
    void showCopies() const;


    string getTitle() const;
    string getPublisher() const;
    string getISBN() const;
    double getPrice() const;
    int getCopies() const;

    bool checkTitle(string) const;
    bool checkPublisher(string) const;
    bool checkISBN(string) const;
    bool checkPrice(double) const;
    bool checkStock() const;
    bool hasAuthor(string) const;
    bool checkAuthors(string[]) const;

private:
    string title;
    string publisher;
    string ISBN;
    
    int publicationYear;
    double price;
    int copies;
    string authors[4];
    int numOfAuthor;
};

#endif