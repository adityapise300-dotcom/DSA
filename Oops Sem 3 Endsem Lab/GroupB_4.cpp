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

template<class T>
void Operatins(T stack[], int &top, int size){
    int choice;
    T value;

    do
    {
        cout<<"\n1. Push";
        cout<<"\n2. Pop";
        cout<<"\n3. Display";
        cout<<"\n4. Exit";

        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter element: ";
                cin>>value;

                push(stack, top, size, value);
                break;

            case 2:
                pop(stack, top);
                break;

            case 3:
                display(stack, top);
                break;

            case 4:
                cout<<"Exiting..."<<endl;
                break;

            default:
                cout<<"Invalid Choice!"<<endl;
        }

    }while(choice != 4);
}

