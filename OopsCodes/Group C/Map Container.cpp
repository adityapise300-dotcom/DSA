#include<iostream>
#include<map>
#include<string>
using namespace std;

class Country {
    map<string, string> m;

public:

    // Add country and currency
    void addCountry() {
        m["India"] = "Rupee";
        m["USA"] = "Dollar";
        m["UK"] = "Pound";
        m["Japan"] = "Yen";
        m["China"] = "Yuan";
        m["Russia"] = "Ruble";
        m["Germany"] = "Euro";
        m["France"] = "Euro";
        m["Australia"] = "Australian Dollar";
        m["Canada"] = "Canadian Dollar";
        m["UAE"] = "Dirham";
        m["Nepal"] = "Nepalese Rupee";
        m["Bangladesh"] = "Taka";
        m["Brazil"] = "Real";
        m["South Korea"] = "Won";
    }

    // Display country-currency chart
    void display() {

        cout << "\n----- COUNTRY - CURRENCY CHART -----\n";

        cout << "\nCountry\t\tCurrency\n";
        cout << "-----------------------------------\n";

        for(auto i : m) {
            cout << i.first << "\t\t" << i.second << endl;
        }
    }
};

int main() {

    Country obj;

    obj.addCountry();

    obj.display();

    return 0;
}