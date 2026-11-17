#include<iostream>
#include<string>
using namespace std;

template<class T>
T maxima(T a, T b) {
    if(a > b) {
        return a;
    }
    else {
        return b;
    }
}

int main() {

    int choice;

    do {
        cout << "\n===== FIND MAXIMUM USING TEMPLATE =====";
        cout << "\n1. Integer";
        cout << "\n2. Float";
        cout << "\n3. String";
        cout << "\n4. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                int a, b;

                cout << "\nEnter First Integer: ";
                cin >> a;

                cout << "Enter Second Integer: ";
                cin >> b;

                cout << "\nMaximum is: " << maxima(a, b);
                break;
            }

            case 2: {
                float a, b;

                cout << "\nEnter First Float: ";
                cin >> a;

                cout << "Enter Second Float: ";
                cin >> b;

                cout << "\nMaximum is: " << maxima(a, b);
                break;
            }

            case 3: {
                string a, b;

                cout << "\nEnter First String: ";
                cin >> a;

                cout << "Enter Second String: ";
                cin >> b;

                cout << "\nMaximum is: " << maxima(a, b);
                break;
            }

            case 4:
                cout << "\nExiting Program...";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 4);

    return 0;
}
