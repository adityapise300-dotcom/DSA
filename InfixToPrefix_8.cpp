#include<iostream>
#include<string>
#include<stack>
using namespace std;

class InfToPost{
    public:
        int precedence(char op);
        bool isoperand(char ch);
        string conversion(string infix);
};

