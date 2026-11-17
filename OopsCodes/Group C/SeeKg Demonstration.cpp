#include<iostream>
#include<fstream>
using namespace std;

class FileOperations {

public:

    // Write data into file
    void writeData() {
        ofstream fout("data.txt");

        fout << "Hello World";

        fout.close();

        cout << "Data written successfully!\n";
    }

    // Read data from file
    void readData() {
        ifstream fin("data.txt");

        char ch;

        cout << "\nOriginal File Content: ";

        while(fin.get(ch)) {
            cout << ch;
        }

        // Using seekg()
        fin.clear();
        fin.seekg(6, ios::beg);

        cout << "\n\nContent from position 6: ";

        while(fin.get(ch)) {
            cout << ch;
        }

        fin.close();
    }

    // Modify data using seekp()
    void modifyData() {
        fstream file("data.txt", ios::in | ios::out);

        file.seekp(6, ios::beg);

        file.put('C');

        file.close();

        cout << "\n\nData modified successfully!";
    }

    // Display modified data
    void displayData() {
        ifstream fin("data.txt");

        char ch;

        cout << "\nModified File Content: ";

        while(fin.get(ch)) {
            cout << ch;
        }

        fin.close();
    }
};

int main() {

    FileOperations obj;

    obj.writeData();

    obj.readData();

    obj.modifyData();

    obj.displayData();

    return 0;
}