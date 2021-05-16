#pragma once
#include <string>
using namespace std;

class User
{
    int key;
    string login;
    string password;

public:
    User(int key);

    int getKey();
    string getLogin();
    string getPassword();

    void setLogin(string login);
    void setPassword(string password);
};