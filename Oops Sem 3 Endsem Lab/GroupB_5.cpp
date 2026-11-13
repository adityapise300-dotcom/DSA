#include<iostream>
using namespace std;

class employee{
    public:
        virtual int calculate(){
            return 1000;
        }
};

class manager : public employee{
    public:
        int calculate() override{
            return 1000+500;
        }
};

class developer : public employee{
    public:
        int calculate() override{
            return 1000+200;
        }
};

void printsalary(employee* emp){
    cout<<"Salary = "<<emp->calculate()<<endl;
}

int main(){
    employee E;
    manager M;
    developer D;

    cout<<"Employee Salary: ";
    printsalary(&E);

    cout<<"Manager Salary: ";
    printsalary(&M);

    cout<<"Developer Salary: ";
    printsalary(&D);

    return 0;
}