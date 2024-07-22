// this is the header file, containing the interface for the classes Security and User

#include <iostream>
#include <string>
using namespace std;

#ifndef SECURITY_H // Check if SECURITY_H is not defined
#define SECURITY_H // Define SECURITY_H to prevent multiple inclusion

// the below subroutine hard-codes valid useers and is not considered a secure practice. It returns 0 if the credentials are invalid, 1 if valid user, and 2 if valid administrator.

class Security
{
public:
    static int validate(string username, string password);
};



#endif // SECURITY_H




