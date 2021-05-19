#pragma once
#include "User.h"
#include "Question.h"
#include "Test.h"
#include <iostream>
#include <iomanip>
using namespace std;
using namespace MyTest;

class Teacher : public User
{
public:
    void viewQuestions(Test<string>& test);
    void viewQuestions(Test<int>& test);
    void newQuestion(Test<string>& test, int type);
	void newQuestion(Test<int>& test);
    void printUser();

    friend istream& operator>>(istream& stream, Teacher& student);
    friend ostream& operator<<(ostream& stream, Teacher& student);
};

void checkAnswer(string& answer, int key);