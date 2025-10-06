//
// Name Vincent Leahy
// Date 10/05/2025
// Employee and ProductionWorker Classes Programming Project
// COSC 2030
//

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

class Employee 
{
private:
    string name;
    string employeeNumber;
    string hireDate;

    bool isValidEmpNum(const string& e) 
    {
        if (e.length() != 5) return false;

        if (!isdigit(e[0]) || !isdigit(e[1]) || !isdigit(e[2]))
            return false;
        if (e[3] != '-')
            return false;
        if (toupper(e[4]) < 'A' || toupper(e[4]) > 'M')
            return false;

        return true;
    }

public:
    // Constructors
    Employee() : name(""), employeeNumber(""), hireDate("") {}
    
    Employee(string n, string num, string date) : name(n), hireDate(date) 
    {
        setEmployeeNumber(num);
    }

    // Mutators
    void setName(string n) 
    {
        name = n;
    }

    void setEmployeeNumber(string e)
    {
        if (isValidEmpNum(e))
            employeeNumber = e;
        else
            employeeNumber = "";
    }

    void setHireDate(string h) 
    {
        hireDate = h;
    }

    // Accessors
    string getName() const 
    {
        return name;
    }

    string getEmployeeNumber() const 
    {
        return employeeNumber;
    }

    string getHireDate() const 
    {
        return hireDate;
    }

    // Display
    virtual void print() const 
    {
        cout << "Name: " << name << endl;
        cout << "Employee Number: ";
        if (employeeNumber == "")
            cout << "INVALID EMPLOYEE NUMBER" << endl;
        else
            cout << employeeNumber << endl;

        cout << "Hire Date: " << hireDate << endl;
    }
};

// Derived class
class ProductionWorker : public Employee 
{
public:
    static const int DAY_SHIFT = 1;
    static const int NIGHT_SHIFT = 2;

private:
    int shift;
    double payRate;

public:
    // Constructors
    ProductionWorker() : Employee(), shift(DAY_SHIFT), payRate(0.0) {}

    ProductionWorker(string n, string num, string date, int sh, double rate)
        : Employee(n, num, date), shift(sh), payRate(rate) {}

    // Mutators
    void setShift(int s) 
    {
        shift = s;
    }

    void setPayRate(double p) 
    {
        payRate = p;
    }

    // Accessors
    int getShift() const 
    {
        return shift;
    }

    double getPayRate() const 
    {
        return payRate;
    }

    // Display
    void print() const override 
    {
        Employee::print();
        cout << "Shift: ";
        if (shift == DAY_SHIFT)
            cout << "Day" << endl;
        else if (shift == NIGHT_SHIFT)
            cout << "Night" << endl;
        else
            cout << "INVALID SHIFT NUMBER" << endl;

        cout << fixed << setprecision(2);
        cout << "Hourly Pay Rate: $" << payRate << endl;
    }
};

//Example
int main() 
{
    ProductionWorker pw("John Smith", "123-A", "11-15-2015", ProductionWorker::DAY_SHIFT, 26.50);

    cout << "Here's the first production worker:\n";
    pw.print();
    cout << endl;

    ProductionWorker pw2;
    pw2.setName("Joan Jones");
    pw2.setEmployeeNumber("222-L");
    pw2.setHireDate("12-12-2015");
    pw2.setShift(ProductionWorker::NIGHT_SHIFT);
    pw2.setPayRate(28.50);

    cout << "Here's the second production worker:\n";
    pw2.print();

    return 0;
}




