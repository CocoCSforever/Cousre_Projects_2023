#include "bookType.h"
#include <iostream>
using namespace std;
const int number = 100;

void setUpDataBase(bookType books[], int numberOfBooks);
void showMenu();
void makechoice(bookType books[]);
void searchBookByTitle(bookType books[]);
int searchBookByISBN(bookType books[]);
void SetBookCopies(bookType books[]);
void printBookData(bookType books[], int size);

int main()
{
    // we have an array of 100 elements which all used the defalut constructor
    bookType books[number];
    // but we'll only show the first 5 elements to test the data-setup and make results clear
    // numberOfBook is just the number of books we want to set a value and test
    int numberOfBooks = 5;

    setUpDataBase(books, numberOfBooks);
    printBookData(books, numberOfBooks);
    showMenu();
    makechoice(books);
    cout << "Thanks for visiting." << endl;

    return 0;
}

// numberOfBooks is the number of books we want to set a different value
void setUpDataBase(bookType books[], int numberOfBooks)
{
    string authors[] = {"author1", "author2"};
    for(int i = 1; i <= numberOfBooks; i++){
        books[i] = bookType("title"+to_string(i), "publisher"+to_string(i),
                            "ISBN"+to_string(i), 2000+i, 10+i,
                            1+i, authors, 2);
    }
}

// show menu and instruct user to enter a choice
void showMenu()
{
    cout << "Welcome to the book management system!" << endl;
    cout << "1. Search a book by title" << endl;
    cout << "2. Search a book by ISBN" << endl;
    cout << "3. Reset the number of copies of a book" << endl;
    cout << endl << "Please enter 1-3 to choose, else to exit. " << endl;
}

// instruct user to choose one of the operations and call the corresponding function
void makechoice(bookType books[])
{
    int choice;
    cin >> choice;
    while(1 <= choice && choice <= 3)
    {
        switch(choice)
        {
        case 1: 
            searchBookByTitle(books);
            break;
        case 2:
            searchBookByISBN(books);
            break;
        case 3:
            SetBookCopies(books);
            break;
        default:
            return;
        }
        cout << endl << "Please enter 1-3 to choose, else to exit. " << endl;
        cin >> choice;
    }
    return;
}

// user enter the title and search through the books database
// print out info when we don't find a matched result
void searchBookByTitle(bookType books[])
{
    string t;
    cout << "Enter the title: ";
    cin >> t;
    int n = 0;
    cout << endl << "Here is the result of your search: " << endl;
    for(int i = 0; i < number; i++){
        // if many books have the same title, only print out the first 5 books in the database
        if(n == 5){
            return;
        }
        if(books[i].checkTitle(t)){
            books[i].showInfo();
            n++;
        }
    }
    if(n== 0){
        cout << "We don't have such a book with title: " << t << endl;
    }
}

// assume isbn is unique so whenver we find the book, just showInfo and return the index
// print out info when we don't find a matched result
// return -1 when we cannot find the book
int searchBookByISBN(bookType books[])
{
    string isbn;
    cout << "Enter the ISBN: ";
    cin >> isbn;
    cout << endl << "Here is the result of your search: " << endl;
    for(int i = 0; i < number; i++){
        if(books[i].checkISBN(isbn)){
            books[i].showInfo();
            return i;
        }
    }
    cout << "We don't have such a book with ISBN: " << isbn << endl;
    return -1;
}

// search book by title and isbn and set the copy of the book
void SetBookCopies(bookType books[])
{
    string title;
    int copies;
    // book can have same titles but different ISBN
    // first search by title and print out eligible books so we can see the ISBN and choose the book from them
    searchBookByTitle(books);
    int i = searchBookByISBN(books);
    
    // only reset copies when we can find the book by isbn
    if(i != -1){
        cout << "Enter the copies to reset: ";
        cin >> copies;
        books[i].setCopies(copies);
        cout << endl << "Already reset the copies of Book: " << books[i].getTitle() << " " << books[i].getISBN() << endl;
        cout << "After reseting: " << endl;
        books[i].showInfo();
    }
}

// print books info in the database, the size is not the size of database but the number of books we want to print out
void printBookData(bookType books[], int size)
{
    cout << "The information of the first " << size+1 << " books is as belows:" << endl;
    for(int i = 0; i <= size; i++){
        books[i].showInfo();
    }
}