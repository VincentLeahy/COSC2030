//
// Name Vincent Leahy
// Date 08/31/2025
// Pig Latin Programming Project
// COSC 2030
//

#include <iostream>
#include <string> //needed to use strings

using namespace std;

int main()
{
    string sentence;
    cout << "enter a sentence: ";
    getline(cin, sentence); //so users can get full sentences even spaces
    
    string word = ""; //starting with an empty word
    string pigword = ""; //this is so it is available outside of the fi block
    sentence += " "; //adding spaces to process last words

  for (int i = 0; i < sentence.length(); i++) 
  {
        char c = sentence[i];

        if (c != ' ') 
        {
            word += c;  // Build the word letter by letter
        } 
        
        else 
        {
            if (word.length() > 0) {
                // Convert the word into Pig Latin
                if (word.length() == 1) {
                    pigword = word + "ay";
                } 

                else 
                {
                    pigword = word.substr(1) + word[0] + "ay";
                }

                // Convert to lowercase
                for (int j = 0; j < pigword.length(); j++) {
                    pigword[j] = tolower(pigword[j]);
                }

                cout << pigword << " ";
                word = ""; // Reset the word for the next one
            }
        }
    }

    cout << endl;
    return 0;
}