#include <iostream>
#include <stack>
#include <string>
using namespace std;

void add(stack<double> &s);
void substract(stack<double> &s);
void multiply(stack<double> &s);
void divide(stack<double> &s);
bool check(stack<double> &s);
string userInput(string command = "");

int main()
{
    stack<double> s;
    string command;
    cout << "Please enter numbers/operands or p to terminate: ";
    cin >> command;
    while(command != "p"){
        if(command == "+")
            add(s);
        else if(command == "-")
            substract(s);
        else if(command == "*")
            multiply(s);
        else if(command == "/")
            divide(s);
        else{
            s.push(stod(command));
        }
        command = userInput();
    }
    cout << "Calculation done. Your final result is: " << s.top() << endl;

    return 0;
}

void add(stack<double> &s)
{
    if(check(s)) return;

    double a = s.top();
    s.pop();
    double b = s.top();
    s.pop();
    s.push(b+a);
    cout << "Current result is: " << s.top() << endl;
}

void substract(stack<double> &s)
{
    if(check(s)) return;
    double a = s.top();
    s.pop();
    double b = s.top();
    s.pop();
    s.push(b-a);
    cout << "Current result is: " << s.top() << endl;
}

void multiply(stack<double> &s)
{
    if(check(s)) return;

    double a = s.top();
    s.pop();
    double b = s.top();
    s.pop();
    s.push(b*a);
    cout << "Current result is: " << s.top() << endl;
}

void divide(stack<double> &s)
{
    if(check(s)) return;

    double a = s.top();
    s.pop();
    double b = s.top();
    s.pop();
    s.push(b/a);
    cout << "Current result is: " << s.top() << endl;
}

bool check(stack<double> &s)
{
    if(s.size() < 2){
        userInput("p");
        return true;
    }
    return false;
}

string userInput(string command)
{
    if(command == ""){
        cout << "Please enter numbers/operands or p to terminate: ";
        cin >> command;
        return command;
    }else{
        return command;
    }
}