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

void CircularLinkedList::insertFirst(){
    int x;
    cout<<"Enter the value of new node: ";
    cin>>x;
    Node*newNode = new Node;
    newNode->data = x;
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }else{
        Node*temp = head;
        temp = temp->next;
        while(temp->next !=head){
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void CircularLinkedList::insertLast(){
    int x;
    cout<<"Enter the value of new node: ";
    cin>>x;
    Node*newNode = new Node;
    newNode->data = x;
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }else{
        Node*temp = head;
        temp = temp->next;
        while(temp->next !=head){
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
    }
}

void CircularLinkedList::insertByValue(){
    int x,val;
    cout<<"Enter the value after which you want to insert: ";
    cin>>val;
    cout<<"Enter the value of new node: ";
    cin>>x;
    Node*newNode = new Node;
    newNode->data = x;
    if(head == NULL){
        cout<<"The list is empty."<<endl;
        return;
    }else{
        Node*temp = head;
        while(temp->data != val){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void CircularLinkedList::insertByPosition(){
    if(head==NULL){
        cout<<"List is empty";
        return;
    }
    int x,pos;
    cout<<"Enter the Position at which you want to insert: ";
    cin>>pos;
    cout<<"Enter the value of new node: ";
    cin>>x;
    Node*newNode = new Node;
    newNode->data = x;
    int count = 1;
    Node*temp = head;
    if(pos==1){
        Node*temp1 = head;
        temp1 = temp1->next;
        while(temp1->next !=head){
            temp1 = temp1->next;
        }
        newNode->next = head;
        temp1->next = newNode;
        head = newNode;
        return;
    }
    while(count<=pos-1){
        if(count == pos-1){
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }else{
            temp = temp->next;
            count++;
        }
    }
}

void CircularLinkedList::deleteFirst(){
    if(head==NULL){
        cout<<"List is empty";
        return;
    }
    Node*temp = head;
    Node*temp1 = head;
    temp1 = temp1->next;
    while(temp1->next !=head){
        temp1 = temp1->next;
    }
    temp1->next = temp->next;
    head = temp->next;
    delete temp;
}

void CircularLinkedList::deleteLast(){
    if(head==NULL){
        cout<<"List is empty";
        return;
    }
    Node*temp = head;
    Node*temp1 = head;
    temp1 = temp1->next;
    temp = temp->next;
    while(temp->next!=head){
        temp = temp->next;
    }
    while(temp1->next->next!=head){
        temp1 = temp1->next;
    }

    temp1->next = head;
    delete temp;
}

void CircularLinkedList::deleteByValue(){
    if(head==NULL){
        cout<<"List is empty";
        return;
    }
    int val;
    cout<<"enter the value of node after which you want you delete the node: ";
    cin>>val;
    Node*temp = head;
    Node*temp1 = head;
    temp1 = temp1->next;
    temp = temp->next;
    while(temp->data != val){
        temp = temp->next;
    }
    while(temp1->next->data != val){
        temp1 = temp1->next;
    }
    temp1->next = temp->next;
    delete temp;
}


