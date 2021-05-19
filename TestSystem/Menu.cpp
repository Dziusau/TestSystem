#include "Menu.h"

void Menu::menu_teacher()
{
	while (true) {
		cls;
		cout << "�������� ��������:" << endl;
		cout << "1 - �������� ������" << endl;
		cout << "2 - ����������� ��� �������" << endl;
		cout << "3 - ����������� ������ ���������" << endl;
		cout << "4 - ����� ��������" << endl;
		cout << "5 - �������� �����/������" << endl;
		cout << "6 - ������� �������� ������������" << endl;
		cout << "default - �����" << endl;
		switch (_getch()) {
		case '1':
		{
			while (true) {
				cls;
				Menu::teacher_addQuest();
				cout << "�������� ��� ����?(�/�)" << endl;  char c = _getch();
				if (c != '�' && c != '�') break;
			}
			break;
		}
		case '2':
		{
			cls;
			Menu::teacher_viewQuest();
			pause;
			break;
		}
		case '3':
		{
			cls;
			cout << "�������� �������:" << endl;
			cout << "1 - �����������" << endl;
			cout << "2 - �����������" << endl;
			cout << "default - ������� ����" << endl << endl;
			int f = _getch() - 48;
			if (f == 1) {
				cout << "����������� ��:" << endl;
				cout << "1 - �������" << endl;
				cout << "2 - �������" << endl;
				int c = _getch() - 48;
				f += c * 10;
			}
			else if (f == 2) {
				cout << endl << "����������� ��:" << endl;
				cout << "1 - ������ ���������" << endl;
				cout << "2 - �������" << endl;
				cout << "default - �������" << endl << endl;
				int c = _getch() - 48;
				if (c != 1 && c != 2) c = 0;
				f += c;
			}
			else f = 0;
			Menu::teacher_viewStud(f);
			pause;
			break;
		}
		case '4':
		{
			cls;
			string stud_login;
			cout << "������� ��� ��������: " << endl;
			getline(cin, stud_login);
			Menu::teacher_searchStud(stud_login);
			pause;
			break;
		}
		case '5':
		{
			cls;
			(*teacher).printUser();
			cout << "��������:" << endl;
			cout << "1 - �����" << endl;
			cout << "2 - ������" << endl;
			cout << "default - ����� � ������" << endl << endl;
			Menu::teacher_edit(_getch());
			pause;
			break;
		}
		case '6':
		{
			cout << endl << "�� �������?(�/�)" << endl; char c = _getch();
			if (c == '�' || c == '�') break;
			else {
				Menu::teacher_deleteTeach();
				pause;
				return;
			}
		}
		default:
			return;
		}
	}
}

void Menu::teacher_addQuest()
{
	cout << "�������� ��� �������:" << endl;
	cout << "1 - ����������" << endl;
	cout << "2 - ��������" << endl;
	cout << "default - � ���������� ������" << endl;
	int type = _getch() - 48;
	if (type != 1 && type != 2) type = 0;
	Test<string> test_str(1);
	Test<int> test_int(0);
	switch (type)
	{
	case 1: case 2:
		(*teacher).newQuestion(test_str, type);
		break;
	default:
		(*teacher).newQuestion(test_int);
		break;
	}
}

void Menu::teacher_viewQuest()
{
	Test<string> test_str(1);
	Test<int> test_int(0);

	(*teacher).viewQuestions(test_str);
	(*teacher).viewQuestions(test_int);
}

