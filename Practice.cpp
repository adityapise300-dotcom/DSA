#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
};

class Stack{
    Node*head = NULL;
    public:
        void push();
        void pop();
        void display();
};

void Stack::push(){
    Node*newNode = new Node;
    int val;
    cout<<"\nEnter the Value to push: ";
    cin>>val;
    newNode->data = val;
    if(head == NULL){
        head = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
    cout<<"\nElement "<<head->data<<" is Pushed successfully.";
}

void Stack::pop(){
    cout<<"\n\nElement "<<head->data<<" is deleted successfully.";
    Node*temp = head;
    head = head->next;
    delete temp;
}

void Stack::display(){
    cout<<"\nCurrent Stack(top to bottom) is like: ";
    if(head==NULL){
        cout<<"Stack is Empty";
        return;
    }
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Stack S;
    S.push();
    S.push();
    S.push();
    S.pop();
    S.display();

    return 0;
}