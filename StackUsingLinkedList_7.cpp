#include<iostream>
#include<string>
using namespace std;

struct Node{
    int data;
    Node*next;
};

class Stack{
    Node*top = NULL;

    public:
        void create();
        void push();
        void pop();
        void display();
};

