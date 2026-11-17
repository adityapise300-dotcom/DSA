#include<iostream>
#include<fstream>
using namespace std;

int main() {

    // Writing data into file
    ofstream fout("data.txt");

    fout << "Hello World";

    fout.close();

    cout << "Data written successfully!\n";


    // Reading data from file
    ifstream fin("data.txt");

    char ch;

    cout << "\nOriginal File Content: ";

    while(fin.get(ch)) {
        cout << ch;
    }


    // Using seekg() to move read pointer
    fin.clear();
    fin.seekg(6, ios::beg);

    cout << "\n\nContent from position 6: ";

    while(fin.get(ch)) {
        cout << ch;
    }

    fin.close();


    // Using seekp() to modify data
    fstream file("data.txt", ios::in | ios::out);

    file.seekp(6, ios::beg);

    file.put('C');

    file.close();


    // Display modified content
    ifstream fin2("data.txt");

    cout << "\n\nModified File Content: ";

    while(fin2.get(ch)) {
        cout << ch;
    }

    fin2.close();

    return 0;
}