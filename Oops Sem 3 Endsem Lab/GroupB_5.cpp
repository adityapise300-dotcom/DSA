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

