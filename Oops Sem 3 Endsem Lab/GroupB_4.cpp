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