void Menu::teacher_viewStud(int key)
{
	try {
		vector<Student> file_students;
		Student temp_stud;
		int m;

		ifstream file_in("files/students.txt");
		if (!file_in.is_open()) throw "���� �� ������!";
		switch (key)
		{
		case 0: {
			while (true) {
				file_in >> temp_stud;

				if (file_in.eof()) break;
				else file_students.push_back(temp_stud);
			}
			file_in.close();
			if (file_students.empty()) throw "��� ������������������ ���������!";

			cout.setf(ios::left);
			cout << setw(20) << "���" << setw(7) << "������" << "������" << endl;
			for (auto i : file_students) cout << i << endl;
			break;
		}
		case 2: {
			while (true) {
				file_in >> temp_stud;

				if (file_in.eof()) break;
				else file_students.push_back(temp_stud);
			}
			file_in.close();
			if (file_students.empty()) throw "��� ������������������ ���������!";

			cout << "�����������:" << endl;
			cout << "1 - �� �����������" << endl;
			cout << "default - �� ��������" << endl << endl;
			if (_getch() == '1') {
				for (int j = 0; j < file_students.size() - 1; j++) {
					m = j;
					for (int i = j + 1; i < file_students.size(); i++)
						if (file_students[i].getMark() < file_students[m].getMark()) m = i;
					temp_stud = file_students[m];
					file_students[m] = file_students[j];
					file_students[j] = temp_stud;
				}
			}
			else {
				for (int j = 0; j < file_students.size() - 1; j++) {
					m = j;
					for (int i = j + 1; i < file_students.size(); i++)
						if (file_students[i].getMark() > file_students[m].getMark()) m = i;
					temp_stud = file_students[m];
					file_students[m] = file_students[j];
					file_students[j] = temp_stud;
				}
			}

			cout.setf(ios::left);
			cout << setw(20) << "���" << setw(7) << "������" << "������" << endl;
			for (auto i : file_students) cout << i << endl;
			break;
		}
		case 3: {
			while (true) {
				file_in >> temp_stud;

				if (file_in.eof()) break;
				else file_students.push_back(temp_stud);
			}
			file_in.close();
			if (file_students.empty()) throw "��� ������������������ ���������!";

			cout << "�����������:" << endl;
			cout << "1 - �� �����������" << endl;
			cout << "default - �� ��������" << endl;
			if (_getch() == '1') {
				for (int j = 0; j < file_students.size() - 1; j++) {
					m = j;
					for (int i = j + 1; i < file_students.size(); i++)
						if (file_students[i].getLogin() < file_students[m].getLogin()) m = i;
					temp_stud = file_students[m];
					file_students[m] = file_students[j];
					file_students[j] = temp_stud;
				}
			}
			else {
				for (int j = 0; j < file_students.size() - 1; j++) {
					m = j;
					for (int i = j + 1; i < file_students.size(); i++)
						if (file_students[i].getLogin() > file_students[m].getLogin()) m = i;
					temp_stud = file_students[m];
					file_students[m] = file_students[j];
					file_students[j] = temp_stud;
				}
			}

			cout.setf(ios::left);
			cout << setw(20) << "���" << setw(7) << "������" << "������" << endl;
			for (auto i : file_students) cout << i << endl;
			break;
		}
		case 4: {
			while (true) {
				file_in >> temp_stud;

				if (file_in.eof()) break;
				else file_students.push_back(temp_stud);
			}
			file_in.close();
			if (file_students.empty()) throw "��� ������������������ ���������!";

			cout << "�����������:" << endl;
			cout << "1 - �� �����������" << endl;
			cout << "default - �� ��������" << endl;
			if (_getch() == '1') {
				for (int j = 0; j < file_students.size() - 1; j++) {
					m = j;
					for (int i = j + 1; i < file_students.size(); i++)
						if (file_students[i].getGroup() < file_students[m].getGroup()) m = i;
					temp_stud = file_students[m];
					file_students[m] = file_students[j];
					file_students[j] = temp_stud;
				}
			}
			else {
				for (int j = 0; j < file_students.size() - 1; j++) {
					m = j;
					for (int i = j + 1; i < file_students.size(); i++)
						if (file_students[i].getGroup() > file_students[m].getGroup()) m = i;
					temp_stud = file_students[m];
					file_students[m] = file_students[j];
					file_students[j] = temp_stud;
				}
			}

			cout.setf(ios::left);
			cout << setw(20) << "���" << setw(7) << "������" << "������" << endl;
			for (auto i : file_students) cout << i << endl;
			break;
		}
		case 11: {
			int group;
			while (true) {
				cout << "������� ����� ������: ";
				cin >> group;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(10, '\n');
					cout << "������������ ����. ����������, ���������� ���.\n" << endl;
					continue;
				}
				break;
			}

			while (true) {
				file_in >> temp_stud;

				if (file_in.eof()) break;
				else if (temp_stud.getGroup() == group)
					file_students.push_back(temp_stud);
			}
			file_in.close();

			if (file_students.empty()) throw "��������� ����� ������ ���!";
			cout.setf(ios::left);
			cout << endl << setw(20) << "���" << setw(7) << "������" << "������" << endl;
			for (auto i : file_students) cout << i << endl;
			break;
		}
		case 21: {
			int mark;
			while (true) {
				cout << "������� ������: ";
				cin >> mark;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(10, '\n');
					cout << "������������ ����. ����������, ���������� ���.\n" << endl;
					continue;
				}
				else if (mark < 0 || mark > 10) {
					cout << "������������ ����. ����������, ���������� ���.\n" << endl;
					continue;
				}
				break;
			}

			while (true) {
				file_in >> temp_stud;

				if (file_in.eof()) break;
				else if (temp_stud.getMark() == mark)
					file_students.push_back(temp_stud);
			}
			file_in.close();

			if (file_students.empty()) throw "��������� c ����� ������� ���!";
			else {
				cout.setf(ios::left);
				cout << endl << setw(20) << "���" << setw(7) << "������" << "������" << endl;
				for (auto i : file_students) cout << i << endl;
			}
			break;
		}
		}
	}
	catch (const char* ex) {
		cout << endl << ex << endl;
	}
}

