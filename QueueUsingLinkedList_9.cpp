#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
};

class Queue{
    Node*head = NULL;
    public:
        void enqueue();
        void dequeue();
        void display();
};

void Queue::enqueue(){
    int val;
    cout<<"\nEnter the Value for adding: ";
    cin>>val;
    Node*newNode = new Node;
    newNode->data = val;
    if(head==NULL){
      head = newNode;
      return;
    }
    Node*temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void Queue ::dequeue(){
    Node*temp = head;
    head = head->next;
    delete temp;
}

void Queue::display(){
    cout<<"Current Queue Looks like: ";
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Queue Q;
    Q.enqueue();
    Q.display();
    Q.enqueue();
    Q.display();
    Q.enqueue();
    Q.display();
    Q.enqueue();
    Q.display();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.display();

    return 0;
}