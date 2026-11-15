#include<iostream>
#include<string>
using namespace std;

class Parlour{
    int arr[100];
    int front;
    int rear;
    int M;
    public:
        Parlour(int size){
            M = size;
            front = -1;
            rear = -1;
        }
        void placeorder();
        void serveorder();
        void showorders();
};

void Parlour::placeorder(){
    if((rear+1)%M==front){
        cout<<"Orders overflow"<<endl;
        return;
    }

    int x;
    cout<<"\nEnter the order id:  ";
    cin>>x;

    if(rear == -1){
        front = 0;
        rear = 0;
    }else{
        rear = (rear+1)%M;
    }

    arr[rear] = x;

    cout<<" Order Placed !";
}

void Parlour::serveorder(){
    if(front == -1){
        cout<<"\nOrders underflow";
        return;
    }

    cout<<"\nOrder "<<arr[front]<<" Served !";

    if(front==rear){
        front=-1;
        rear=-1;
    }else{
        front = (front+1)%M;
    }
}

void Parlour::showorders(){
    if(front == -1){
        cout<<"\nNo Pending Orders Exist";
        return;
    }

    int i = front;

    cout<<"Currently Pending orders are : ";

    while(true){
        cout<<arr[i]<<" ";

        if(i == rear){
            break;
        }

        i=(i+1)%M;
    }
}

int main(){
    int size, choice;

    cout<<"Enter the maximum number of orders: ";
    cin>>size;

    Parlour p(size);

    do{
        cout<<"\n\n----- PARLOUR ORDER MANAGEMENT -----";
        cout<<"\n1. Place Order";
        cout<<"\n2. Serve Order";
        cout<<"\n3. Show Pending Orders";
        cout<<"\n4. Exit";

        cout<<"\n\nEnter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                p.placeorder();
                break;

            case 2:
                p.serveorder();
                break;

            case 3:
                p.showorders();
                break;

            case 4:
                cout<<"\nExiting Program...";
                break;

            default:
                cout<<"\nInvalid Choice!";
        }

    }while(choice != 4);

    return 0;
}