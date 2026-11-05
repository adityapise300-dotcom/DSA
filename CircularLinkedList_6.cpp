#include<iostream>
#include<string>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class CircularLinkedList{
    Node*head = NULL;

    public:
        void create();
        void display();
        void search();
        void insertFirst();
        void insertLast();
        void insertByValue();
        void insertByPosition();
        void deleteFirst();
        void deleteLast();
        void deleteByValue();
        void deleteByPosition();
        void reverse();
        void findMiddle();
};

void CircularLinkedList::create(){
    int n,x;
    Node*temp = NULL;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<endl<<"Enter the nodes: ";
    for(int i=0; i<n; i++){
        Node*newNode = new Node;
        cin>>x;
        newNode->data = x;
        if(head == NULL){
            head = newNode;
            newNode->next = head;
            temp = newNode;
        }else{
            temp->next = newNode;
            newNode->next = head;
            temp = newNode;
        }
    } 
}

void CircularLinkedList::display(){
    if(head==NULL){
        cout<<"List is empty.";
        return;
    }
    cout<<"The Current Circular List is: ";
    Node*temp = head;
    cout<<temp->data<<" ";
    temp = temp->next;
    while(temp != head){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

