#include <iostream>
#include <string>
using namespace std;
#include "Security.h"

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

class Administrator
{
public:
    bool login(string username, string password);

private:
    Security administrator;
};

#endif // ADMINISTRATOR_H
