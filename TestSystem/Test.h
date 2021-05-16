#pragma once
#include "Question.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <time.h>
using namespace std;

namespace MyTest {
	template <class T>
	class Test
	{
		int hardLevel;
		multimap<int, Question<T>> questions;
	public:
		Test(int key);

		int getHardLevel();
		void setHardLevel(int level);

		auto getQuestions();
		auto shuffleQuestions(int type);
		int rateStudent(int amount_questions, int correct_answers);
	};


	template<class T>
	inline Test<T>::Test(int key)
	{
		this->hardLevel = 0;
		ifstream file((key == 0) ? "files/questions_0.txt" : "files/questions_12.txt");
		if (file.is_open()) {
			Question<T> temp;
			while (true) {
				file >> temp;
				if (file.eof()) break;
				questions.emplace(temp.getType(), temp);
			}
		}
		file.close();
	}

	template<class T>
	int Test<T>::getHardLevel() { return this->hardLevel; }

	template<class T>
	void Test<T>::setHardLevel(int level) { this->hardLevel = level; }

	template<class T>
	auto Test<T>::getQuestions() { return &questions; }

	template<class T>
	auto Test<T>::shuffleQuestions(int type)
	{
		vector<Question<T>> test;
		for (auto i : questions) {
			if (i.first == type) test.push_back(i.second);
		};

		srand(time(NULL));
		for (int i = test.size() - 1; i > 0; i--)
		{
			int j = rand() % (i + 1);
			Question<T> temp = test[i];
			test[i] = test[j];
			test[j] = temp;
		}

		return test;
	}

	template<class T>
	inline int Test<T>::rateStudent(int amount_questions, int correct_answers)
	{
		float mark = (float)correct_answers / amount_questions;
		mark += 0.05;
		return (int)(mark * 10);
	}
}
