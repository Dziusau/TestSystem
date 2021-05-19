#include "Student.h"

Student::Student() : group(0), mark(0) {}

void Student::setMark(int mark) { this->mark = mark; }

int Student::getMark() { return mark; }

void Student::setGroup(int group) { this->group = group; }

int Student::getGroup() { return group; }

int Student::answer(Question<string>& question, string answer)
{
	if (question.checkAnswer(answer)) {
		cout << "Верно" << endl;
		return 1;
	}
	else {
		cout << "Неверно" << endl;
		cout << "Верный ответ: " << question.getAnswer() << endl;
		return 0;
	}
}

int Student::answer(Question<int>& question, int answer)
{
	if (question.checkAnswer(answer)) {
		cout << "Верно" << endl;
		return 1;
	}
	else {
		cout << "Неверно" << endl;
		cout << "Верный ответ: " << question.getAnswer() << endl;
		return 0;
	}
}

void Student::passTest(Test<string>& questions, int type)
{
	vector<Question<string>> test = questions.shuffleQuestions(type);

	switch (questions.getHardLevel())
	{
	case 1:
		for (int i = test.size(); i > 10; i--) test.pop_back();
		break;
	case 0:
		for (int i = test.size(); i > 15; i--) test.pop_back();
		break;
	case 2:
		for (int i = test.size(); i > 20; i--) test.pop_back();
		break;
	}

	int correct_answers = 0;
	string answer;
	for (auto i : test)
	{
		system("cls");
		string str = i.getQuestion();
		if (type == 1)
		{
			size_t pos = 0;
			string variant;
			int k = 0;
			while ((pos = str.find('/')) != std::string::npos) {
				variant = str.substr(0, pos);
				cout.setf(ios::left);
				if (k % 2 == 1)	cout << setw(20) << variant;
				else cout << setw(20) << variant << endl;
				k++;
				str.erase(0, pos + 1);
			}
			cout << str << endl;
			checkAnswer(answer, 1);
		}
		else {
			cout << str << endl;
			cout << "Ваш ответ: ";
			getline(cin, answer);
		}
		correct_answers += Student::answer(i, answer);
		system("pause");
	}
	this->setMark(questions.rateStudent(test.size(), correct_answers));
}

void Student::passTest(Test<int>& questions, int type)
{
	vector<Question<int>> test = questions.shuffleQuestions(type);

	switch (questions.getHardLevel())
	{
	case 1:
		for (int i = test.size(); i > 10; i--) test.pop_back();
		break;
	case 0:
		for (int i = test.size(); i > 15; i--) test.pop_back();
		break;
	case 2:
		for (int i = test.size(); i > 20; i--) test.pop_back();
		break;
	}

	int correct_answers = 0;
	int answer;
	for (auto i : test)
	{
		system("cls");
		string str = i.getQuestion();
		size_t pos = 0;
		string variant;
		while ((pos = str.find('/')) != std::string::npos) {
			variant = str.substr(0, pos);
			cout << variant << endl;
			str.erase(0, pos + 1);
		}
		cout << str << endl;

		while (true) {
			cout << "Ваш ответ: ";
			cin >> answer;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10, '\n');
				cout << "Некорректный ввод. Пожалуйста, попробуйте еще.\n" << endl;
				continue;
			}
			else if (answer < 1 || answer > 3)
			{
				cout << "Некорректный вариант ответа. Пожалуйста, попробуйте еще.\n" << endl;
				continue;
			}
			break;
		}
		correct_answers += Student::answer(i, answer);
		system("pause");
	}
	this->setMark(questions.rateStudent(test.size(), correct_answers));
}

void Student::printUser()
{
	cout.setf(ios::left);
	cout << setw(20) << "Имя" << setw(7) << "Группа" << "Оценка" << endl;
	cout << setw(20) << this->getLogin() << setw(7) << this->group << this->mark;
}

istream& operator>>(istream& stream, Student& student)
{
	string login;
	string group;

	stream >> student.mark;
	getline(stream, login);
	getline(stream, group);

	if (!group.empty()) {
		student.setGroup(stoi(group));
		student.setLogin(login);
	}
	return stream;
}

ostream& operator<<(ostream& stream, Student& student)
{
	stream << setw(20) << student.getLogin() << setw(7) << student.group << student.mark;
	return stream;
}