#include<iostream>
using namespace std;

// A. SINGLE INHERITANCE

class Car{
    public:
        string brand;

        void getCar(){
            cout<<"Enter Car Brand: ";
            cin>>brand;
        }
};

class Rental : public Car{
    public:
        int days;
        int rent;

        void getRental(){
            cout<<"Enter Number of Days: ";
            cin>>days;

            cout<<"Enter Rent Per Day: ";
            cin>>rent;
        }

        void display(){
            cout<<"\nCar Brand: "<<brand;
            cout<<"\nTotal Rent: "<<days*rent<<endl;
        }
};


// B. MULTILEVEL INHERITANCE

class Vehicle{
    public:
        string name;

        void getVehicle(){
            cout<<"Enter Vehicle Name: ";
            cin>>name;
        }
};

class CarType : public Vehicle{
    public:
        string type;

        void getType(){
            cout<<"Enter Car Type: ";
            cin>>type;
        }
};

class Booking : public CarType{
    public:
        int days;
        int rent;

        void getBooking(){
            cout<<"Enter Number of Days: ";
            cin>>days;

            cout<<"Enter Rent Per Day: ";
            cin>>rent;
        }

        void display(){
            cout<<"\nVehicle Name: "<<name;
            cout<<"\nCar Type: "<<type;
            cout<<"\nTotal Rent: "<<days*rent<<endl;
        }
};


// C. MULTIPLE INHERITANCE

class Customer{
    public:
        string customerName;

        void getCustomer(){
            cout<<"Enter Customer Name: ";
            cin>>customerName;
        }
};

class Payment{
    public:
        int amount;

        void getPayment(){
            cout<<"Enter Payment Amount: ";
            cin>>amount;
        }
};

class CarRental : public Customer, public Payment{
    public:
        void display(){
            cout<<"\nCustomer Name: "<<customerName;
            cout<<"\nPayment Amount: "<<amount<<endl;
        }
};


// D. HIERARCHICAL INHERITANCE

class RentalBase{
    public:
        int days;
        int rent;

        void getDetails(){
            cout<<"Enter Number of Days: ";
            cin>>days;

            cout<<"Enter Rent Per Day: ";
            cin>>rent;
        }
};

class Hatchback : public RentalBase{
    public:
        void display(){
            cout<<"\nHatchback Total Rent: "<<days*rent<<endl;
        }
};

class SUV : public RentalBase{
    public:
        void display(){
            cout<<"\nSUV Total Rent: "<<days*rent<<endl;
        }
};


int main(){

    // SINGLE INHERITANCE
    cout<<"\n===== SINGLE INHERITANCE ====="<<endl;

    Rental r;
    r.getCar();
    r.getRental();
    r.display();


    // MULTILEVEL INHERITANCE
    cout<<"\n===== MULTILEVEL INHERITANCE ====="<<endl;

    Booking b;
    b.getVehicle();
    b.getType();
    b.getBooking();
    b.display();


    // MULTIPLE INHERITANCE
    cout<<"\n===== MULTIPLE INHERITANCE ====="<<endl;

    CarRental c;
    c.getCustomer();
    c.getPayment();
    c.display();


    // HIERARCHICAL INHERITANCE
    cout<<"\n===== HIERARCHICAL INHERITANCE ====="<<endl;

    cout<<"\nEnter Hatchback Details:"<<endl;
    Hatchback h;
    h.getDetails();
    h.display();

    cout<<"\nEnter SUV Details:"<<endl;
    SUV s;
    s.getDetails();
    s.display();

    return 0;
}