#include<iostream>
#include<list>
using namespace std;

class Operations {
    list<int> l = {10, 20, 30, 40, 50};

public:

    // Display list elements
    void display() {
        cout << "List Elements: ";

        for(int i : l) {
            cout << i << " ";
        }

        cout << endl;
    }

    // Add element at front
    void addFront() {
        l.push_front(60);

        cout << "\nAfter adding 60 at front: ";
        display();
    }

    // Add element at back
    void addBack() {
        l.push_back(5);

        cout << "\nAfter adding 5 at back: ";
        display();
    }

    // Remove first element
    void removeFront() {
        l.pop_front();

        cout << "\nAfter removing first element: ";
        display();
    }

    // Remove last element
    void removeBack() {
        l.pop_back();

        cout << "\nAfter removing last element: ";
        display();
    }
};

int main() {

    Operations obj;

    cout << "Original List: ";
    obj.display();

    obj.addFront();

    obj.addBack();

    obj.removeFront();

    obj.removeBack();

    return 0;
}