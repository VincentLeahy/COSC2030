//
// Name Vincent Leahy
// Date 10/26/2025
// Unique Words Programming Project
// COSC 2030
//

#include <iostream>   
#include <fstream>    //to read files
#include <set>        //to store unique words
#include <string>    

using namespace std;

int main() 
{
    string filename;   //variable to hold the file name
    cout << "Enter the name of the text file: ";
    cin >> filename;   //user types: Kennedy.txt

    ifstream file(filename); //open the file for reading

    // heck if the file opened correctly
    if (!file.is_open()) 
    {
        cout << "Error: Could not open file." << endl;
        return 1; //stop the program if file not found
    }

    set<string> uniqueWords; //creates a set that only keeps unique words
    string word;             //holds each word read from the file

    //ead one word at a time from the file
    while (file >> word) 
    {
        uniqueWords.insert(word); //add the word to the set
    }

    //close the file when done
    file.close();

    //show all the unique words
    cout << "\nUnique words found in the file:\n";
    for (const string& w : uniqueWords) 
    {
        cout << w << endl;
    }

    return 0;
}