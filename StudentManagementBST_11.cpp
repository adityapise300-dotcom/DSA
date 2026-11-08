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

