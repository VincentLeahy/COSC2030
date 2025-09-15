//
// Name Vincent Leahy
// Date 09/14/2025
// File Encryption Programming Project
// COSC 2030
//

//File encryption Filter 
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputFile; //input file object
    ofstream outputFile; //output file object

    string inFileName; //input file name
    string outFileName; //output file name 
    char data;          //To hold a character of data

    //get the input file name
    cout << "Enter the input file name: ";
    getline(cin, inFileName);

    //Get the output file name
    cout << "Enter the output file name: ";
    getline(cin, outFileName);

    //Open the files
    inputFile.open(inFileName.c_str());
    outputFile.open(outFileName.c_str());

    //Read the first character from the input file
    inputFile.get(data);

    //Read the contet of the input file, one character at a time, encrypt it, and store it in the output file
    while (inputFile)
    {
        //Encrypt the character by adding 10 to it.
        data += 10;

        //Write the chacter to output file
        outputFile.put(data);

        //Get the next character from inputFile
        inputFile.get(data);
    }
    cout << "The file has been encrypted.\n";

    //close both files
    inputFile.close();
    outputFile.close();

    return 0;
}