void Menu::teacher_searchStud(string login)
{
	try {
		Student temp_stud;
		bool check = false;

		ifstream file_in("files/students.txt");
		if (!file_in.is_open()) throw "���� �� ������!";
		while (true) {
			file_in >> temp_stud;

			if (file_in.eof()) break;
			else if (temp_stud.getLogin() == login) {
				check = true;
				break;
			}
		}
		file_in.close();
		if (!check) throw "�������� � ����� ������ ���!";

		cout.setf(ios::left);
		cout << setw(20) << "���" << setw(7) << "������" << "������" << endl;
		cout << temp_stud << endl;
	}
	catch (const char* ex) {
		cout << endl << ex << endl;
	}
}

void Menu::teacher_edit(char key)
{
	vector<string> file_logins;
	vector<string> file_passwords;
	string login;
	string password;
	try {
		ifstream file_in("files/teachers.txt");
		if (!file_in.is_open()) throw "���� �� ������!";

		while (!file_in.eof()) {
			getline(file_in, login);
			if (login.empty()) break;
			file_logins.push_back(login);

			getline(file_in, password);
			file_passwords.push_back(password);
		}
		file_in.close();

		ofstream file_out("files/teachers.txt", ios::trunc);
		if (!file_out.is_open()) throw "���� �� ������!";

		if (key == '1') {
			cout << "������� ����� �����: ";
			//cin.ignore(10, '\n');
			getline(cin, login);

			for (auto i : file_logins) {
				if (i == login) {
					file_out.close();
					throw false;
				}
			}

			for (int i = 0; i < file_logins.size(); i++) {
				if (file_logins[i] == (*teacher).getLogin()) {
					file_logins[i] = login;
					(*teacher).setLogin(login);
					break;
				}
			}
			for (int i = 0; i < file_logins.size(); i++)
				file_out << file_logins[i] << "\n" << file_passwords[i] << "\n";
		}
		else if (key == '2') {
			password.clear();
			//cin.ignore(10, '\n');
			char c;
			cout << "������� ����� ������: ";
			while ((c = _getch()) != '\r') {
				password += c;
				cout << '*';
			}
			cout << endl;

			(*teacher).setPassword(password);
			for (int i = 0; i < password.size(); i++) password[i] += 6;

			for (int i = 0; i < file_logins.size(); i++) {
				if (file_logins[i] == (*teacher).getLogin()) {
					file_passwords[i] = password;
					break;
				}
			}
			for (int i = 0; i < file_logins.size(); i++)
				file_out << file_logins[i] << "\n" << file_passwords[i] << "\n";
		}
		else {
			char c;
			cout << "������� ����� �����: ";
			getline(cin, login);

			for (auto i : file_logins) {
				if (i == login) {
					file_out.close();
					throw false;
				}
			}

			password.clear();
			cout << "������� ����� ������: ";
			while ((c = _getch()) != '\r') {
				password += c;
				cout << '*';
			}
			cout << endl;

			(*teacher).setPassword(password);
			for (int i = 0; i < password.size(); i++) password[i] += 6;

			for (int i = 0; i < file_logins.size(); i++) {
				if (file_logins[i] == (*teacher).getLogin()) {
					file_logins[i] = login;
					file_passwords[i] = password;
					(*teacher).setLogin(login);
					(*teacher).setPassword(password);
					break;
				}
			}
			for (int i = 0; i < file_logins.size(); i++)
				file_out << file_logins[i] << "\n" << file_passwords[i] << "\n";
		}
		cout << "������������ ��������." << endl;
		file_out.close();
	}
	catch (const char* ex) {
		cout << endl << ex << endl;
	}
	catch (bool) {
		cout << endl << "���� ����� ��� ������������!" << endl;
		ofstream file_out("files/teachers.txt", ios::trunc);
		for (int i = 0; i < file_logins.size(); i++)
			file_out << file_logins[i] << "\n" << file_passwords[i] << "\n";
		file_out.close();
	}
}

