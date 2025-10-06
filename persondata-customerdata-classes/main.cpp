//
// Name Vincent Leahy
// Date 10/05/2025
// PersonData and CustomerData Classes Programming Project
// COSC 2030
//

#include <iostream>
#include <string>

using namespace std;

//Base classes for the personal data
class PersonData 
{
private:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    string zip;
    string phone;

public:
    //Setters (Mutators)
    void setLastName(string ln) { lastName = ln; }
    void setFirstName(string fn) { firstName = fn; }
    void setAddress(string addr) { address = addr; }
    void setCity(string c) { city = c; }
    void setState(string s) { state = s; }
    void setZip(string z) { zip = z; }
    void setPhone(string p) { phone = p; }

    //Getters (Accessors)
    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getAddress() const { return address; }
    string getCity() const { return city; }
    string getState() const { return state; }
    string getZip() const { return zip; }
    string getPhone() const { return phone; }
};

//Derived classes
class CustomerData : public PersonData 
{
private:
    int customerNumber;
    bool mailingList;

public:
    //Setter methods
    void setCustomerNumber(int num) { customerNumber = num; }
    void setMailingList(bool mList) { mailingList = mList; }

    //Getter methods
    int getCustomerNumber() const { return customerNumber; }
    bool getMailingList() const { return mailingList; }
};

//Main function to demonstrate usage
int main() 
{
    //Customer data object
    CustomerData customer;

    //Setting personal data (inherited from PersonData)
    customer.setFirstName("John");
    customer.setLastName("Doe");
    customer.setAddress("123 Main St");
    customer.setCity("Anytown");
    customer.setState("CA");
    customer.setZip("90210");
    customer.setPhone("555-1234");

    //Setting customer data
    customer.setCustomerNumber(1001);
    customer.setMailingList(true);

    //Displaying customer information
    cout << "Customer Information:\n";
    cout << "Name: " << customer.getFirstName() << " " << customer.getLastName() << endl;
    cout << "Address: " << customer.getAddress() << ", " << customer.getCity()
         << ", " << customer.getState() << " " << customer.getZip() << endl;
    cout << "Phone: " << customer.getPhone() << endl;
    cout << "Customer Number: " << customer.getCustomerNumber() << endl;
    cout << "On Mailing List: " << (customer.getMailingList() ? "Yes" : "No") << endl;

    return 0;
}