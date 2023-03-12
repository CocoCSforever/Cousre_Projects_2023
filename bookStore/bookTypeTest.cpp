#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include "bookType.h"
using namespace std;

void testStack();
void testQueue();
void testVector();

int main()
{
    int choice;
    // print out the menu and instruct user to choose
    cout << "1. Use stack to test bookType" << endl;
    cout << "2. Use queue to test bookType" << endl;
    cout << "3. Use vector to test bookType" << endl;
    cout << "Please enter 1-3 to choose, else to exit:" << endl;
    cin >> choice;
    // users can test as many times as they like and enter other key to exit
    while(1 <= choice && choice <= 3){
        switch(choice)
        {
        case 1:
            testStack();
            break;
        case 2:
            testQueue();
            break;
        case 3:
            testVector();
            break;
        default:
            break;
        }

        cout << "Please enter 1-3 to choose, else to exit:" << endl;
        cin >> choice;
    }
    cout << "---End---" << endl;
    return 0;
}


// use STL stack to store 5 objects and print them out backwards
// For Stack, Please test PU: PUSH, POP, TOP, SIZE AND EMPTY
void testStack(){
    cout << endl << "----------Now we are testing stack functions--------------" << endl;
    stack<bookType> stack;
    string authors[] = {"author1", "author2"};

    // push 5 books to stack to set up the data, if we print out these books successfully later, it means push() works well
    for(int i = 0; i < 5; i++){
        stack.push(bookType("title"+to_string(i), "publisher"+to_string(i),
                            "ISBN"+to_string(i), 2000+i, 10+i,
                            1+i, authors, 2));
    }
    cout << endl << "1. Testing size(): " << endl;
    cout << "The size of stack should be 5: " << stack.size() << endl;

    cout << endl << "2. Testing top(): " << endl;
    cout << "The top one should be title4, publisher4, ISBN4: " << endl;
    stack.top().showInfo();

    // print out every books stores in the stack backwards until the stack is empty
    cout << endl << "3. Testing push(), pop(), empty(). 5 books will be printed out backwards: " << endl;
    while(!stack.empty()){
        stack.top().showInfo();
        stack.pop();
    }
    cout << endl;
}

// For Queue, Please test: PUSH, POP, SIZE, FRONT and BACK
void testQueue()
{
    cout << endl << "----------Now we are testing queue functions--------------" << endl;
    
    queue<bookType> q;
    string authors[] = {"author1", "author2"};

    // push 5 books to queue to set up the data, if we print out these books successfully, it means push() works well
    for(int i = 0; i < 5; i++){
        q.push(bookType("title"+to_string(i), "publisher"+to_string(i),
                            "ISBN"+to_string(i), 2000+i, 10+i,
                            1+i, authors, 2));
    }
    cout << endl << "1. Testing size(): " << endl;
    cout << "The size of queue should be 5: " << q.size() << endl;

    cout << endl << "2. Testing front(): " << endl;
    cout << "The front one should be title0, publisher0, ISBN0: " << endl;
    q.front().showInfo();

    cout << endl << "3. Testing back(): " << endl;
    cout << "The back one should be title4, publisher4, ISBN4: " << endl;
    q.back().showInfo();

    // print out every books stores in the queue forwards until the queue is empty
    cout << endl << "4. Testing push(), pop(). 5 books will be printed out forwards: " << endl;
    while(!q.empty()){
        q.front().showInfo();
        q.pop(); // remove the frist element
    }
    cout << endl;
}

// For Vector: Please test: PUSH_BACK, POP_BACK, INSERT, SIZE , EMPTY
void testVector()
{
    cout << endl << "----------Now we are testing vector functions--------------" << endl;

    vector<bookType> v;
    vector<bookType>::iterator it;

    string authors[] = {"author1", "author2"};

    // push 5 books to vector to set up the data, if we print out these books successfully, it means push() works well
    for(int i = 0; i < 5; i++){
        v.push_back(bookType("title"+to_string(i), "publisher"+to_string(i),
                            "ISBN"+to_string(i), 2000+i, 10+i,
                            1+i, authors, 2));
    }

    // insert a book to the beginning of the vector and check if the front element will change
    cout << endl << "1. Testing size(): " << endl;
    cout << "The size of vector should be 5: " << v.size() << endl;

    cout << endl << "2. Testing insert(): " << endl;
    cout << "Before inserting to the beginning, the first one should be title0, publisher0, ISBN0: " << endl;
    it = v.begin();
    (*it).showInfo();

    v.insert(v.begin(), bookType("InsertTitle", "publisher",
                            "ISBN", 2000, 10,
                            1, authors, 2));

    cout << "After inserting to the beginning, the first one should be InsertTitle, publisher, ISBN: " << endl;
    it = v.begin();
    (*it).showInfo();

    // print out every books stores in the vector backwards until the vector is empty
    cout << endl << "3. Testing push_back(), pop_back(), empty(). 6 books will be printed out backwards: " << endl;
    while(!v.empty()){
        v.back().showInfo();
        v.pop_back();
    }
    
    cout << endl;
}