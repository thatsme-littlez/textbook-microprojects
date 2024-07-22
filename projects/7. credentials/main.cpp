// this is the application file, which demonstrates use of the program

#include <iostream>
using namespace std;
#include "Security.h"
#include "Security.cpp"
#include "Administrator.h"
#include "Administrator.cpp"
#include "User.h"
#include "User.cpp"

string username;
string password;

int main()
{
    Administrator admin;
    User user;

    cout << "Username: ";
    string username;
    cin >> username;

    cout << "Password: ";
    string password;
    cin >> password;

    if (admin.login(username, password))
    {
        cout << "Administrator login successful.\n";
    }
    else if (user.login(username, password))
    {
        cout << "User login successful.\n";
    }
    else
    {
        cout << "Login unsuccessful.\n";
    }


    return 0;
}
