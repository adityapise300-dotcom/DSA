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

int InfToPost::precedence(char op){
    if(op=='^'){
        return 3;
    }else if(op=='*' || op=='/'){
        return 2;
    }else if(op=='+' || op=='-'){
        return 1;
    }else{
        return 0;
    }
}

