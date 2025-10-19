//
// Name Vincent Leahy
// Date 10/19/2025
// Exception Project Programming Project
// COSC 2030
//

#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
using namespace std;

// ===== Exception Classes =====
class InvalidEmployeeNumber : public runtime_error 
{
public:
    InvalidEmployeeNumber() : runtime_error("Error: Invalid Employee Number!") {}
};

class InvalidShift : public runtime_error 
{
public:
    InvalidShift() : runtime_error("Error: Invalid Shift! Must be 1 (Day) or 2 (Night).") {}
};

class InvalidPayRate : public runtime_error 
{
public:
    InvalidPayRate() : runtime_error("Error: Invalid Pay Rate! Cannot be negative.") {}
};

//Employee Class
class Employee {
private:
    string name;
    int employeeNumber;
    string hireDate;

public:
    Employee() : name(""), employeeNumber(0), hireDate("") {}

    Employee(string n, int num, string date) : name(n), hireDate(date) {
        setEmployeeNumber(num);
    }

    void setName(string n) { name = n; }

    void setEmployeeNumber(int num) 
    {
        if (num < 0 || num > 9999)
            throw InvalidEmployeeNumber();
        employeeNumber = num;
    }

    void setHireDate(string h) { hireDate = h; }

    string getName() const { return name; }
    int getEmployeeNumber() const { return employeeNumber; }
    string getHireDate() const { return hireDate; }

    virtual void print() const 
    {
        cout << "Name: " << name << endl;
        cout << "Employee Number: " << employeeNumber << endl;
        cout << "Hire Date: " << hireDate << endl;
    }
};

//ProductionWorker Class
class ProductionWorker : public Employee 
{
public:
    static const int DAY_SHIFT = 1;
    static const int NIGHT_SHIFT = 2;

private:
    int shift;
    double payRate;

public:
    ProductionWorker() : Employee(), shift(DAY_SHIFT), payRate(0.0) {}

    ProductionWorker(string n, int num, string date, int sh, double rate)
        : Employee(n, num, date) 
        
        {
        setShift(sh);
        setPayRate(rate);
    }

    void setShift(int s) 
    {
        if (s != DAY_SHIFT && s != NIGHT_SHIFT)
            throw InvalidShift();
        shift = s;
    }

    void setPayRate(double p) 
    {
        if (p < 0)
            throw InvalidPayRate();
        payRate = p;
    }

    int getShift() const { return shift; }
    double getPayRate() const { return payRate; }

    void print() const override 
    {
        Employee::print();
        cout << "Shift: " << (shift == DAY_SHIFT ? "Day" : "Night") << endl;
        cout << "Hourly Pay Rate: $" << fixed << setprecision(2) << payRate << endl;
    }
};

// ===== main() Demonstration =====
int main() 
{
    try 
    {
        cout << "Creating employee with invalid number...\n";
        Employee e1("John Smith", -10, "10-19-2025");
    }
    catch (InvalidEmployeeNumber &ex) 
    
    {
        cout << ex.what() << endl;
    }

    try 
    {
        cout << "\nCreating production worker with invalid shift...\n";
        ProductionWorker pw1("Jane Doe", 1234, "10-19-2025", 3, 25.00);
    }
    catch (InvalidShift &ex) 
    
    {
        cout << ex.what() << endl;
    }

    try 
    {
        cout << "\nCreating production worker with invalid pay rate...\n";
        ProductionWorker pw2("Bob Jones", 5678, "10-19-2025", ProductionWorker::DAY_SHIFT, -5.00);
    }
    catch (InvalidPayRate &ex) 
    
    {
        cout << ex.what() << endl;
    }

    cout << "\nNow let's create a valid production worker:\n";
    try 
    {
        ProductionWorker pw3("Sally Smith", 2222, "10-19-2025", ProductionWorker::NIGHT_SHIFT, 22.50);
        pw3.print();
    }
    catch (exception &ex) 
    
    {
        cout << ex.what() << endl;
    }

    return 0;
}