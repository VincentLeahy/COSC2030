//
// Name Vincent Leahy
// Date 10/19/2025
// Exception Project Programming Project
// COSC 2030
//

#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string employeeName;
    int employeeNumber;
    string hireDate;

    //member function to valudatre the eomptee number
    void checkEmployeeNumber()
    {
        if (employeeNumber < 0 || employeeNumber > 9999)
            throw InvalidEmployeeNumber();
    }

public:
    //exception class
    class InvalidEmployeeNumber {};

    //Constructor
    Employee(string name, int number, string hDate)
    {
        //set the number varible
        employeeName = name;
        employeeNumber = number;
        hireDate = hDate;

        //chekc the emploett number 
        checkEmployeeNumber();
    }

    //mutators
    void setEmployeeName(string name)
    {
        employeeName = name;
    }

    void setEmployeeNumber(int number)
    {
        employeeNumber = number;
        checkEmployeeNumber();
    }

    void setHireDate(string hDate)
    {
        hireDate = hDate;
    }

    //Accessors
    string getEmployeeName() const
    {
        return employeeName; 
    }

    int getEmployeeNumber() const
    {
        return employeeNumber;
    }

    string getHireDate()const
    {
        return hireDate;
    }

};

class ProductionWorker : public Employee
{
private:
    int shift;
    double hourlyPayRate;
    
    //Member Function to validate the shift number
    void checkShift()
    {
        if (shift < 1 || shift > 2)
            throw InvalidShift();
    }

    //Member function to validate the pay rate 
    void checkPayRate()
    {
        if (hourlyPayRate < 0)
            throw InvalidPayRate();
    }

public:
    //exception classes 
    class InvalidShift
    {};

    class InvalidPayRate
    {};

    //constructor 
    ProductionWorker(string name, int number, string hDate, int shiftNum, double payRate) : Employee(name, number, hDate)
    {
        //set the member varible
        shift = shiftNum;
        hourlyPayRate = payRate;

        //check the shift and pay rate
        checkShift();
        checkPayRate();
    }

    //Mutators
    void setShift(int shiftNum)
    {
        shift = shiftNum;
        checkShift();
    }

    void setHourlyPayRate(double payRate)
    {
        hourlyPayRate = payRate;
        checkPayRate();
    }

    //Accessors
    int getShift() const
    {
        return shift;
    }

    double getHourlyPayRate()
    {
        return hourlyPayRate;
    }
};

//Function Prototype
void testValues(string, int, string, int, double);

int main()
{
    //Test all good data
    cout << "Testing good data...\n";
    testValues("John Doe", 1234, "12/01/2009", 1, 22.50);

    //Test a bad Employee Number
    cout << "\nTesting a bad Employee number...\n";
    testValues("John Doe", -99, "12/01/2009", 1, 22.50);

    //test a bad shift number
    cout << "\nTesting a bad shift number...\n";
    testValues("John Doe", 1234, "12/01/2009", 5, 22.50);

    //Test a bad pay rate.
    cout << "\nTesting a bad pay rate...\n";
    testValues("John Doe", 1234, "12/01/20009", 1, -100.0);

    return 0;
}

void testValues(string name, int number, string hDate, int shift, double payRate)
{
    //test the InvlaidEmployeeNumber exception
    try
    {
        //create a production worker with an invaliud number
        ProductionWorker worker(name, number, hDate, shift, payRate);

        //report good date
        cout << "Good date\n";
    }
    catch (Employee::InvalidEmployeeNumber)
    {
        cout << "Invaild employee number encountered.\n";
    }
    catch (ProductionWorker::InvalidShift)
    {
        cout << "invalid shift encountered.\n";
    }
    catch (ProductionWorker::InvalidPayRate)
    {
        cout << "Invlaid pay rate encountered.\n";
    }
}