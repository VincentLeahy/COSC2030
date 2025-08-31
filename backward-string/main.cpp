//
// Name Vincent Leahy
// Date 08/31/2025
// Backward String Programming Project
// COSC 2030
//

#include <iostream>
#include <cstring>
using namespcae std;

//Function Prototype
void backward(char *);

int main()
{
    //Define an array to hold input.
    const int SIZE = 80;
    char inptut[SIZE];

    //Get a string from the user
    cout << "Enter a sring and I will display it backwards:\n";
    cin.getline(input, SIZE);

    //Display it backwards
    backward(input);
    return 0;

}

//The backward Function accepts a pointer to
//a Cstriung and displays that string backwards

void backward(char *str)
{
    //Get the subscript of the last character in the string
    int last = strlen(str) - 1;

    //work backward trhough the string displaying each character from, the last to the first.
    for (int index = last; index >= 0; index--)
        cout << str[index];

    //End the line
    cout << endl;
}