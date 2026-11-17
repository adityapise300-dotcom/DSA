#include<iostream>
#include<stdexcept>
using namespace std;

class Complex {
    float real, imag;

    public:
        Complex() {
            real = 0;
            imag = 0;
        }

        // Addition
        friend Complex operator+(const Complex& c1, const Complex& c2) {
            Complex temp;

            temp.real = c1.real + c2.real;
            temp.imag = c1.imag + c2.imag;

            return temp;
        }

        // Subtraction
        friend Complex operator-(const Complex& c1, const Complex& c2) {
            Complex temp;

            temp.real = c1.real - c2.real;
            temp.imag = c1.imag - c2.imag;

            return temp;
        }

        // Multiplication
        friend Complex operator*(const Complex& c1, const Complex& c2) {
            Complex temp;

            temp.real = (c1.real * c2.real) - (c1.imag * c2.imag);
            temp.imag = (c1.real * c2.imag) + (c1.imag * c2.real);

            return temp;
        }

        // Division
        friend Complex operator/(const Complex& c1, const Complex& c2) {
            Complex temp;

            float denominator = (c2.real * c2.real) + (c2.imag * c2.imag);

            if(denominator == 0) {
                throw runtime_error("Division by zero!");
            }

            temp.real = ((c1.real * c2.real) + (c1.imag * c2.imag)) / denominator;

            temp.imag = ((c1.imag * c2.real) - (c1.real * c2.imag)) / denominator;

            return temp;
        }

        // Input Operator
        friend istream& operator>>(istream& in, Complex& c) {
            cout << "Enter the real part: ";
            in >> c.real;

            cout << "Enter the imaginary part: ";
            in >> c.imag;

            return in;
        }

        // Output Operator
        friend ostream& operator<<(ostream& out, const Complex& c) {
            out << c.real;

            if(c.imag >= 0) {
                out << " + " << c.imag << "i";
            }
            else {
                out << " - " << -c.imag << "i";
            }

            return out;
        }
};

int main() {

    Complex c1, c2, result;
    int choice;

    cout << "\nEnter First Complex Number:\n";
    cin >> c1;

    cout << "\nEnter Second Complex Number:\n";
    cin >> c2;

    do {
        cout << "\n\n===== COMPLEX NUMBER OPERATIONS =====";
        cout << "\n1. Addition";
        cout << "\n2. Subtraction";
        cout << "\n3. Multiplication";
        cout << "\n4. Division";
        cout << "\n5. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                result = c1 + c2;
                cout << "\nAddition: " << result;
                break;

            case 2:
                result = c1 - c2;
                cout << "\nSubtraction: " << result;
                break;

            case 3:
                result = c1 * c2;
                cout << "\nMultiplication: " << result;
                break;

            case 4:
                try {
                    result = c1 / c2;
                    cout << "\nDivision: " << result;
                }
                catch(runtime_error& e) {
                    cout << "\nDivision: " << e.what();
                }
                break;

            case 5:
                cout << "\nExiting Program...";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 5);

    return 0;
}
