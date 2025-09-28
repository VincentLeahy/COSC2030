//
// Name Vincent Leahy
// Date 08/28/2025
// NumDays Class Programming Project
// COSC 2030
//

#include <iostream>
using namespace std;

const int HOURS_PER_DAY = 8;

// Numdats class 
class NumDays
{
    private:
        double hours;
    
    public:
    //Constructor
    NumDays(double hrs)
    { hours = hrs; }

    //sethours function
    void setHours(double hrs)
    { hours = hrs; }

    //gethours function
    double getHours() const
    { return hours; }

    //getDays function
    double getDays() const
    { return hours / HOURS_PER_DAY; }

    //Overload + operator
    double operator+(const NumDays &right)
    { return hours + right.hours; }

    //overloaded - operator
    double operator-(const NumDays &right)
    { return hours - right.hours; }

    //prefix ++ operator
    double operator++()
    { return ++hours; }

    //Postfix ++ operator
    double operator++(int)
    { return hours++; }

};

int main()
{
    NumDays testA(20.0);
    NumDays testB(16.0);

    cout << "testA hours: " << testA.getHours() << endl;
    cout << "testA days: " << testA.getDays() << endl;
    cout << "-----------------------------\n";

    cout << "testB hours: " << testB.getHours() << endl;
    cout << "testB days: " << testB.getDays() << endl;
    cout << "-----------------------------\n";

    return 0;
}

int main()
{
    NumDays testA(20.0);
    NumDays testB(16.0);

    cout << "testA is set to " << testA.getHours() << endl;
    cout << "testB is set to " << testB.getHours() << endl;
    cout << "-----------------------------\n";

    cout << "The expression testA++ give us " << testA++ << endl;
    cout << "After the expression executes testB's hours are: "
         << testB.getHours() << endl;
    cout << "-----------------------------\n";

    return 0;
}

int main()
{
    NumDays testA(20.0);
    NumDays testB(16.0);

    cout << "testA = " << testA.getHours() << endl;
    cout << "testB = " << testB.getHours() << endl;
    cout << "testA + testB = " << (testA + testB) << endl;
    cout << "testA = testB = " << (testA - testB) << endl;

    return 0;
}