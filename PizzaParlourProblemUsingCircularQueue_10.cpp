#include<iostream>
#include<string>
using namespace std;

class Parlour{
    int queue[100];
    int front, rear;
    int M;

    public:
        Parlour(int size);

        void placeorder();
        void serveorder();
        void displayorder();
};

Parlour::Parlour(int size){
    M = size;
    front = -1;
    rear = -1;
}

void Parlour::placeorder(){
    
    int order;

    if((rear+1)%M == front){
        cout<<"Queue is full !!";
        return;
    }

    cout<<"Enter the order: ";
    cin>>order;

    if(front==-1){
        rear = 0;
        front = 0;
    }else{
        rear = (rear+1)%M;
    }

    queue[rear] = order;

    cout<<"Order "<<order<<" was placed Successfully"<<endl; 
}

void Parlour::serveorder(){
    if(front==-1){
        cout<<"No orders to serve"<<endl;
        return;
    }

    cout<<"Order "<<queue[front]<<" was served!"<<endl;

    if(front==rear){
        front=-1;
        rear=-1;
    }else{
        front = (front+1)%M;
    }
}

void Parlour::displayorder(){
    if(front==-1){
        cout<<"No orders remaining"<<endl;
        return;
    }

    cout << "Pending Orders"<<endl;

    int i = front;

    while(true){
        cout<<queue[i]<<" ";

        if(i==rear){
            break;
        }

        i=(i+1)%M;
    }

    cout<<endl;
}

