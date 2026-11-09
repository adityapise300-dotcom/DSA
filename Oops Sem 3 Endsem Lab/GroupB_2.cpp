#include<iostream>
#include<stdexcept>
#include<string>
using namespace std;

class complex{
    float real,imag;

    public:
        complex(){
            real = 0;
            imag = 0;
        }

        friend complex operator+(complex c1,complex c2){
            complex temp;

            temp.real = c1.real + c2.real;
            temp.imag = c1.imag + c2.imag;

            return temp;
        }

        friend complex operator-(complex c1, complex c2){
            complex temp;

            temp.real = c1.real - c2.real;
            temp.imag = c1.imag - c2.imag;

            return temp;
        }

        friend complex operator*(complex c1, complex c2){
            complex temp;

            temp.real = (c1.real*c2.real) - (c1.imag*c2.imag);
            temp.imag = (c1.real*c2.imag) + (c1.imag*c2.real);

            return temp;
        }

        friend complex operator/(complex c1, complex c2){
           complex temp;

           float dinominater = (c2.real*c2.real) + (c2.imag*c2.imag);

           if(dinominater==0){
            throw runtime_error("Division by zero");
           }

           temp.real = ((c1.real*c2.real) + (c1.imag*c2.imag)) / dinominater;

           temp.imag = ((c1.imag*c2.real) - (c1.real*c2.imag)) / dinominater;

           return temp;
        }

        friend istream& operator>>(istream& in, complex& c){
            cout<<"Enter the real part: "<<endl;
            in>>c.real;

            cout<<"Enter the imaginary part: "<<endl;
            in>>c.imag;

            return in;
        }

        friend ostream& operator<<(ostream& out, complex& c){
            out<<c.real;

            if(c.imag>=0){
                out<<" + "<<c.imag<<"i";
            }else{
                out<<" - "<<-c.imag<<"i";
            }

            return out;
        }
};



int main(){
    complex c1, c2, result;

    cout<<"Enter First Complex Number:"<<endl;
    cin>>c1;

    cout<<"\nEnter Second Complex Number:"<<endl;
    cin>>c2;

    cout<<"\nFirst Complex Number: "<<c1;
    cout<<"\nSecond Complex Number: "<<c2;

    result = c1 + c2;
    cout<<"\nAddition: "<<result;

    result = c1 - c2;
    cout<<"\nSubtraction: "<<result;

    result = c1 * c2;
    cout<<"\nMultiplication: "<<result;

    try{
        result = c1 / c2;
        cout<<"\nDivision: " <<result;
    }catch(runtime_error &e){
        cout<<"\nDivision: " <<e.what();
    }

    return 0;
}