//
// Name Vincent Leahy
// Date 09/21/25
// Employee Class Programming Project
// COSC 2030
//

//specification file for the Employee Class
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
    private:
        string name;        //Employee name
        int idNumber;       //ID number
        string department;  //Department Name
        string position;     //Job Title

    public:
        //Constructors
        Employee(string, int, string, string);
        Employee(string, int);
        Employee();

        //Mutators
        void setName(string);
        void setIdNumber(int);
        void setDepartment(string);
        void setPosition(string);

        //Accessors
        string getName() const;
        int getIdNumber() const;
        string getDepartment() const;
        string getPosition() const;
};

#endif

//Implementation file for employee class
//#include "Employee.h"

//This constructor accepts arguiemtns for the employee name. ID #, dept, and position
Employee::Employee(string n, int id, string dept, string pos)
{
    name = n;
    idNumber = id;
    department = dept;
    position = pos;
}

//This constructor accpets arguments for the employee name and ID number
//the department and pos member vari are assigned empty strings
Employee::Employee(string n, int id)
{
    name =n;
    idNumber = id;
    department = "";
    position = "";
}

//The default construictor assigns emplty strings
//to the name dept, and posi member vari
//The idNumber member vari is assigned 0
Employee::Employee()
{
    name = "";
    idNumber = 0;
    department = "";
    position = "";
}

//Mutator function for the Name
void Employee::setName(string n)
{
    name = n;
}

//mutator function for id number
void Employee::setIdNumber(int id)
{
    idNumber = id;
}

//mutator function for the department
void Employee::setDepartment(string dept)
{
    department = dept;
}

//mutator Function for the postion
void Employee::setPosition(string pos)
{
    position = pos;
}

//Accessor function for the name
string Employee::getName() const
{
    return name;
}

//accesor function for the id number
int Employee::getIdNumber() const
{
    return idNumber;
}

//Accessor function for the department
string Employee::getDepartment() const
{
    return department;
}

//Accessor Functions for the position
string Employee::getPosition() const
{
    return position;
}

#include <iostream>
//#include "Employee.h"
using namespace std;

//function prototype
void displayEmployee(Employee);

int main()
{
    //create three employee objects
    Employee susan("Susan Meyers", 47899, "accounting", "Vice President");
    Employee mark("Mark Jones", 39119);
    Employee joy;

    //Display each employees data
    cout << "Here is each employee's data:\n";
    displayEmployee(susan);
    displayEmployee(mark);
    displayEmployee(joy);

    //Using the mutator functions to update the mark and joy objects
    mark.setDepartment("IT");
    mark.setPosition("Programmer");

    joy.setName("Joy Rogers");
    joy.setIdNumber(81774);
    joy.setDepartment("Manufacturing");
    joy.setPosition("Engineer");

    //display each employees data again
    cout << "\nEmployee data after updating:\n";
    displayEmployee(susan);
    displayEmployee(mark);
    displayEmployee(joy);

    return 0;
}

//the displayEmployee Function displays an Employee objects data
void displayEmployee(Employee e)
{
    cout << "------------------------------------------\n";
    cout << "Name: " << e.getName() << endl;
    cout << "ID Number: " << e.getIdNumber() << endl;
    cout << "Department: " << e.getDepartment() << endl;
    cout << "Position: " <<e.getPosition() << endl;
}