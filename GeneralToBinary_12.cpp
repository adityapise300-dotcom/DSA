#include<iostream>
#include<string>
using namespace std;

class Node{
  public:  
    int data;
    Node*right;
    Node*left;
    Node(int value){
        data = value;
        right = left = NULL;
    }

};

class Tree{
    Node*root;
    public:
     Tree(){
        root = NULL;
     };
     Node* CreateTree();
     void MakeTree();
     void conversion(Node*node);
     void show();
     void distroy(Node*node);
};

