//
// Name Vincent Leahy
// Date 10/19/2025
// TestScores Class Programming Project
// COSC 2030
//

#include <iostream>
#include <iomanip>
using namespace std;

//Simple Exception Class
class InvalidTestScore
{
    //Empty class — just a type to throw and catch
};

//TestScores Class
class TestScores
{
private:
    double *scores; //pointer to hold scores
    int size;       //number of test scores

public:
    //Constructor
    TestScores(double s[], int arraySize)
    {
        size = arraySize;
        scores = new double[size];

        //Copy and validate each score
        for (int i = 0; i < size; i++)
        {
            if (s[i] < 0 || s[i] > 100)
            {
                delete[] scores; //clean up memory before throwing
                throw InvalidTestScore(); //throw simple exception
            }
            scores[i] = s[i];
        }
    }

    //Destructor
    ~TestScores()
    {
        delete[] scores;
    }

    //Function to get average
    double getAverage() const
    {
        double total = 0.0;
        for (int i = 0; i < size; i++)
            total += scores[i];
        return total / size;
    }
};

//Main Function
int main()
{
    cout << fixed << setprecision(2);

    //Valid scores example
    try
    {
        double goodScores[5] = {90, 85, 78, 92, 88};
        TestScores student1(goodScores, 5);
        cout << "Average score (valid): " << student1.getAverage() << endl;
    }
    catch (InvalidTestScore)
    {
        cout << "Error: One or more test scores are invalid!" << endl;
    }

    cout << endl;

    //Invalid scores example (negative number)
    try
    {
        double badScores[5] = {100, 95, -5, 88, 92};
        TestScores student2(badScores, 5);
        cout << "Average score (invalid): " << student2.getAverage() << endl;
    }
    catch (InvalidTestScore)
    {
        cout << "Error: One or more test scores are invalid!" << endl;
    }

    cout << endl;

    //Another invalid example (too high)
    try
    {
        double tooHigh[3] = {120, 80, 90};
        TestScores student3(tooHigh, 3);
        cout << "Average score (invalid): " << student3.getAverage() << endl;
    }
    catch (InvalidTestScore)
    {
        cout << "Error: One or more test scores are invalid!" << endl;
    }

    return 0;
}