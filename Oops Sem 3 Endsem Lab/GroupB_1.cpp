#include<iostream>
#include<string>
using namespace std;

class OnlinePayment
{
    public:

    // UPI Payment
    void payment(int amount, string upiID)
    {
        cout<<"\nPayment Mode: UPI"<<endl;
        cout<<"UPI ID: "<<upiID<<endl;
        cout<<"Amount Paid: Rs. "<<amount<<endl;
        cout<<"Payment Successful!"<<endl;
    }

   