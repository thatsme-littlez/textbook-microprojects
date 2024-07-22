#include <iostream>
using namespace std;

int oldHours;
int minutes;

int getHours();
int getMinutes();
void twelveHour(int originalHours, int minutes, char& abbreviation);
int conversion(int originalHours, char& abbreviation);
bool repeat();

int main()
{
    do
    {
        cout << "Welcome to the time conversion program!\n";
        cout << "Please enter the time in the format of 24-hour notation.\n";
        oldHours = getHours();
        minutes = getMinutes();
        char abbreviation = '\0';
        twelveHour (oldHours, minutes, abbreviation);
    }
    while(repeat());
}

int getHours()
{
    int hours;
    cout << "Specifically, first enter the hours (a whole number between 1 and 24, inclusive): \n";
    cin >> hours;
    return hours;
}

int getMinutes()
{
    int min;
    cout << "Now, please enter the minutes (a whole number between 1 and 59, inclusive): \n";
    cin >> min;
    return min;
}

void twelveHour(int originalHours, int minutes, char& abbreviation)
{
    cout << "Here is the 12-hour notation, which was kindly converted for you from the 24-hour notation: " << conversion(originalHours, abbreviation) << ":" << minutes;
    string abbrev;
    if(abbreviation = 'A')
    {
        abbrev = "am";
    }
    else if(abbreviation = 'P')
    {
        abbrev = "pm";
    }
    cout << abbrev << endl;
}

int conversion(int originalHours, char& abbreviation)
{
    int newHour;
    if((originalHours >= 1) && (originalHours < 12))
    {
        newHour = originalHours;
        abbreviation = 'A';
    }
    else if((originalHours >= 12) && (originalHours < 24))
    {
        abbreviation = 'P';
        newHour = originalHours - 12;
    }
    return newHour;
}

bool repeat()
{
    char decision;
    cout << "Would you like to proceed with another round? (y/n)\n";
    cin >> decision;
    if(decision == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

