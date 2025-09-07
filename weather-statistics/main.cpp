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

//The totalRain function accepsts an array of WeatherData
//Structures and resturns the total of all the elements
//rain members

double totalRain(WeatherData data[], int size)
{
    double totalRain = 0; // Accumulator

    //get the total of the rain members
    for (int index = 0; index < size; index++)
        totalRain += data[index].rain;

    //return the total
    return totalRain;
}

//the averageMontlyRainfall fuinction accepts an arry
//of weather structures and returns the average
//monthly rainfall

double averageMonthlyRainfall(WeatherData data [], int size)
{
    //the average is the total amount of rain divided by the number of months
    return totalRain(data, size) / size;
}

//averageAverageTemp function accpets an array of WeatherData structs and reuntrs the average of all
//the monthly average tempratures

double averageAverageTemp(WeatherData data [], int size)
{
    //calcualte the average monthly average temprature
    double aveTotal = 0;    //Accumulator for average tmeps
    double aveAve;          //average of the averagfes

    //get the total of the average temperatures
    for (int index = 1; index < size; index++)
        aveTotal += data[index].averageTemp;

    //return the average of the averages
    return aveAve;
}

//The highestTemp function accepts
// a weatherdata array, int indicatting the sieze of the array, in by reference to hold the month with the highest temp.
//The funct retrns the hgsts temp and sets the mnth parameter to number of the mnth w/ hghtemp.

double highestTemp(WeatherData data[], int size, int &month)
{
    //set the highest to the first month
    double highest = data[0].high;

    //step though the array lookin for the highest
    for (int index =1; index < size; index++)
    {
        if (data[index].high > highest)
        {
            //save this value. it is the highest so far.
            highest = data[index].high;

            //save this months number. (1 = jan, etc)
            month = index + 1;
        }
    }

    //return the highest temprature
    return highest;
}

//lowest function accepts
// a weatherdata array, int indicatting the sieze of the array, in by reference to hold the month with the lowest temp.
//The funct retrns the hgsts temp and sets the mnth parameter to number of the mnth w/ lowest temp.

double lowestTemp(WeatherData data[], int size, int &month)
{
    //set the lowest to the first month
    double lowest = data[0].low;

    //step though the array lookin for the highest
    for (int index =1; index < size; index++)
    {
        if (data[index].low > lowest)
        {
            //save this value. it is the highest so far.
            lowest = data[index].low;

            //save this months number. (1 = jan, etc)
            month = index + 1;
        }
    }

    //return the highest temprature
    return lowest;