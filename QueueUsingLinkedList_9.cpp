#include<iostream>
#include<string>
using namespace std;

struct Node{
    int data;
    Node*next;
};

class Queue{
    Node*head;
    int n;

    public:
        Queue(){
            head = NULL;
            n = 0;
        }
        void create();
        void display();
        void enqueue();
        void dequeue();
};

void Queue::create(){
    int x;
    Node*temp = NULL;
    head = NULL;
    cout<<"Enter the capacity of queue: ";
    cin>>n;
    cout<<"Enter the value of nodes in the queue: ";
    for(int i=0;i<n;i++){
        cin>>x;
        Node*newNode = new Node;
        newNode->data = x;
        newNode->next = NULL;
        if(head==NULL){
            head = newNode;
            temp = head;
        }else{
            temp->next = newNode;
            temp = temp->next;
        }
    }
}

void Queue::display(){
    if(head==NULL){
        cout<<"List is empty.";
        return;
    }
    Node*temp = head;
    cout<<"Your current List of Queue is: ";
   while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
   }
   cout<<endl;
}

void Queue::enqueue(){
    int val;
    cout<<"Enter the value of the new node: ";
    cin>>val;
    Node*newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
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

void Queue::dequeue(){
    if(head==NULL){
        cout<<"List is empty, can't pop";
        return;
    }

    Node*temp = head;
    head = temp->next;
    delete temp;
}

int main(){
    int choice;
    char cont;
    Queue Q;
    Q.create();
    Q.display();
    cout<<endl<<"menu: "<<"\n1. enqueue(push) \n2. dequeue(pop)"<<endl;
    cout<<"Enter the Operation you want to perform (1/2): ";
    cin>>choice;
    do{
        switch(choice){
            case 1:
                Q.enqueue();
                Q.display();
                break;

            case 2:
                Q.dequeue();
                Q.display();
                break;
        }

        cout<<"do you want to redo the operation?(Y/N): ";
        cin>>cont;
    }while(cont=='Y'||cont=='y');

    return 0;
}
