#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include "User.h"
#include "Student.h"
#include "Teacher.h"
#include "Question.h"
#include "Authorization.h"
#include "Menu.h"
#include "Test.h"

using namespace std;
using namespace MyTest;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu();
	return 0;
}