#include<iostream>
#include<string>
using namespace std;

class Node{
   public:
    int roll;
    string name;
    float marks;
    Node*left;
    Node*right;
    Node(int r,string n,float m){
        roll = r;
        name = n;
        marks = m;
        right = left = NULL;
    }
};

class Tree{
    Node*root;
    public:
     Tree(){
        root=NULL;
     }
     Node* create(Node*root,int r,string n,float m);
     void createnode();
     void display(Node*root);
     void displayinorder();
     Node* search(Node*root,int r);
     void searchnode();
     Node* findMin(Node*root);
     Node* deletee(Node*root,int r);
     void deletenode();
};

Node* Tree :: create(Node*root,int r,string n,float m){
    if(root==NULL){
        return new Node(r,n,m);
    }
    if(r<root->roll){
        root->left = create(root->left,r,n,m);
    }else if(r>root->roll){
        root->right = create(root->right,r,n,m);
    }else{
        cout<<"Element already exists";
    }
    return root;
}

void Tree::createnode(){
    int r;
    string n;
    float m;
    cout<<"Enter Roll No: ";
    cin>>r;
    cout<<"Enter name: ";
    cin>>n;
    cout<<"Enter Marks: ";
    cin>>m;
    root = create(root,r,n,m);
}

void Tree::display(Node*root){
    if(root!=NULL){
        display(root->left);
        cout<<"Roll no: "<<root->roll;
        cout<<"Name: "<<root->name;
        cout<<"marks: "<<root->marks;
        display(root->right);
    }
}

void Tree ::displayinorder(){
    if(root==NULL){
        cout<<"System is empty";
    }else{
        display(root);
    }
}

Node* Tree::search(Node*root,int r){
    if(root==NULL || r==root->roll){
        return root;
    }
    if(r<root->roll){
        return search(root->left,r);
    }else{
        return search(root->right,r);
    }
}

void Tree::searchnode(){
    int r;
    cout<<"Enter Roll Number to search: ";
    cin>>r;
    if(search(root,r)==NULL){
        cout<<"Element not found";
    }else{
        Node*temp = search(root,r);
        cout<<"Student Found";
        cout<<"Roll no: "<<temp->roll;
        cout<<"Name: "<<temp->name;
        cout<<"Marks: "<<temp->marks;
    }
}

Node* Tree::findMin(Node*root){
    while(root!=NULL && root->left!=NULL){
        root = root->left;
    }
    return root;
}

Node* Tree::deletee(Node*root,int r){
    if(root==NULL){
        return root;
    }
    if(r<root->roll){
        root->left = deletee(root->left,r);
    }else if(r>root->roll){
        root->right = deletee(root->right,r);
    }else{
        if(root->left==NULL){
            Node*temp = root->right;
            delete root;
            return temp;
        }

        if(root->right==NULL){
            Node*temp = root->left;
            delete root;
            return temp;
        }

        Node*temp = findMin(root->right);
        root->roll = temp->roll;
        root->name = temp->name;
        root->marks = temp->marks;
        root->right = deletee(root->right,temp->roll);
    }
    return root;
}

void Tree::deletenode(){
    int r;
    cout<<"Roll No to delete: ";
    cin>>r;
    if(search(root, r) == NULL){
        cout<<"Nothing to delete";
    }else{
        root = deletee(root,r);
        cout<<"Student record deleted Successfully";
    }
}

int main(){
    Tree t;
    int choice;

    do{
        cout<<"\n\n----- BINARY SEARCH TREE -----";
        cout<<"\n1. Insert Student";
        cout<<"\n2. Display Students (Inorder)";
        cout<<"\n3. Search Student";
        cout<<"\n4. Delete Student";
        cout<<"\n5. Exit";

        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice){

            case 1:
                t.createnode();
                break;

            case 2:
                t.displayinorder();
                break;

            case 3:
                t.searchnode();
                break;

            case 4:
                t.deletenode();
                break;

            case 5:
                cout<<"Exiting Program...";
                break;

            default:
                cout<<"Invalid Choice!";
        }

    }while(choice!=5);

    return 0;
}