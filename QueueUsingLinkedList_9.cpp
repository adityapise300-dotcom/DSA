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
        void create();
        void display();
        void enqueue();
        void dequeue();
};

void Queue::create(){
    int x;
    Node*temp = NULL;
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



