#include<iostream>
#include<stdexcept>
#include<string>
using namespace std;

class ATM{
    int pin;

    public:
        ATM(){
            pin = 1234;
        }

        void verifyPin(int entry){
            if(entry<1000 || entry>9999){
                throw invalid_argument("Please enter a 4 digit pin");
            }

            if(entry!=pin){
                throw runtime_error("Invalid Pin entry !!");
            }

            cout<<"Correct Pin Entered"<<endl;
            cout<<"welcome to the banking system"<<endl;
        }
};

int main(){
    int entry;
    ATM A;

    cout<<"Welcome to the ATM"<<endl;
    cout<<"Enter your correct pin: ";
    cin>>entry;

    try{
        A.verifyPin(entry);
    }catch(invalid_argument &e){
        cout<<"\nError: "<<e.what()<<endl;
    }catch(runtime_error &e){
        cout<<"\nError: "<<e.what()<<endl;
    }catch(...){
        cout<<"\nInvalid error occured"<<endl;
    }

    return 0;
}