void Menu::teacher_deleteTeach()
{
	try {
		vector<Teacher> file_teachers;
		Teacher temp_teacher;

		ifstream file_in("files/teachers.txt");
		if (!file_in.is_open()) throw "���� �� ������!";

		while (true) {
			file_in >> temp_teacher;

			if (file_in.eof()) break;
			else if (temp_teacher.getLogin() != (*teacher).getLogin())
				file_teachers.push_back(temp_teacher);
		}
		file_in.close();

		ofstream file_out("files/teachers.txt", ios::trunc);
		if (!file_out.is_open()) throw "���� �� ������!";

		for (auto i : file_teachers) file_out << i;
		cout << "������������ ������� ������." << endl;
	}
	catch (const char* ex) {
		cout << endl << ex << endl;
	}
}

void Menu::menu_student()
{
	while (true) {
		cls;
		cout << "�������� ��������:" << endl;
		cout << "1 - ������� � ������� �����" << endl;
		cout << "2 - ����������� ������ ���������� ������������" << endl;
		cout << "3 - �������� �����/����� ������" << endl;
		cout << "default - �����" << endl;
		switch (_getch()) {
		case '1':
		{
			Menu::student_passTest();
			break;
		}
		case '2':
		{
			cls;
			cout.setf(ios::left);
			cout << setw(20) << "���" << setw(7) << "������" << "������" << endl;
			cout << student << endl;
			pause;
			break;
		}
		case '3':
		{
			cls;
			cout << "������� �����: " << (*student).getLogin() << endl;
			cout << "������� ����� ������: " << (*student).getGroup() << endl << endl;
			cout << "��������:" << endl;
			cout << "1 - �����" << endl;
			cout << "2 - ����� ������" << endl;
			cout << "default - ����� � ������" << endl << endl;
			char c = _getch();
			if (c != '1' && c != '2') c = '0';
			Menu::student_edit(c);
			pause;
			break;
		}
		default:
			return;
		}
	}
}

