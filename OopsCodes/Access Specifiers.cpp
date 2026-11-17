#include<iostream>
using namespace std;

class Student{
    private:
        int rollno;

    protected:
        float marks;

    public:
        string name;

        void getdata(){
            cout<<"Enter Name: ";
            cin>>name;

            cout<<"Enter Roll Number: ";
            cin>>rollno;

            cout<<"Enter Marks: ";
            cin>>marks;
        }

        void display(){
            cout<<"\n----- Student Details -----"<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Roll Number: "<<rollno<<endl;
            cout<<"Marks: "<<marks<<endl;
        }
};

int main(){
    Student s;

    s.getdata();
    s.display();

    s.name = "Aditya";  // Public member accessible

    return 0;
}