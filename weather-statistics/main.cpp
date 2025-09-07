//
// Name Vincent Leahy
// Date 09/07/2025
// Weather Statistics Programming Project
// COSC 2030
//

// Weather Statistics 
#include <iostream>
using namespace std;

//declaration of the Weatherdata structure
struct WeatherData
{
    double rain;        //Tot rainfall
    double high;        //High temp
    double low;         //low temp
    double averageTemp; //average temp
};

//Function protoypes 
void getMonthData(WeatherData &);
double totalRain(WeatherData[], int);
double averageMonthlyRainfall(WeatherData[], int);
double averageAverageTemp(WeatherData[], int);
double highestTemp(WeatherData[], int, int &);
double lowestTemp(WeatherData[], int, int &);

int main()
{
    //Constant for the number of months
    const int NUM_MONTHS =12;

    //Array of WeatherData structs..
    WeatherData year[NUM_MONTHS];

    int highestMonth;       //Month with highest temp
    int lowestMonth;        //Month with lowest temp

    //Get weather data for each mnonth
    cout << "Enter the following infomration:\n";
    for (int index = 0; index < NUM_MONTHS; index++)
    {
        //Get rainfall.
        cout << "Month" << (index + 1) << endl;
        getMonthData(year[index]);
    }

    //Display total rainfall
    cout << "\nTotal Rainfall: "
         << totalRain(year, NUM_MONTHS) << endl;


    //Display average monthly rainfall
    cout << "Average Monthly Rain: "
         << averageMonthlyRainfall(year, NUM_MONTHS)
         << endl;

    //Display average of the monthly average tempratures 
    cout << "Average Monthly Average Temperature: "
         << averageAverageTemp(year, NUM_MONTHS)
         << endl;

    //Display the highest temp and the month it occured in.
    double highest = highestTemp(year, NUM_MONTHS, highestMonth);
    cout << "Highest temprature: " << highest;
    cout << "  (Month " << lowestMonth << ")\n\n";

    return 0;

}

//The getMonthData function accepts a WeatherData
//Vatiable by reference. It prompts the user for 
//Weather datra and stores the input in the argiment

void getMonthData(WeatherData &data)
{
    //Get the total rainfall for the month
    cout << "\tTotal Rainfall: ";
    cin >> data.rain;

    //Get high temp
    cout << "\tHigh Temprature: ";
    cin >> data.high;

    //Validate the high temerature.
    while (data.high < -100 || data.high > 140)
    {
        cout << "Error: Temprature must be in the range "
             << "of -100 through 140.\n";
        cout << "\tHigh Temprature: ";
        cin >> data.high;
    }

    //Get the low temp
    cout << "\tLow Temprature; ";
    cin >> data.low;

    //validate the low temp
    while (data.low < -100 || data.low > 140)
    {
        cout << "Error: Temprature must be in the range "
             << "of -100 through 140.\n";
        cout << "\tLow Temperature: ";
        cin >> data.low;
    }

    //calculate the average tempratures
    data.averageTemp = (data.high + data.low) / 2.0;
}