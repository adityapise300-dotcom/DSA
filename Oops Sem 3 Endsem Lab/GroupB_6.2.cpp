#include<iostream>
using namespace std;

template<class T>
class operations{
    T stack[100];
    int top = -1;
    public:
        void push(T value){
            if(top==99){
                cout<<"Stack overflow !!"<<endl;
            }else{
                top++;
                stack[top] = value;
                cout<<"Element added successfully!!"<<endl;
            }
        }

        void pop(){
            if(isempty()){
                cout<<"Stact is empty !!"<<endl;
            }else{
                cout<<"Element "<<stack[top]<<" was deleted"<<endl;
                top--;
            }
        }

        bool isempty(){
            return top==-1;
        }
};

int main(){
    operations <int> S;
    S.push(80);
    S.push(90);
    S.pop();

    return 0;
}