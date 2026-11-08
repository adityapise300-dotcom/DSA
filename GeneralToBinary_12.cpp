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

void Tree::conversion(Node*node){
    if(node==NULL){
        return;
    }

    cout<<"\nNode: "<<node->data;
    if(node->left!=NULL){
        cout<<"\nAt left of Node: "<<node->left->data;
    }else{
        cout<<"\nNothing on left";
    }
    if(node->right!=NULL){
        cout<<"\nAt Right of Node: "<<node->right->data;
    }else{
        cout<<"\nNothing on right";
    }
    cout<<endl;

    conversion(node->left);
    conversion(node->right);
}

void Tree::show(){
    if(root==NULL){
        cout<<"\nList is Empty";
        return;
    }
    conversion(root);
}

int main(){
    Tree T;
    T.MakeTree();
    T.show();
    return 0;
}