#include<iostream>
using namespace std;

class Calculator {

    float a, b;

public:

    void getNumbers() {
        cout << "Enter two numbers: ";
        cin >> a >> b;
    }

    void addition() {
        cout << "Addition = " << a+b << endl;
    }

    void subtraction() {
        cout << "Subtraction = " << a-b << endl;
    }

    void multiplication() {
        cout << "Multiplication = " << a*b << endl;
    }

    void division() {
        if(b != 0) {
            cout << "Division = " << a/b << endl;
        }
        else {
            cout << "Division by zero is not possible!" << endl;
        }
    }
};

int main() {

    Calculator obj;
    int choice;

    do {
        cout << "\n----- Simple Calculator -----" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        if(choice >= 1 && choice <= 4) {
            obj.getNumbers();
        }

        switch(choice) {

            case 1:
                obj.addition();
                break;

            case 2:
                obj.subtraction();
                break;

            case 3:
                obj.multiplication();
                break;

            case 4:
                obj.division();
                break;

            case 5:
                cout << "Exiting Calculator..." << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while(choice != 5);

    return 0;
}