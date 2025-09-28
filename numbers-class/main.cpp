//
// Name Vincent Leahy
// Date 9/28/2025
// Numbers Class Programming Project
// COSC 2030
//

#include <iostream>
#include <string> 

using namespace std;


class NUMBERS 
{
private:
    int number;

    // Static arrays for converting numbers to words
    static string lessThan20[20]; // numbers from 0 to 19
    static string tens[10];       // tens like twenty, thirty
    static string hundred;        // the word "hundred"
    static string thousand;       // the word "thousand"

public:
    // Constructor that takes a number
    NUMBERS(int num) 
    {
        number = num; // store the number
    }

    // prints the number in English words
    void print() 
    {
        if (number == 0) // if the number is zero
        {
            cout << "zero" << endl;
            return;
        }

        int num = number; // make a copy of the number

        // Thousands
        if (num >= 1000) 
        {
            int t = num / 1000; // get the thousands place
            cout << lessThan20[t] << " " << thousand; // print it
            num = num % 1000; // remove the thousands part
            if (num > 0) 
            {
                cout << " "; // space between words
            }
        }

        // Hundreds
        if (num >= 100) 
        {
            int h = num / 100; // get hundreds place
            cout << lessThan20[h] << " " << hundred; // print it
            num = num % 100; // remove hundreds
            if (num > 0) 
            {
                cout << " ";
            }
        }

        // For numbers less than 100
        if (num >= 20) 
        {
            int t = num / 10; // get the tens place
            cout << tens[t]; // print the tens word
            num = num % 10; // get the ones place

            if (num > 0) 
            {
                cout << " " << lessThan20[num]; // print the ones
            }

            cout << endl;
        } 
        else if (num > 0) 
        {
            cout << lessThan20[num] << endl; // print number under 20
        } 
        else 
        {
            cout << endl;
        }
    }
};

// Definitions of static arrays
string NUMBERS::lessThan20[20] = 
{
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

string NUMBERS::tens[10] = 
{
    "", "", "twenty", "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety"
};

string NUMBERS::hundred = "hundred";
string NUMBERS::thousand = "thousand";

int main() 
{
    int userInput; // store the number from user

    // ask the user for input
    cout << "Enter a number between 0 and 9999: ";
    cin >> userInput; // get the input

    // check if the input is valid
    if (userInput < 0) 
    {
        cout << "Number is too small!" << endl;
        return 1;
    }

    if (userInput > 9999) 
    {
        cout << "Number is too big!" << endl;
        return 1;
    }

    // create an object of NUMBERS
    NUMBERS myNum(userInput);

    // print the number in words
    cout << "In words: ";
    myNum.print();

    return 0;
}