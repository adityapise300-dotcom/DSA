#include<iostream>
using namespace std;

class Student{
    int rollno;
    string name;
    float marks;

    static int count;

    public:

        // Parameterized Constructor
        Student(int r, string n, float m){
            rollno = r;
            name = n;
            marks = m;
            count++;
        }

        // Inline Function
        inline void display(){
            cout<<"\nRoll Number: "<<rollno;
            cout<<"\nName: "<<name;
            cout<<"\nMarks: "<<marks<<endl;
        }

        // Static Function
        static void showCount(){
            cout<<"\nTotal Students: "<<count<<endl;
        }

        // Friend Function
        friend void showMarks(Student s);

        // Destructor
        ~Student(){
            cout<<"\nDestructor Called for "<<name<<endl;
        }
};

// Static Variable Definition
int Student::count = 0;

// Friend Function Definition
void showMarks(Student s){
    cout<<"Marks: "<<s.marks<<endl;
}

int main(){

    int n;

    cout<<"Enter number of students: ";
    cin>>n;

    Student* s[100];

    for(int i=0; i<n; i++){

        int r;
        string name;
        float m;

        cout<<"\nEnter details of Student "<<i+1<<endl;

        cout<<"Enter Roll Number: ";
        cin>>r;

        cout<<"Enter Name: ";
        cin>>name;

        cout<<"Enter Marks: ";
        cin>>m;

        s[i] = new Student(r,name,m);
    }

    cout<<"\n----- Student Details -----"<<endl;

    for(int i=0; i<n; i++){
        s[i]->display();
    }

    Student::showCount();

    cout<<"\n----- Marks Using Friend Function -----"<<endl;

    for(int i=0; i<n; i++){
        showMarks(*s[i]);
    }

    // Deleting objects
    for(int i=0; i<n; i++){
        delete s[i];
    }

    return 0;
}