#include <iostream>
using namespace std;
#include "User.h"

bool User::login(string username, string password)
{
    if ((Security::validate(username, password) == 1) || (Security::validate(username, password) == 2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
