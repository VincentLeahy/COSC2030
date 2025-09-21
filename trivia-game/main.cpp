//
// Name Vincent 
// Date 09/21/25
// Trivia Game Programming Project
// COSC 2030
//

#include <iostream>
#include <string>
using namespace std;

// Question class definition
class Question 
{
private:
    string questionText;
    string answer1;
    string answer2;
    string answer3;
    string answer4;
    int correctAnswer; // 1, 2, 3, or 4

public:
    // Constructor
    Question(string q, string a1, string a2, string a3, string a4, int correct) 
    {
        questionText = q;
        answer1 = a1;
        answer2 = a2;
        answer3 = a3;
        answer4 = a4;
        correctAnswer = correct;
    }

    // Ask the question and return if answer was correct
    bool askQuestion() const 
    {
        cout << questionText << endl;
        cout << "1. " << answer1 << endl;
        cout << "2. " << answer2 << endl;
        cout << "3. " << answer3 << endl;
        cout << "4. " << answer4 << endl;
        cout << "Enter your answer (1-4): ";

        int userAnswer;
        cin >> userAnswer;

        // Simple validation
        while (userAnswer < 1 || userAnswer > 4) 
        {
            cout << "Invalid choice. Please enter 1, 2, 3, or 4: ";
            cin >> userAnswer;
        }

        if (userAnswer == correctAnswer) 
        {
            cout << "Correct!\n\n";
            return true;
        } 
        
        else 
        {
            cout << "Wrong! The correct answer was option " << correctAnswer << ".\n\n";
            return false;
        }
    }
};

int main() 
{
    const int TOTAL_QUESTIONS = 10;
    Question questions[TOTAL_QUESTIONS] = 
    {
        Question("What is the Mohs Hardness of a Diamond?", "5", "4", "6", "10", 4),
        Question("What Color does a sapphire not come in?", "Red", "Blue", "Green", "Pink", 1),
        Question("What is the alloy percentage of 24k gold?", "25%", "80%", "99.99%", "75%", 3),
        Question("What is the rarest color of Diamond", "Red", "Purple", "Pink", "Brown", 1),
        Question("What material are diamonds made of?", "Oxygen", "Carbon", "Hydrogen", "Nitrogen", 2),
        Question("Who created the 4 Cs for Diamond grading?", "DCA", "J.P Morgan", "GIA", "NDC", 3),
        Question("How many facets are in a round brillant diamond?", "100", "60", "58", "80", 3),
        Question("What is the rainbow effect from a stone called?", "Rainbow", "Sparkle", "Dispersion", "Fire", 4),
        Question("Which stone is commonly mistaken for diamond?", "CZ", "Moissanite", "White Sapphire", "White Topaz", 2),
        Question("What is the most expensive stone in the world?", "Red Diamond", "Painite", "Alexanderite", "Melo Pearl", 2)
    };

    int player1Score = 0;
    int player2Score = 0;

    cout << "Welcome to the Trivia Game!\n\n";

    // Player 1 answers questions 0-4
    cout << "--- Player 1's Turn ---\n";
    for (int i = 0; i < 5; i++) 
    {
        if (questions[i].askQuestion()) 
        {
            player1Score++;
        }
    }

    // Player 2 answers questions 5-9
    cout << "--- Player 2's Turn ---\n";
    for (int i = 5; i < 10; i++) 
    {
        if (questions[i].askQuestion()) 
        {
            player2Score++;
        }
    }

    // Final scores
    cout << "Game Over!\n";
    cout << "Player 1 Score: " << player1Score << endl;
    cout << "Player 2 Score: " << player2Score << endl;

    // Declare winner
    if (player1Score > player2Score) 
    {
        cout << "Player 1 wins!\n";
    } 
    
    else if (player2Score > player1Score) 
    {
        cout << "Player 2 wins!\n";
    } 
    
    else 
    {
        cout << "It's a tie!\n";
    }

    return 0;
}