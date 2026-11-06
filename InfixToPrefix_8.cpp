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

bool InfToPost::isoperand(char ch){
    if(ch>='A' && ch<='Z'){
        return true;
    }

    if(ch>='a' && ch<='z'){
        return true;
    }

    return false;
}

string InfToPost::conversion(string infix){
    string postfix = "";
    stack<char> s;

    for(int i=0; i<infix.length(); i++){

        char ch = infix[i];

        if(isoperand(ch)){
            postfix += ch;
        }else if(ch == '('){
            s.push(ch);
        }else if(ch == ')'){
            while(!s.empty() && s.top()!='('){
                postfix += s.top();
                s.pop();
            }

            if(!s.empty()){
                s.pop();
            }
        }else{
            while(!s.empty() && s.top()!='(' && precedence(s.top()) >= precedence(ch) ){
                postfix+=s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while(!s.empty()){
            postfix += s.top();
            s.pop();
        }

    return postfix;
    
};
