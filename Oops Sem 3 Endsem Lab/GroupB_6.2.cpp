#include<iostream>
using namespace std;

template<class T>
class operations {
    T stack[100];
    int top = -1;

    public:

        void push(T value) {
            if(top == 99) {
                cout << "Stack Overflow !!" << endl;
            }
            else {
                top++;
                stack[top] = value;
                cout << "Element added successfully !!" << endl;
            }
        }

        void pop() {
            if(isempty()) {
                cout << "Stack is empty !!" << endl;
            }
            else {
                cout << "Element " << stack[top] << " was deleted" << endl;
                top--;
            }
        }

        bool isempty() {
            return top == -1;
        }
};

int main() {
    int choice, repeat, ch;

    operations<int> S1;
    operations<float> S2;
    operations<char> S3;

    do {
        cout << "\n----- Select Data Type -----";
        cout << "\n1. Integer";
        cout << "\n2. Float";
        cout << "\n3. Character";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                int value;

                cout << "\n----- Integer Stack -----";
                cout << "\n1. Push";
                cout << "\n2. Pop";
                cout << "\n3. Check Empty";
                cout << "\nEnter choice: ";
                cin >> ch;

                switch(ch) {
                    case 1:
                        cout << "Enter integer: ";
                        cin >> value;
                        S1.push(value);
                        break;

                    case 2:
                        S1.pop();
                        break;

                    case 3:
                        if(S1.isempty())
                            cout << "Stack is empty";
                        else
                            cout << "Stack is not empty";
                        break;

                    default:
                        cout << "Invalid choice!";
                }
                break;
            }

            case 2: {
                float value;

                cout << "\n----- Float Stack -----";
                cout << "\n1. Push";
                cout << "\n2. Pop";
                cout << "\n3. Check Empty";
                cout << "\nEnter choice: ";
                cin >> ch;

                switch(ch) {
                    case 1:
                        cout << "Enter float: ";
                        cin >> value;
                        S2.push(value);
                        break;

                    case 2:
                        S2.pop();
                        break;

                    case 3:
                        if(S2.isempty())
                            cout << "Stack is empty";
                        else
                            cout << "Stack is not empty";
                        break;

                    default:
                        cout << "Invalid choice!";
                }
                break;
            }

            case 3: {
                char value;

                cout << "\n----- Character Stack -----";
                cout << "\n1. Push";
                cout << "\n2. Pop";
                cout << "\n3. Check Empty";
                cout << "\nEnter choice: ";
                cin >> ch;

                switch(ch) {
                    case 1:
                        cout << "Enter character: ";
                        cin >> value;
                        S3.push(value);
                        break;

                    case 2:
                        S3.pop();
                        break;

                    case 3:
                        if(S3.isempty())
                            cout << "Stack is empty";
                        else
                            cout << "Stack is not empty";
                        break;

                    default:
                        cout << "Invalid choice!";
                }
                break;
            }

            default:
                cout << "Invalid data type choice!";
        }

        cout << "\n\nDo you want to perform operations again?";
        cout << "\n1. Yes";
        cout << "\n2. No";
        cout << "\nEnter choice: ";
        cin >> repeat;

    } while(repeat == 1);

    cout << "\nProgram terminated successfully!";

    return 0;
}