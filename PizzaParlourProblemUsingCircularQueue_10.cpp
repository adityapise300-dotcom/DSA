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

