#include<iostream>
#include<string>
using namespace std;

struct Node{
    int data;
    Node*next;
};

class Stack{
    Node*top = NULL;

    public:
        void create();
        void push();
        void pop();
        void display();
};

void Stack::create(){
    int n,x;
    cout<<"Enter the number of Nodes in the stack: ";
    cin>>n;
    cout<<"Enter the node value: ";
    for(int i=0; i<n; i++){
        cin>>x;
        Node*newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }
}

void Stack::push(){
    int d;
    cout<<"Enter the value you want to insert: ";
    cin>>d;
    Node*newNode = new Node;
    newNode->data = d;
    newNode->next = top;
    top = newNode;
}

void Stack::pop(){
    if(top==NULL){
        cout<<"Stack is empty.";
        return;
    }
    Node*temp = top;
    top = temp->next;
    temp->next = NULL;
    delete temp;
}

void Stack::display(){
    if(top==NULL){
        cout<<"Stack is empty.";
        return;
    }
    Node*temp = top;
    cout<<"Current stack is: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    int choice;
    char cont;
    Stack S;
    S.create();
    S.display();
    do{
        cout<<endl<<"Menu: \n1. push \n2. pop"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                S.push();
                S.display();
                break;
            
            case 2:
                S.pop();
                S.display();
                break;
        }

        cout<<endl<<"Do you want to redo any operation?(Y/N): ";
        cin>>cont;
    }while(cont=='Y'||cont=='y');
    return 0;
}