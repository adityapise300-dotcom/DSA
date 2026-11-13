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

int main(){
    cout<<"For integers(2,3), Maxima is: "<<maxima(2,3)<<endl;

    cout<<"For Floats(2.1,3.3), Maxima is: "<<maxima(2.1,3.3)<<endl;

    cout<<"For strings(apple,banana), Maxima is: "<<maxima(string("apple"),string("banana"))<<endl;

    return 0;
}