#include "bookType.h"
#include <iostream>

bookType::bookType()
{
    title = "Autobiography";
    publisher = "ChinaGold";
    ISBN = "1000000";
    authors[0] = "Yijia Ma";
    publicationYear = 1998;
    price = 10;
    copies = 1;
    numOfAuthor = 1;
}

bookType::bookType(string title, string publisher,
             string ISBN, int py, double price,
             int copies, string authors[], int numOfAuthor)
{
    setInfo(title, publisher, ISBN, py, price,
            copies, authors, numOfAuthor);
}

bookType::~bookType()
{

}

void bookType::setInfo(string title, string publisher,
                       string ISBN, int py, double price,
                       int copies, string authors[], int numOfAuthor){
    this->title = title;
    this->publisher = publisher;
    this->ISBN = ISBN;
    this->numOfAuthor = numOfAuthor;
    for(int i =0; i < numOfAuthor; i++){
        this->authors[i] = authors[i];
    }
    this->publicationYear = py;
    this->price = price;
    this->copies = copies;
}

// set the title of the book
void bookType::setTitle(string title)
{
    this->title = title;
}

// set the author of the book
void bookType::setAuthors(string authors[], int num)
{
    numOfAuthor = num;
    for(int i =0; i < 4; i++){
        this->authors[i] = authors[i];
    }
}

// set the publisher of the book
void bookType::setPublisher(string publisher)
{
    this->publisher = publisher;
}

// set the ISBN of the book
void bookType::setISBN(string ISBN)
{
    this->ISBN = ISBN;
}

// set the price of the book
void bookType::setPrice(double price)
{
    this->price = price;
}

// set the copies of the book
void bookType::setCopies(int copies)
{
    this->copies = copies;
}

// add copies to the book's stock
void bookType::addCopies(int copies)
{
    this->copies += copies;
}

// print out all the info about the book
void bookType::showInfo() const
{
    cout << "-------------------" << endl;
    showTitle();
    showAuthors();
    showPublisher();
    showISBN();
    showPrice();
    showCopies();
    cout << "-------------------" << endl;
}

// print out the title of the book
void bookType::showTitle() const
{
    cout << "Title: " << title << endl;
}

// print out the author of the book
void bookType::showAuthors() const
{
    cout << "Author(s): ";
    for(int i = 0; i < numOfAuthor; i ++){
        cout << authors[i] << " ";
    }
    cout << endl;
}

// print out the publisher of the book
void bookType::showPublisher() const
{
    cout << "Publisher: " << publisher << endl;
}

// print out the ISBN of the book
void bookType::showISBN() const
{
    cout << "ISBN: " << ISBN << endl;
}

// print out the price of the book
void bookType::showPrice() const
{
    cout << "Price: " << price << endl;
}

// print out the copies of the book
void bookType::showCopies() const
{
    cout << "Copies in stock: " << copies << endl;
}

// get the title of the book
string bookType::getTitle() const
{
    return title;
}

// get the publisher of the book
string bookType::getPublisher() const
{
    return publisher;
}

// get the ISBN of the book
string bookType::getISBN() const
{
    return ISBN;
}

// get the price of the book
double bookType::getPrice() const
{
    return price;
}

// get the copies of the book
int bookType::getCopies() const
{
    return copies;
}

// check whether the book has title t
bool bookType::checkTitle(string t) const
{
    return title == t;
}

// check whether the book has the same publisher
bool bookType::checkPublisher(string publisher) const
{
    return this->publisher == publisher;
}

// check whether the book has the same ISBN
bool bookType::checkISBN(string isbn) const
{
    return ISBN == isbn;
}

// check whether the book has price p
bool bookType::checkPrice(double p) const
{
    return price == p;
}

// check whether the book is in stock
bool bookType::checkStock() const
{
    return copies > 0;
}

// check whether the book has author a
bool bookType::hasAuthor(string a) const
{
    for(int i = 0; i < numOfAuthor; i++){
        if(authors[i] == a){
            return true;
        }
    }
    return false;
}
