//
// Name Vincent Leahy
// Date 09/07/2025
// Movie Data Programming Project
// COSC 2030
//

#include <iostream>
#include <string>

using namespace std;

//defining the structure to hold the data regarding the movies
struct MovieData
{
    string title;
    string director;
    int yearReleased;
    int runtime;
};

//Function that will display the information
void displayMovieData(MovieData movie)
{
    cout << "Title: " << movie.title <<endl;
    cout << "Director: " << movie.director << endl;
    cout << "Year Released: " << movie.yearReleased << endl;
    cout << "Running time: " << movie.runtime << endl;
}

int main()
{
    //making the first movie data
    MovieData movie1;
    movie1.title = "Ghost in The Shell (1996)";
    movie1.director = "Mamoru Oshii";
    movie1.yearReleased = 1996;
    movie1.runtime = 83;

    //data for second movie
    MovieData movie2;
    movie2.title = "Annihilation";
    movie2.director = "Alex Garland";
    movie2.yearReleased = 2018;
    movie2.runtime = 120;

    //display the movies and their information
    cout << "Movie 1 data: " << endl;
    displayMovieData(movie1);

    cout << "Movie 2 info: " << endl;
    displayMovieData(movie2);

    return 0;
}