void Menu::student_passTest()
{
	cls;
	cout << "�������� ������� ��������� �����:" << endl;
	cout << "1 - ����� (10 ��������)" << endl;
	cout << "2 - ������ (20 ��������)" << endl;
	cout << "default - ��������� (15 ��������)" << endl;
	int hardlevel = _getch() - 48;
	if (hardlevel != 1 && hardlevel != 2) hardlevel = 0;
	cout << endl;
	cout << "�������� ��� �����:" << endl;
	cout << "1 - ����������" << endl;
	cout << "2 - ��������" << endl;
	cout << "default - � ���������� ������" << endl;
	int type = _getch() - 48;
	if (type != 1 && type != 2) type = 0;
	try {
		Test<string> test_str(1);
		test_str.setHardLevel(hardlevel);
		Test<int> test_int(0);
		test_int.setHardLevel(hardlevel);
		if ((*test_str.getQuestions()).empty() && (*(test_int.getQuestions())).empty()) throw "��������� ������������� ����������� �������";
		switch (type)
		{
		case 1: case 2:
			(*student).passTest(test_str, type);
			break;
		default:
			(*student).passTest(test_int, type);
			break;
		}
		cls;
		cout << "���� �������.\n���� ������: " << (*student).getMark() << endl;
		Menu::student_edit('u');
		pause;
	}
	catch (const char* ex) {
		cout << endl << ex << endl;
		pause;
	}
}

void Menu::student_edit(char key)
{
	vector<string> file_logins;
	vector<string> file_groups;
	vector<int> file_marks;
	string login;
	string group;
	int mark;
	try {
		ifstream file_in("files/students.txt");
		if (!file_in.is_open()) throw "���� �� ������!";

		while (true) {
			file_in >> mark;
			getline(file_in, login);
			getline(file_in, group);

			if (file_in.eof()) break;
			else {
				file_marks.push_back(mark);
				file_logins.push_back(login);
				file_groups.push_back(group);
			}
		}
		file_in.close();

		ofstream file_out("files/students.txt", ios::trunc);
		if (!file_out.is_open()) throw "���� �� ������!";

		if (key == '1') {
			cout << "������� ����� �����: ";
			getline(cin, login);

			for (auto i : file_logins) {
				if (i == login) {
					file_out.close();
					throw false;
				}
			}

			for (int i = 0; i < file_logins.size(); i++) {
				if (file_logins[i] == (*student).getLogin()) {
					file_logins[i] = login;
					(*student).setLogin(login);
					break;
				}
			}
			for (int i = 0; i < file_logins.size(); i++)
				file_out << file_marks[i] << file_logins[i] << "\n" << file_groups[i] << "\n";
		}
		else if (key == '2') {
			cout << "������� ����� ������: ";
			getline(cin, group);

			for (int i = 0; i < file_logins.size(); i++) {
				if (file_logins[i] == (*student).getLogin()) {
					file_groups[i] = group;
					(*student).setGroup(stoi(group));
					break;
				}
			}
			for (int i = 0; i < file_logins.size(); i++)
				file_out << file_marks[i] << file_logins[i] << "\n" << file_groups[i] << "\n";
		}
		else if (key == '0') {
			cout << "������� ����� �����: ";
			getline(cin, login);

			for (auto i : file_logins) {
				if (i == login) {
					file_out.close();
					throw false;
				}
			}

			cout << "������� ����� ������: ";
			getline(cin, group);

			for (int i = 0; i < file_logins.size(); i++) {
				if (file_logins[i] == (*student).getLogin()) {
					file_logins[i] = login;
					file_groups[i] = group;
					(*student).setLogin(login);
					(*student).setGroup(stoi(group));
					break;
				}
			}
			for (int i = 0; i < file_logins.size(); i++)
				file_out << file_marks[i] << file_logins[i] << "\n" << file_groups[i] << "\n";
		}
		else {
			for (int i = 0; i < file_logins.size(); i++) {
				if (file_logins[i] == (*student).getLogin()) {
					file_marks[i] = (*student).getMark();
					break;
				}
			}
			for (int i = 0; i < file_logins.size(); i++)
				file_out << file_marks[i] << file_logins[i] << "\n" << file_groups[i] << "\n";
		}
		if (key == '1' || key == '2' || key == '3')
			cout << "������������ ��������." << endl;
		file_out.close();
	}
	catch (const char* ex) {
		cout << endl << ex << endl;
	}
	catch (bool) {
		cout << endl << "���� ����� ��� ������������!" << endl;
		ofstream file_out("files/students.txt", ios::trunc);
		for (int i = 0; i < file_logins.size(); i++)
			file_out << file_marks[i] << file_logins[i] << "\n" << file_groups[i] << "\n";
		file_out.close();
	}
}