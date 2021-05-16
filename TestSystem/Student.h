#pragma once
#include "User.h"
#include "Question.h"
#include "Test.h"
#include "Teacher.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Student : public User
{
	int mark;
	int group;
public:
	Student();

	void setMark(int mark);
	int getMark();
	void setGroup(int group);
	int getGroup();

	int answer(Question<string>& question, string answer);
	int answer(Question<int>& question, int answer);
	void passTest(Test<string>& test, int type);
	void passTest(Test<int>& test, int type);

	friend istream& operator>>(istream& stream, Student& student);
	friend ostream& operator<<(ostream& stream, Student& student);
};