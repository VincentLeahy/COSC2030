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

//Base class for general employee information
class Employee 
{
private:
    //Private member variables to hold employee data
    string name;
    string employeeNumber;
    string hireDate;

    //Private helper function to validate employee number format
    bool isValidEmpNum(const string& e) 
    {
        if (e.length() != 5) return false;

        //First 3 characters must be digits
        if (!isdigit(e[0]) || !isdigit(e[1]) || !isdigit(e[2]))
            return false;

        // Fourth character must be a dash
        if (e[3] != '-')
            return false;

        //Fifth character must be a letter between A and M
        if (toupper(e[4]) < 'A' || toupper(e[4]) > 'M')
            return false;

        return true;
    }

public:
    //Default constructor
    Employee() : name(""), employeeNumber(""), hireDate("") {}
    
    //Parameterized constructor
    Employee(string n, string num, string date) : name(n), hireDate(date) 
    {
        setEmployeeNumber(num); //Useing setter to validate the employee number
    }

    //Mutator (setter) for name
    void setName(string n) 
    {
        name = n;
    }

    //Mutator for employee number with validation
    void setEmployeeNumber(string e)
    {
        if (isValidEmpNum(e))
            employeeNumber = e;
        else
            employeeNumber = ""; //Invalid input stored as empty
    }

    //Mutator for hire date
    void setHireDate(string h) 
    {
        hireDate = h;
    }

    //Accessor (getter) for name
    string getName() const 
    {
        return name;
    }

    //Accessor for employee number
    string getEmployeeNumber() const 
    {
        return employeeNumber;
    }

    //Accessor for hire date
    string getHireDate() const 
    {
        return hireDate;
    }

    //Virtual function to print employee details
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

//Derived class for production workers, inheriting from Employee
class ProductionWorker : public Employee 
{
public:
    //Constants for shift types
    static const int DAY_SHIFT = 1;
    static const int NIGHT_SHIFT = 2;

private:
    //Private member variables specific to production workers
    int shift;         //1 for day, 2 for night
    double payRate;    //Hourly pay rate

public:
    //Default constructor
    ProductionWorker() : Employee(), shift(DAY_SHIFT), payRate(0.0) {}

    //Parameterized constructor
    ProductionWorker(string n, string num, string date, int sh, double rate)
        : Employee(n, num, date), shift(sh), payRate(rate) {}

    //Mutator for shift
    void setShift(int s) 
    {
        shift = s;
    }

    //Mutator for pay rate
    void setPayRate(double p) 
    {
        payRate = p;
    }

    //Accessor for shift
    int getShift() const 
    {
        return shift;
    }

    //Accessor for pay rate
    double getPayRate() const 
    {
        return payRate;
    }

    //Override base class print function to include shift and pay rate
    void print() const override 
    {
        //Call base class print
        Employee::print();

        //Display shift
        cout << "Shift: ";
        if (shift == DAY_SHIFT)
            cout << "Day" << endl;
        else if (shift == NIGHT_SHIFT)
            cout << "Night" << endl;
        else
            cout << "INVALID SHIFT NUMBER" << endl;

        //Display pay rate with two decimal places
        cout << fixed << setprecision(2);
        cout << "Hourly Pay Rate: $" << payRate << endl;
    }
};

//Main function to demonstrate the classes
int main() 
{
    //Make a ProductionWorker object using constructor
    ProductionWorker pw("John Smith", "123-A", "11-15-2015", ProductionWorker::DAY_SHIFT, 26.50);

    cout << "Here's the first production worker:\n";
    pw.print(); //Call print to display data
    cout << endl;

    //Make another ProductionWorker using default constructor and setters
    ProductionWorker pw2;
    pw2.setName("Joan Jones");
    pw2.setEmployeeNumber("222-L");
    pw2.setHireDate("12-12-2015");
    pw2.setShift(ProductionWorker::NIGHT_SHIFT);
    pw2.setPayRate(28.50);

    cout << "Here's the second production worker:\n";
    pw2.print(); //Display second worker data

    return 0;
}




