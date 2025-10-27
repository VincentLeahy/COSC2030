//
// Name Vincent Leahy
// Date 10/26/2025
// Course Information Programming Project
// COSC 2030
//

//this program displays information about a course.

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string courseNumber; //to hold the course number 

    //A map containg course numbers and room numbers
    map<string, string> courseRoom = { { "CS101", "3004" },{ "CS102", "4501" },
                                    { "CS103", "6755" }, { "NT110", "1234" }, { "CM241", "1411" } };

    //A map containg course number and instructors.
    map<string, string> courseInstructor = { { "CS101", "Haynes" },{ "CS102", "Alvarado" },{ "CS103", "Rich" },{ "NT110", "Burke" }, { "CM241", "Lee" } };

    //A map containing course numbers and meeting times
    map<string, string> courseTimes = { { "CS101", "8:00 A.M." },{ "CS102", "9:00 A.M." },{ "CS103", "10:00 A.M." },{ "NT110", "11:00 A.M." },{ "CM241", "1:00 P.M."} };

    //Get a course number from the user
    cout << "Enter a course number to get infomration about that course: ";
    getline(cin, courseNumber);

    //Display infomration about the couse
    if (courseRoom,count(courseNumber))
    {
        cout << "Room Number: " << courseRoom.at(courseNumber) << endl;
        cout << "Instructor: " << courseInstructor.at(courseNumber) << endl;
        cout << "Meeting time: " << courseTimes.at(courseNumber) << endl;
    }
    else
    {
        cout << "Invalid course" << endl;
    }
}