#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template <class T>
class Question
{
	int type;
	string question;
	T answer;
	bool isRight;

public:
	Question();

	int getType();
	void setType(int type);
	string getQuestion();
	void setQuestion(string question);
	T getAnswer();
	void setAnswer(T answer);

	bool checkAnswer(T answer);
	void write2file(int type);

	friend istream& operator>>(istream& stream, Question<string>& question);
	friend istream& operator>>(istream& stream, Question<int>& question);
	template<class T>
	friend ostream& operator<<(ostream& stream, Question<T>& question);
};


template <class T>
Question<T>::Question() : type(0), question(""), answer(T()), isRight(false) {};

template<class T>
int Question<T>::getType() { return this->type; }

template<class T>
void Question<T>::setType(int type) { this->type = type; }

template<class T>
string Question<T>::getQuestion() { return this->question; }

template<class T>
void Question<T>::setQuestion(string question) { this->question = question; }

template<class T>
T Question<T>::getAnswer() { return this->answer; }

template<class T>
void Question<T>::setAnswer(T answer) { this->answer = answer; }

template<class T>
bool Question<T>::checkAnswer(T answer)
{
	return isRight = (this->answer == answer) ? true : false;
}

template<class T>
void Question<T>::write2file(int type)
{
	try {
		ofstream file((type == 0) ? "files/questions_0.txt" : "files/questions_12.txt", ios::app);
		if (!file.is_open()) throw "Ошибка открытия файла!";
		file << *this;
		file.close();
	}
	catch (char* ex) {
		cout << ex << endl;
	}
}

template<class T>
ostream& operator<<(ostream& stream, Question<T>& question) {
	stream << question.type << question.question << '\n' << question.answer << '\n';
	return stream;
}
