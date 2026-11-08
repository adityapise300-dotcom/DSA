#include <iostream>
using namespace std;

class Node
{
public:
    int rollNo;
    string name;
    float marks;
    Node *left, *right;
    Node(int r, string n, float m);
};

class StudentBST
{
    Node *root;
public:
    StudentBST();
    Node* insert(Node *root, int r, string n, float m);
    void addStudent();
    void displayInorder(Node *root);
    void displayStudents();
    Node* search(Node *root, int r);
    void searchStudent();
    Node* findMin(Node *root);
    Node* deleteNode(Node *root, int r);
    void deleteStudent();
};

// Node constructor
Node::Node(int r, string n, float m)
{
    rollNo = r;
    name = n;
    marks = m;
    left = right = NULL;
}

// BST constructor
StudentBST::StudentBST()
{
    root = NULL;
}

// Insert student record
Node* StudentBST::insert(Node *root, int r, string n, float m)
{
    if (root == NULL)
        return new Node(r, n, m);
    if (r < root->rollNo)
        root->left = insert(root->left, r, n, m);
    else if (r > root->rollNo)
        root->right = insert(root->right, r, n, m);
    else
        cout << "Roll number already exists!\n";
    return root;
}

void StudentBST::addStudent()
{
    int r;
    string n;
    float m;
    cout << "Enter Roll Number: ";
    cin >> r;
    cout << "Enter Name: ";
    cin >> n;
    cout << "Enter Marks: ";
    cin >> m;
    root = insert(root, r, n, m);
}

