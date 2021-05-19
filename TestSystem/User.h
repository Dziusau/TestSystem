#pragma once
#include <string>
using namespace std;

class User
{
    static int key;
    string login;
    string password;

public:
    User();

    static int getKey();
    static void setKey(int key);
    string getLogin();
    string getPassword();

    void setLogin(string login);
    void setPassword(string password);

    virtual void printUser() = 0;
};