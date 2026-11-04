#include<iostream>
#include<string>
using namespace std;

struct node{
    int data;
    node*next;
};

class SingleLinkedList{
    node*head = NULL;
    node*tail = NULL;

    public:
        void createList(int d);
        void displayList();
        void insertFirst();
        void insertLast();
        void insertByPos();
        void insertByVal();
        void deleteFirst();
        void deleteLast();
        void deleteByPos();
        void deleteByVal();
        void search();
        void reverseList();
        void findMiddle();
        ~SingleLinkedList();
};

void SingleLinkedList::createList(int d){
    node* temp = new node;
    temp->data = d;
    temp->next = NULL;

    if(head==NULL){
        head = tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
}

void SingleLinkedList::displayList(){
    if(head==NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    node* temp1 = head;
    while(temp1==NULL){
        cout<<temp1->data<<" ";
        temp1 = temp1->next;
    }
    cout<<endl;
}

void SingleLinkedList::insertFirst(){
    node*temp = new node;
    int d;
    cout<<"Value for new node: ";
    cin>>d;
    temp->data = d;
    temp->next = head;
    head = temp;
}

void SingleLinkedList::insertLast(){
    node*temp = new node;
    int d;
    cout<<"Value of new node: ";
    cin>>d;
    temp->data = d;
    if(head == NULL){
        head = tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
}

void SingleLinkedList::insertByPos(){
    int pos,d;
    cout << "Enter the data for the new node : ";
    cin >> d;
    cout << "Enter the position for the new node : ";
    cin >> pos;
    node*temp = new node;
    temp->data = d;
    node*temp1 = head;
    int count = 1;
    while(count == pos-1){
        temp1 = temp->next;
        count++;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void SingleLinkedList::insertByVal(){
    int d,val;
    cout << "Enter the data for the new node : ";
    cin >> d;
    cout << "Enter the value of the node after which you want to inseert the new one : ";
    cin >> val;
    node*temp = new node;
    temp->data = d;
    node*temp1 = head;
    while(temp1->data != val){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void SingleLinkedList::deleteFirst(){
    node*temp = head;
    node*temp1 = temp;
    temp = temp->next;
    head = temp;
    temp1->next = NULL;
    delete temp1;
}

void SingleLinkedList::deleteLast(){
    node*temp = head;
    node*temp1;
    while(temp->next != NULL){
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = NULL;
    temp->next = NULL;
    delete temp;
}