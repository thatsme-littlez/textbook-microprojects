// this is the implementation file of the class Security

#include <iostream>
using namespace std;
#include "Security.h"

int Security::validate(string username, string password)
{
    if ((username == "abbott") && (password == "monday"))
    {
        return 1;
    }
    else if ((username == "costello") && (password == "tuesday"))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
