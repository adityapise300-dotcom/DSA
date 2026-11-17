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

    // Card Payment
    void payment(int amount, long long cardNo, string name)
    {
        cout<<"\nPayment Mode: Debit/Credit Card"<<endl;
        cout<<"Card Holder: "<<name<<endl;
        cout<<"Card Number: "<<cardNo<<endl;
        cout<<"Amount Paid: Rs. "<<amount<<endl;
        cout<<"Payment Successful!"<<endl;
    }

    // Net Banking Payment
    void payment(int amount, string bank, string account)
    {
        cout<<"\nPayment Mode: Net Banking"<<endl;
        cout<<"Bank Name: "<<bank<<endl;
        cout<<"Account Number: "<<account<<endl;
        cout<<"Amount Paid: Rs. "<<amount<<endl;
        cout<<"Payment Successful!"<<endl;
    }
};

int main()
{
    OnlinePayment obj;

    int choice, amount;

    cout<<"===== ONLINE SHOPPING PAYMENT ====="<<endl;

    cout<<"Enter Order Amount: ";
    cin>>amount;

    cout<<"\nSelect Payment Method:"<<endl;
    cout<<"1. UPI Payment"<<endl;
    cout<<"2. Card Payment"<<endl;
    cout<<"3. Net Banking"<<endl;

    cout<<"Enter your choice: ";
    cin>>choice;

    if(choice == 1)
    {
        string upi;
        cout<<"Enter UPI ID: ";
        cin>>upi;

        obj.payment(amount, upi);
    }

    else if(choice == 2)
    {
        long long card;
        string name;

        cout<<"Enter Card Number: ";
        cin>>card;

        cout<<"Enter Card Holder Name: ";
        cin>>name;

        obj.payment(amount, card, name);
    }

    else if(choice == 3)
    {
        string bank, account;

        cout<<"Enter Bank Name: ";
        cin>>bank;

        cout<<"Enter Account Number: ";
        cin>>account;

        obj.payment(amount, bank, account);
    }

    else
    {
        cout<<"Invalid Choice!"<<endl;
    }

    return 0;
}
