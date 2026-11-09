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

        