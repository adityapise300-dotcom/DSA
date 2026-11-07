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

int main(){
    int size, choice;

    cout<<"Enter the size of queue: ";
    cin>>size;

    if(size<=0 || size>100){
        cout<<"Invalid queue size!"<<endl;
        return 0;
    }

    Parlour p(size);

    do{
        cout<<"\n\n1. Place Order";
        cout<<"\n2. Serve Order";
        cout<<"\n3. Display Orders";
        cout<<"\n4. Exit";

        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                p.placeorder();
                break;

            case 2:
                p.serveorder();
                break;

            case 3:
                p.displayorder();
                break;

            case 4:
                cout<<"Exiting..."<<endl;
                break;

            default:
                cout<<"Invalid choice!"<<endl;
        }

    }while(choice!=4);

    return 0;
}