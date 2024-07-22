#include <iostream>
#include <string>
using namespace std;
#include "Security.h"
#include "Administrator.h"

#ifndef USER_H
#define USER_H

class User
{
public:
    bool login(string username, string password);

private:
    Security user;
};

#endif // USER_H
