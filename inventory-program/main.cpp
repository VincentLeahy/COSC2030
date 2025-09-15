//
// Name Vincent Leahy
// Date 09/14/2025
// Inventory Program Programming Project
// COSC 2030
//

#include <iostream>     
#include <fstream>      
#include <string>      
using namespace std;

// Structure to store inventory item data
struct InventoryItem 
{
    string description;     // Item description
    int quantity;           // Quantity on hand
    double wholesaleCost;   // Wholesale cost
    double retailCost;      // Retail cost
    string dateAdded;       // Date added to inventory
};

// Name of the file to store records in
const string FILENAME = "inventory.txt";

// Function declarations (defined later)
void addRecord();
void displayRecord();
void editRecord();
bool isValidDate(const string& date); // Function to check date format

int main() 
{
    int choice; // User's menu choice

    // Loop to show the menu until the user chooses to exit
    do 
    {
        // Display menu
        cout << "\nInventory Menu:\n";
        cout << "1. Add New Record\n";
        cout << "2. Display Record\n";
        cout << "3. Edit Record\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline character from input buffer

        // Handling the menu choice
        switch (choice) 
        {
            case 1: addRecord(); break;     // Add a new item
            case 2: displayRecord(); break; // Show one item
            case 3: editRecord(); break;    // Edit one item
            case 4: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 4); // Keep looping until user chooses to exit

    return 0; 
}

// Function to add a new record to the file
void addRecord() 
{
    InventoryItem item;

    // Get item description
    cout << "Enter item description: ";
    getline(cin, item.description);

    // Get and validate quantity
    do 
    {
        cout << "Enter quantity on hand: ";
        cin >> item.quantity;
    } while (item.quantity < 0); // Quantity must be >= 0

    // Get and validate wholesale cost
    do 
    {
        cout << "Enter wholesale cost: ";
        cin >> item.wholesaleCost;
    } while (item.wholesaleCost < 0); // Must be >= 0

    // Get and validate retail cost
    do 
    {
        cout << "Enter retail cost: ";
        cin >> item.retailCost;
    } while (item.retailCost < 0); // Must be >= 0

    cin.ignore(); // Clear input buffer

    // Get and validate date
    do 
    {
        cout << "Enter date added (YYYY-MM-DD): ";
        getline(cin, item.dateAdded);
    } while (!isValidDate(item.dateAdded)); // Check format

    // Open file in append mode (add to end)
    ofstream file(FILENAME, ios::app);
    if (file) 
    {
        // Write each field on its own line
        file << item.description << endl;
        file << item.quantity << endl;
        file << item.wholesaleCost << endl;
        file << item.retailCost << endl;
        file << item.dateAdded << endl;
        cout << "Record added.\n";
    } 
    
    else 
    {
        cout << "Error opening file.\n";
    }
}

// Function to display a specific record from the file
void displayRecord() 
{
    ifstream file(FILENAME); // Open file for reading

    if (!file) 
    {
        cout << "No records found.\n";
        return;
    }

    int recordNumber;
    cout << "Enter record number to display (starting from 1): ";
    cin >> recordNumber;

    InventoryItem item;
    int currentRecord = 1;
    bool found = false;

    while (getline(file, item.description)) 
    {
        file >> item.quantity;
        file >> item.wholesaleCost;
        file >> item.retailCost;
        file.ignore(); // Ignore leftover newline
        getline(file, item.dateAdded);

        // Check if current record is the one the user asked for
        if (currentRecord == recordNumber) 
        {
            // Display the record
            cout << "\nRecord #" << currentRecord << ":\n";
            cout << "Description: " << item.description << endl;
            cout << "Quantity: " << item.quantity << endl;
            cout << "Wholesale Cost: " << item.wholesaleCost << endl;
            cout << "Retail Cost: " << item.retailCost << endl;
            cout << "Date Added: " << item.dateAdded << endl;
            found = true;
            break; // Stop reading file
        }
        currentRecord++;
    }

    if (!found) 
    {
        cout << "Record not found.\n";
    }
}

// Function to edit an existing record
void editRecord() 
{
    ifstream file(FILENAME); // Open file for reading

    if (!file) 
    {
        cout << "No records found.\n";
        return;
    }

    // Load all records into an array
    InventoryItem items[100]; // Can hold up to 100 records
    int count = 0;

    // Read each record from the file
    while (getline(file, items[count].description)) 
    {
        file >> items[count].quantity;
        file >> items[count].wholesaleCost;
        file >> items[count].retailCost;
        file.ignore(); // Ignore newline
        getline(file, items[count].dateAdded);
        count++; // Count how many records read
    }

    file.close(); // Close file

    int recordNumber;
    cout << "Enter record number to edit (starting from 1): ";
    cin >> recordNumber;
    cin.ignore(); // Clear input buffer

    // Check if record number is valid
    if (recordNumber < 1 || recordNumber > count) 
    {
        cout << "Invalid record number.\n";
        return;
    }

    // Reference the record to edit
    InventoryItem& item = items[recordNumber - 1];

    // Edit each field
    cout << "Editing Record #" << recordNumber << endl;

    cout << "Enter new description (" << item.description << "): ";
    getline(cin, item.description);

    do 
    {
        cout << "Enter new quantity (" << item.quantity << "): ";
        cin >> item.quantity;
    } while (item.quantity < 0);

    do 
    {
        cout << "Enter new wholesale cost (" << item.wholesaleCost << "): ";
        cin >> item.wholesaleCost;
    } while (item.wholesaleCost < 0);

    do 
    {
        cout << "Enter new retail cost (" << item.retailCost << "): ";
        cin >> item.retailCost;
    } while (item.retailCost < 0);

    cin.ignore(); // Clear buffer

    do 
    {
        cout << "Enter new date (" << item.dateAdded << "): ";
        getline(cin, item.dateAdded);
    } while (!isValidDate(item.dateAdded));

    // Rewrite the entire file with updated records
    ofstream outFile(FILENAME);
    for (int i = 0; i < count; i++) 
    {
        outFile << items[i].description << endl;
        outFile << items[i].quantity << endl;
        outFile << items[i].wholesaleCost << endl;
        outFile << items[i].retailCost << endl;
        outFile << items[i].dateAdded << endl;
    }

    cout << "Record updated.\n";
}

//function to check date is correct
bool isValidDate(const string& date) 
{
    // Very basic format check: YYYY-MM-DD (length = 10)
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    int year = stoi(date.substr(0, 4));  // Extract year
    int month = stoi(date.substr(5, 2)); // Extract month
    int day = stoi(date.substr(8, 2));   // Extract day

    // Check reasonable ranges
    if (year < 2000 || year > 2100) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    return true; // Passed all checks
}