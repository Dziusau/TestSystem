#pragma once
#include "Teacher.h"
#include "Student.h"
#include "Question.h"
#include "Test.h"
#include "Authorization.h"
#include <memory>

class Menu {
public:
	unique_ptr<Teacher> teacher;
	unique_ptr<Student> student;

	Menu(Teacher teacher) {
		this->teacher = make_unique<Teacher>();
		*(this->teacher) = teacher;
	}
	Menu(Student student) {
		this->student = make_unique<Student>();
		*(this->student) = student;
	}

	void menu_teacher();
	void teacher_addQuest();
	void teacher_viewQuest();
	void teacher_viewStud(int);
	void teacher_searchStud(string);
	void teacher_edit(char);
	void teacher_deleteTeach();

	void menu_student();
	void student_passTest();
	void student_edit(char);
};