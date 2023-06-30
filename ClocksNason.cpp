/*  
Created By Darren Nason
Project chada Clock
CS - 210
insert Date here
*/

// grabbing the C++ libraries for the program
#include <iostream>
#include <ctime>
#include <string>

using namespace std;
string asterisks(13, '*');
string asterisk(1, '*');

// Function for user to add one hour to both clocks
void addOneHour(struct tm *timeInfo) 
{
    timeInfo->tm_hour += 1;
    mktime(timeInfo);
}
// Function for user to add one minute to both clocks
void addOneMinute(struct tm *timeInfo) 
{
    timeInfo->tm_min += 1;
    mktime(timeInfo);
}
// Function for user to add one second to both clocks
void addOneSecond(struct tm *timeInfo) 
{
    timeInfo->tm_sec += 1;
    mktime(timeInfo);
}
// Function to grab local time from client computer and display both 12-24 hour clocks
void displayTime(struct tm *timeInfo) 
{
    string aMpM;
    // giving both variables plenty of space to handle overflow
    char militaryTime[80];
    char standardTime[80];

    // Setting the format for both clocks
    strftime(militaryTime, sizeof(militaryTime), "%H:%M:%S", timeInfo);
    strftime(standardTime, sizeof(standardTime), "%I:%M:%S %p", timeInfo);

    // formatting to display only the time without the date
    string timeOnly = standardTime;
    timeOnly = timeOnly.substr(0,12);

    // displaying both clocks with proper asterisks and spacing format
    cout << asterisks << asterisks <<  "\t" << asterisks << asterisks << endl;
    cout << asterisk << "     " << "12-Hour Clock\t " << asterisk << "\t" << asterisk << "\t" << "24-Hour Clock" << "    " << asterisk << endl;
    cout << asterisk << "     " << timeOnly << " " << aMpM << "       " <<  asterisk << "\t" << asterisk << "\t  " << militaryTime << "       " << asterisk << endl;
    cout << asterisks << asterisks <<  "\t" << asterisks << asterisks << endl;

}
// Function to display program menu
void displayMenu()
{
cout << "\t" << "\t " << asterisks << asterisks << endl;
cout << "\t" << "\t " << asterisk << " 1 - Add One Hour" << "\t" << "  " << asterisk << endl;
cout << "\t" << "\t " << asterisk << " 2 - Add One Minute" << "\t" << "  " << asterisk << endl;
cout << "\t" << "\t " << asterisk << " 3 - Add One Second" << "\t" << "  " << asterisk << endl;
cout << "\t" << "\t " << asterisk << " 4 - Exit Program" << "\t" << "  " << asterisk << endl;
cout << "\t" << "\t " << asterisks << asterisks << endl;
}
// Main function
int main()
{
    char userInput;
    bool keepUsing = true;
    time_t currentTime = time(0);
    struct tm* now = localtime(&currentTime);

    displayTime(now);
    cout << endl << endl;
// Loop for program to display and update both clocks according to user input
while (keepUsing)
{
    displayMenu();
    cout << endl << endl;
    cout << "Enter Selection here: ";
    cin >> userInput;
// Switch statement to direct program for desired output along with input validation
    switch (userInput)
    {
        case '1': 
            addOneHour(now);
            system("clear");
            displayTime(now);
            break;
        case '2':
            addOneMinute(now);
            system("clear");
            displayTime(now);
            break;
        case '3':
            addOneSecond(now);
            system("clear");
            displayTime(now);
            break;
        case '4':
            keepUsing = false;
            break;
            default:
                system("clear");
                cout << "Invalid Input. Use num keys 1-4" << endl;
                break;
        }
    }
}
