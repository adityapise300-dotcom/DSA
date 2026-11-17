
#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Stack {
private:
    stack<T> s;

public:
    void push(T value) {
        s.push(value);
        cout << "Element pushed successfully!\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }

        cout << "Popped element: " << s.top() << endl;
        s.pop();
    }

    bool isEmpty() {
        return s.empty();
    }

    T top() {
        return s.top();
    }
};

int main() {
    Stack<int> s;
    int choice, value;

    do {
        cout << "\n--- STACK OPERATIONS ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Check if Stack is Empty\n";
        cout << "4. Display Top Element\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                if (s.isEmpty())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;

            case 4:
                if (s.isEmpty())
                    cout << "Stack is empty!\n";
                else
                    cout << "Top element: " << s.top() << endl;
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
