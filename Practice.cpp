#include<iostream>
#include<string>
#include<stack>
using namespace std;

class infToPost{
    stack<char> s;
    string postfix = "";
    public:
        int precesion(char op);
        bool isoperand(char ch);
        string conversion(string infix);
};

int infToPost :: precesion(char op){
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

bool infToPost :: isoperand(char ch){
    if(ch>='A' &&ch<='Z'){
        return true;
    }
    if(ch>='a'&&ch<='z'){
        return true;
    }

    return false;
}

string infToPost :: conversion(string infix){
    postfix = "";
    for(int i=0;i<infix.length();i++){
        char ch = infix[i];

        if(isoperand(ch)){
            postfix+=ch;
        }else if(ch=='('){
            s.push(ch);
        }else if(ch==')'){
            while(!s.empty() && s.top()!='('){
                postfix+=s.top();
                s.pop();
            }

            if(!s.empty()){
                s.pop();
            }
        }else{
            while(!s.empty() && s.top()!='(' && precesion(ch)<=precesion(s.top())){
                postfix +=s.top();
            }
            s.push(ch);
        }
    }

    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }

    return postfix;
}

int main(){
    infToPost I;
    string infix = "";
    cout<<"\nEnter the infix string: ";
    cin>>infix;
    string result = I.conversion(infix);
    cout<<endl<<result;

    return 0;
}

