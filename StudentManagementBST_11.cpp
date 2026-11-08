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

// Display records in ascending order of roll number
void StudentBST::displayInorder(Node *root)
{
    if (root != NULL)
    {
        displayInorder(root->left);
        cout << "Roll No: " << root->rollNo
             << ", Name: " << root->name
             << ", Marks: " << root->marks << endl;
        displayInorder(root->right);
    }
}

void StudentBST::displayStudents()
{
    if (root == NULL)
        cout << "No student records found.\n";
    else
        displayInorder(root);
}

// Search student by roll number
Node* StudentBST::search(Node *root, int r)
{
    if (root == NULL || root->rollNo == r)
        return root;
    if (r < root->rollNo)
        return search(root->left, r);
    return search(root->right, r);
}

void StudentBST::searchStudent()
{
    int r;
    cout << "Enter Roll Number to search: ";
    cin >> r;
    Node *temp = search(root, r);
    if (temp == NULL)
        cout << "Student record not found.\n";
    else
    {
        cout << "Student Found!\n";
        cout << "Roll No: " << temp->rollNo << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Marks: " << temp->marks << endl;
    }
}

