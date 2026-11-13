#include<iostream>
#include<stack>
using namespace std;

template<class T>
void push(T stack[], int &top, int size, T value){
    if(top == size-1){
        cout<<"Stact overflow !"<<endl;
        return;
    }else{
        top++;
        stack[top] = value;
        cout<<"\nElement Pushed Successfully !";
    }
}

template<class T>
void pop(T stack[], int &top){
    if(top==-1){
        cout<<"Stact Underflow !!"<<endl;
    }else{
        cout<<"Element "<<stack[top]<<" was removed successfully !"<<endl;
        top--;
    }
}

template<class T>
void display(T stack[], int top){
    if(top==-1){
        cout<<"Stack is empty";
        return;
    }

    cout<<"Current stack is: ";
    for(int i=top; i>=0; i--){
        cout<<stack[i]<<" ";
    }
}

