#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Student {
    int roll;
    char name[50];
    float marks;

public:

    void getData() {
        cout << "\nEnter Roll No: ";
        cin >> roll;

        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 50);

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "\nRoll No: " << roll;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks << endl;
    }

    int getRoll() {
        return roll;
    }

    char* getName() {
        return name;
    }
};

// a. Create and write student object
void createStudent() {
    Student s;

    ofstream fout("student.dat", ios::binary | ios::app);

    s.getData();

    fout.write((char*)&s, sizeof(s));

    fout.close();

    cout << "\nStudent record added successfully!\n";
}

// b. Display student details
void displayStudent() {
    Student s;

    ifstream fin("student.dat", ios::binary);

    if (!fin) {
        cout << "\nFile not found!\n";
        return;
    }

    cout << "\n--- Student Records ---\n";

    while (fin.read((char*)&s, sizeof(s))) {
        s.display();
    }

    fin.close();
}

// c. Search record based on Roll No. or Name
void searchStudent() {
    Student s;
    int choice, roll;
    char name[50];
    bool found = false;

    ifstream fin("student.dat", ios::binary);

    if (!fin) {
        cout << "\nFile not found!\n";
        return;
    }

    cout << "\n1. Search by Roll No";
    cout << "\n2. Search by Name";
    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "\nEnter Roll No: ";
        cin >> roll;
    }
    else if (choice == 2) {
        cout << "\nEnter Name: ";
        cin.ignore();
        cin.getline(name, 50);
    }
    else {
        cout << "\nInvalid choice!";
        fin.close();
        return;
    }

    while (fin.read((char*)&s, sizeof(s))) {

        if ((choice == 1 && s.getRoll() == roll) ||
            (choice == 2 && strcmp(s.getName(), name) == 0)) {

            cout << "\nRecord Found!";
            s.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nRecord not found!";
    }

    fin.close();
}

// d. Modify student record
void modifyStudent() {
    Student s;
    int roll;
    bool found = false;

    fstream file("student.dat", ios::binary | ios::in | ios::out);

    if (!file) {
        cout << "\nFile not found!\n";
        return;
    }

    cout << "\nEnter Roll No to modify: ";
    cin >> roll;

    while (file.read((char*)&s, sizeof(s))) {

        if (s.getRoll() == roll) {

            cout << "\nExisting Record:";
            s.display();

            cout << "\nEnter New Details:";
            s.getData();

            file.seekp(-sizeof(s), ios::cur);

            file.write((char*)&s, sizeof(s));

            cout << "\nRecord Modified Successfully!";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nRecord not found!";
    }

    file.close();
}

// e. Delete student record
void deleteStudent() {
    Student s;
    int roll;
    bool found = false;

    ifstream fin("student.dat", ios::binary);
    ofstream fout("temp.dat", ios::binary);

    if (!fin) {
        cout << "\nFile not found!\n";
        fout.close();
        return;
    }

    cout << "\nEnter Roll No to delete: ";
    cin >> roll;

    while (fin.read((char*)&s, sizeof(s))) {

        if (s.getRoll() == roll) {
            found = true;
            continue;
        }

        fout.write((char*)&s, sizeof(s));
    }

    fin.close();
    fout.close();

    remove("student.dat");
    rename("temp.dat", "student.dat");

    if (found) {
        cout << "\nRecord Deleted Successfully!";
    }
    else {
        cout << "\nRecord not found!";
    }
}

int main() {
    int choice;

    do {
        cout << "\n\n===== STUDENT RECORD MANAGEMENT =====";
        cout << "\n1. Create Student Record";
        cout << "\n2. Display Student Records";
        cout << "\n3. Search Student Record";
        cout << "\n4. Modify Student Record";
        cout << "\n5. Delete Student Record";
        cout << "\n6. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                createStudent();
                break;

            case 2:
                displayStudent();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                modifyStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                cout << "\nExiting Program...";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while (choice != 6);

    return 0;
}