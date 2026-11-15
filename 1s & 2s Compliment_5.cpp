#include<iostream>
#include<string>
using namespace std;

struct Node{
    int data;
    Node*next;
    Node*prev;
};

class Binary{
    Node*head = NULL;
    public:
        void create();
        void display();
        void ones();
        void twos();
};

void Binary::create(){
    int n,x;
    cout<<"Enter the number of nodes in your binary number: ";
    cin>>n;
    Node*temp;
    cout<<"\nEnter the value of nodes: ";
    for(int i=0;i<n;i++){
        
        cin>>x;
        Node*newNode = new Node;
        newNode->data = x;
        if(head==NULL){
            head = newNode;
            newNode->next = NULL;
            newNode->prev = NULL;
            temp = head;
        }else{
            temp->next = newNode;
            newNode->prev = temp;
            temp = temp->next;
        }
    }
}

void Binary::display(){
    cout<<"\nYour Current Linked list is :  ";
    Node*temp = head;
    if(head==NULL){
        cout<<"Empty List";
    }else{
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

void Binary::ones(){
    Node*temp = head;
    while(temp!=NULL){
        if (temp->data == 1){
            temp->data = 0;
        }else{
            temp->data = 1;
        }
        temp=temp->next;
    }
}

void Binary::twos(){
    Node*temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    int carry = 1;

    while(carry==1 && temp!=NULL){
        if(temp->data==1){
            temp->data = 0;
            carry = 1;
        }else{
            temp->data = 1;
            carry = 0;
        }
        temp = temp->prev;
    }

    if(carry==1){
        Node*newNode = new Node;
        newNode->data = 1;
        newNode->next = head;
        newNode->prev = NULL;
        head = newNode;
    }
}

int main(){
    Binary B;
    B.create();
    B.display();
    B.ones();
    B.display();
    B.twos();
    B.display();

    return 0;
}