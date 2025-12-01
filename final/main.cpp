//
// Name Vincent Leahy
// Date 11/30/2025
// Final Project
// COSC 2030
//

#include <iostream>
#include <iomanip>

using namespace std;

int main()

{
    double sales;
    double rate;
    double commission;
    double advance;
    double pay;

    //User input

    cout << "Enter the salesperson's monthly sales: ";
    cin >> sales;
    
    cout << "Enter the amount of advanced pay for this salesperson: ";
    cin >> advance;

    //Determine the commission rate

    if (sales < 10000)
        rate = 0.05;
        
    else if (sales < 15000)
        rate = 0.10;

    else if (sales < 18000)
        rate = 0.12;

    else if (sales < 22000)
        rate = 0.14;

    else    
        rate = 0.16;

    //Calculate commission and pay

    commission = sales * rate;
    pay = commission - advance;

    //Results

    cout << fixed << setprecision(2);
    cout << "\nPay Results\n";
    cout << "-------------\n";
    cout << "Sales: $" << sales << endl;
    cout << "Commission Rate: " << rate << endl;
    cout << "Commission: $" << commission << endl;
    cout << "Advance Pay: $" << advance << endl;
    cout << "Remaining Pay: $" << pay << endl;

    return 0;
}