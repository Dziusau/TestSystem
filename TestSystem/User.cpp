#include "User.h"

int User::key = 0;

User::User()
{
	this->login = "";
	this->password = "";
}

int User::getKey() { return key; }

void User::setKey(int key) { User::key = key; }

string User::getLogin() { return login; }
string User::getPassword() { return password; }

void User::setLogin(string login) { this->login = login; }
void User::setPassword(string password) { this->password = password; }