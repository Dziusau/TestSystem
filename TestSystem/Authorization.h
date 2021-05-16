#pragma once
#include "Menu.h"
#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#define cls system("cls");
#define pause system("pause");

using namespace std;

void menu();
void sign_in(string& login, string& password, int key);
void teacher_auth();
void teacher_add();
void student_auth();
void student_add();