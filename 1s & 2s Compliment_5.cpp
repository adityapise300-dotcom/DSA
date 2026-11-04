#include<iostream>
#include<string>
using namespace std;

struct Node{
    int data;
    Node*next;
    Node*prev;
};

class Binary{
    Node* head = NULL;
    Node* tail = NULL;

    public:
        void create();
        void display();
        void ones();
        void twos();
};

void Binary::create(){
    int n,x;
    cout<<"Enter the number of bits: ";
    cin>>n;

    for(int i=0; i<n; i++){
        cout<<"Enter bit: ";
        cin>>x;
        
        Node* temp = new Node;
        temp->data = x;
        temp->next = NULL;
        temp->prev = NULL;

        if(head == NULL){
            head = tail = temp;
        }else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
}

void Binary::display(){
    if(head==NULL){
        cout<<"No Binary Number exists"<<endl;
        return;
    }else{
        cout<<"Binary Number: ";
        for(Node*temp = head; temp!=NULL; temp = temp->next){
            cout<<temp->data;
        }
        cout<<endl;
    }
}

void Binary::ones(){
    Node*temp = head;
    while(temp!=NULL){
        if(temp->data==0){
            temp->data=1;
        }else{
            temp->data=0;
        }
        temp = temp->next;
    }

    cout<<"Ones compliment is: ";
    for(Node*temp = head; temp!=NULL; temp = temp->next){
            cout<<temp->data;
        }
    cout<<endl;
}

void Binary::twos(){
    Node*temp = head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    int carry = 1;

    while(temp!=NULL && carry==1){
        if(temp->data==0){
            temp->data=1;
            carry=0;
        }else{
            temp->data=0;
            carry=1;
        }

        temp = temp->prev;
    }

    if(carry==1){
        temp = new Node;
        temp->data = 1;
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    cout<<"Twos compliment is: ";
    for(Node*temp = head; temp!=NULL; temp = temp->next){
            cout<<temp->data;
        }
    cout<<endl;
}
