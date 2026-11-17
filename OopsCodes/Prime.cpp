#include<iostream>
using namespace std;

class Prime {
    int limit;

public:

    void getData() {
        cout << "Enter the Limit of the series: ";
        cin >> limit;
    }

    void displayPrime() {

        for(int i = 2; i <= limit; i++) {

            int flag = 0;

            for(int j = 2; j < i; j++) {

                if(i % j == 0) {
                    flag = 1;
                    break;
                }
            }

            if(flag == 0) {
                cout << i << " ";
            }
        }
    }
};

int main() {

    Prime obj;

    obj.getData();

    cout << "\nPrime Numbers: ";
    obj.displayPrime();

    return 0;
}