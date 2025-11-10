//
// Name Vincent Leahy
// Date 11/09/2025
// Inventory Bin Stack Programming Project
// COSC 2030
//

#include <iostream>
using namespace std;

//Inventory Class
class Inventory
{
private:
    int serialNum;
    string manufactDate;
    int lotNum;

public:
    Inventory() { serialNum = 0; manufactDate = ""; lotNum = 0; }

    void setData(int s, string date, int lot) 
    {
        serialNum = s;
        manufactDate = date;
        lotNum = lot;
    }

    void display() const 
    {
        cout << "Serial Number: " << serialNum << endl;
        cout << "Manufacture Date: " << manufactDate << endl;
        cout << "Lot Number: " << lotNum << endl;
    }
};

//Stack Class
class InventoryStack
{
private:
    static const int MAX = 100;
    Inventory stack[MAX];
    int top;

public:
    InventoryStack() { top = -1; }

    bool isEmpty() const { return top == -1; }
    bool isFull() const { return top == MAX - 1; }

    void push(const Inventory &item) 
    {
        if (!isFull()) stack[++top] = item;
        else cout << "Stack is full! Cannot add more parts.\n";
    }

    Inventory pop() 
    {
        if (!isEmpty()) return stack[top--];
        else {
            cout << "Stack is empty! No parts to take.\n";
            Inventory empty;
            return empty;
        }
    }

    void displayAll() const 
    {
        if (isEmpty()) 
        {
            cout << "No parts left in inventory.\n";
            return;
        }
        cout << "\nParts remaining in inventory:\n";
        for (int i = top; i >= 0; i--) {
            cout << "----------------------\n";
            stack[i].display();
        }
        cout << "----------------------\n";
    }
};

//Main Program
int main()
{
    InventoryStack inventory;
    int choice;

    do {
        cout << "\nInventory Menu:\n";
        cout << "1. Add a part to inventory\n";
        cout << "2. Take a part from inventory\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) 
        {
            int serial, lot;
            string date;
            cout << "Enter Serial Number: ";
            cin >> serial;
            cout << "Enter Manufacture Date (e.g., 2025-11-09): ";
            cin >> date;
            cout << "Enter Lot Number: ";
            cin >> lot;

            Inventory part;
            part.setData(serial, date, lot);
            inventory.push(part);
            cout << "Part added to inventory.\n";
        }
        else if (choice == 2) 
        {
            if (!inventory.isEmpty()) 
            {
                Inventory part = inventory.pop();
                cout << "Part taken from inventory:\n";
                part.display();
            } 
            else

            {
                cout << "Inventory is empty.\n";
            }
        }

        else if (choice == 3) 
        
        {
            cout << "Exiting program.\n";
        }
        else 
        {
            cout << "Invalid choice. Try again.\n";
        }

    } 
    
    while (choice != 3);

    inventory.displayAll();
    return 0;
}