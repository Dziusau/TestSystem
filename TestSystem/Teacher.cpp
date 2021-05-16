#include "Teacher.h"

Teacher::Teacher() :User(1) {}

void Teacher::viewQuestions(Test<string>& test)
{
	for (auto i : *(test.getQuestions()))
	{
		string str = i.second.getQuestion();

		switch (i.second.getType())
		{
		case 2:
			cout << str << endl << endl;
			break;
		case 1:
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
			cout << str << endl << endl;
			break;
		}
		}
	}
}

void Teacher::viewQuestions(Test<int>& test) {
	for (auto i : *(test.getQuestions()))
	{
		string str = i.second.getQuestion();

		size_t pos = 0;
		string variant;
		while ((pos = str.find('/')) != std::string::npos) {
			variant = str.substr(0, pos);
			cout << variant << endl;
			str.erase(0, pos + 1);
		}
		cout << str << endl << endl;
	}
}

void Teacher::newQuestion(Test<string>& test, int type)
{
	Question<string> question;
	question.setType(type);
	string str;
	string answer;

	if (type == 1) {
		str = "Найдите соответствие:";
		cout << endl << "Введите утверждение 1-1: ";
		getline(cin, answer);
		str += "/1. "; str += answer;
		cout << "Введите утверждение 2-1: ";
		getline(cin, answer);
		str += "/а. "; str += answer;
		cout << "Введите утверждение 1-2: ";
		getline(cin, answer);
		str += "/2. "; str += answer;
		cout << "Введите утверждение 2-2: ";
		getline(cin, answer);
		str += "/б. "; str += answer;
		cout << "Введите утверждение 1-3: ";
		getline(cin, answer);
		str += "/3. "; str += answer;
		cout << "Введите утверждение 2-3: ";
		getline(cin, answer);
		str += "/в. "; str += answer;

		checkAnswer(answer, 0);
	}
	else {
		cout << "Введите формулировку вопроса: ";
		getline(cin, str);
		cout << endl << "Введите правильный ответ: ";
		getline(cin, answer);
	}
	question.setQuestion(str);

	question.setAnswer(answer);

	(*test.getQuestions()).emplace(type, question);
	question.write2file(1);
}

void Teacher::newQuestion(Test<int>& test)
{
	Question<int> question;

	question.setType(0);

	cout << "Введите формулировку вопроса: ";
	string str;
	getline(cin, str);

	cout << "Введите вариант первого ответа: ";
	string answer;
	getline(cin, answer);
	str += "/1. "; str += answer;
	cout << "Введите вариант второго ответа: ";
	getline(cin, answer);
	str += "/2. "; str += answer;
	cout << "Введите вариант третьего ответа: ";
	getline(cin, answer);
	str += "/3. "; str += answer;

	question.setQuestion(str);

	cout << endl << "Введите правильный ответ: ";
	int answer_int;

	while (true) {
		cin >> answer_int;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10, '\n');
			cout << "Некорректный ввод. Пожалуйста, попробуйте еще.\n" << endl;
			continue;
		}
		else if (answer_int < 1 || answer_int > 3)
		{
			cout << "Некорректный вариант ответа. Пожалуйста, попробуйте еще.\n" << endl;
			continue;
		}
		break;
	}
	cin.ignore(10, '\n');
	question.setAnswer(answer_int);

	(*test.getQuestions()).emplace(0, question);
	question.write2file(0);
}

istream& operator>>(istream& stream, Teacher& teacher)
{
	string login;
	string password;

	getline(stream, login);
	getline(stream, password);

	for (int i = 0; i < password.size(); i++) password[i] -= 6;
	teacher.setLogin(login);
	teacher.setPassword(password);

	return stream;
}

ostream& operator<<(ostream& stream, Teacher& teacher)
{
	string password = teacher.getPassword();
	for (int i = 0; i < password.size(); i++) password[i] += 6;
	stream << teacher.getLogin() << "\n" << password << "\n";
	return stream;
}

void checkAnswer(string& answer, int key)
{
	bool isCorrect = false;
	while (!isCorrect) {
		isCorrect = true;
		cout << endl << ((key == 0)?"Введите правильную комбинацию (пример: 1а2б3в): ": "Ваш ответ: ");
		getline(cin, answer);
		for (auto c : answer) c = tolower(c);

		if (answer.find("12") != string::npos || answer.find("13") != string::npos || answer.find("21") != string::npos || answer.find("23") != string::npos || answer.find("31") != string::npos || answer.find("32") != string::npos) {
			cout << "Некорректный ввод: нельзя ввести две цифры подряд!\nПожалуйста, повторите попытку." << endl;
			isCorrect = false;
			continue;
		}
		if (answer.find("аб") != string::npos || answer.find("ав") != string::npos || answer.find("ба") != string::npos || answer.find("бв") != string::npos || answer.find("ва") != string::npos || answer.find("вб") != string::npos) {
			cout << "Некорректный ввод: нельзя ввести две буквы подряд!\nПожалуйста, повторите попытку." << endl;
			isCorrect = false;
			continue;
		}
		if (answer.find("1") == string::npos || answer.find("2") == string::npos || answer.find("3") == string::npos) {
			cout << "Некорректный ввод: в комбинации должны присутствовать все цифры от 1 до 3!\nПожалуйста, повторите попытку." << endl;
			isCorrect = false;
			continue;
		}
		if (answer.find("а") == string::npos || answer.find("б") == string::npos || answer.find("в") == string::npos) {
			cout << "Некорректный ввод: в комбинации должны присутствовать все буквы от а до в!\nПожалуйста, повторите попытку." << endl;
			isCorrect = false;
			continue;
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] == '1') {
			if (i == 0) continue;
			else {
				char c = answer[0];
				answer[0] = '1';
				answer[i] = c;

				c = answer[1];
				answer[1] = answer[i + 1];
				answer[i + 1] = c;
				continue;
			}
		}
		else if (answer[i] == '2') {
			if (i == 2) continue;
			else {
				char c = answer[2];
				answer[2] = '2';
				answer[i] = c;

				c = answer[3];
				answer[3] = answer[i + 1];
				answer[i + 1] = c;
				continue;
			}
		}
		else if (answer[i] == '3') {
			if (i == 4) continue;
			else {
				char c = answer[4];
				answer[4] = '3';
				answer[i] = c;

				c = answer[5];
				answer[5] = answer[i + 1];
				answer[i + 1] = c;
				continue;
			}
		}
	}
}
