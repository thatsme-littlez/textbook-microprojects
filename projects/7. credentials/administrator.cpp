#include <iostream>
using namespace std;
#include "Security.h"
#include "Administrator.h"

bool Administrator::login(string username, string password)
{
    if (Security::validate(username, password) == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
