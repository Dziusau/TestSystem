#include "User.h"

User::User(int key = 0)
{
	this->key = key;
	this->login = "";
	this->password = "";
}

int User::getKey() { return key; }

string User::getLogin() { return login; }
string User::getPassword() { return password; }

void User::setLogin(string login) { this->login = login; }
void User::setPassword(string password) { this->password = password; }