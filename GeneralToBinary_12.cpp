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

Node* Tree::CreateTree(){
    int val,n;

    cout<<"\nEnter the data of node: ";
    cin>>val;

    cout<<"\nEnter the childrens of this Node: ";
    cin>>n;

    Node*node = new Node(val);
    Node*previous=NULL;

    for(int i=0;i<n;i++){
        Node*child = CreateTree();

        if(node->left!=NULL){
            node->left = child;
        }else{
            previous->right = child;
        }
        previous = child;
    }
    return node;
}

void Tree::MakeTree(){
    root = CreateTree();
}

