//
// Name Vincent Leahy
// Date 11/02/2025
// Your Own Linked List Programming Project
// COSC 2030
//

#include <iostream>
using namespace std;

//Node structure
struct Node 
{
    int data;
    Node* next;
};

//Linked List class
class LinkedList 
{
private:
    Node* head;

public:
    //Constructor
    LinkedList() 
    {
        head = nullptr;
    }

    //Append a node at the end
    void append(int value) 
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) 
        {
            head = newNode;
        } 
        
        else 
        {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    //Insert a node at the beginning
    void insertAtBeginning(int value) 
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    //Delete a node by value
    void deleteNode(int value) 
    {
        if (head == nullptr) 
        {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == value) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != value) 
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) 
        {
            cout << "Value not found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    //Display all nodes
    void display() 
    {
        Node* temp = head;
        while (temp != nullptr) 
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    //Destructor to delete all nodes
    ~LinkedList() 
    {
        Node* temp = head;
        while (temp != nullptr) 
        {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
        cout << "List destroyed.\n";
    }
};

//Driver program
int main() 
{
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    cout << "List after appending nodes: ";
    list.display();

    list.insertAtBeginning(5);
    cout << "List after inserting at beginning: ";
    list.display();

    list.deleteNode(20);
    cout << "List after deleting 20: ";
    list.display();

    return 0; //Destrcutor is called here 
}