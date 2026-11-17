#include<iostream>
#include<vector>
using namespace std;

class Operations {
    vector<int> v;

public:

    // Add elements to vector
    void addElements() {
        int n, value;

        cout << "Enter number of elements: ";
        cin >> n;

        for(int i = 0; i < n; i++) {
            cout << "Enter element: ";
            cin >> value;

            v.push_back(value);
        }
    }

    // Display vector
    void display() {
        cout << "\nVector Elements: ";

        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
    }

    // Access 3rd element
    void accessElement() {
        cout << "\n\n3rd Element using index: " << v[2];

        cout << "\n3rd Element using at(): " << v.at(2);
    }

    // Remove last element
    void removeElement() {
        v.pop_back();

        cout << "\n\nAfter removing last element:";

        display();
    }
};

int main() {

    Operations obj;

    obj.addElements();

    obj.display();

    obj.accessElement();

    obj.removeElement();

    return 0;
}