#include<iostream>
#include<stack>
using namespace std;

template<class T>
T maxima(T a, T b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

