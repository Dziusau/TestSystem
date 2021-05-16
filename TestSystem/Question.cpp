#include "Question.h"

istream& operator>>(istream& stream, Question<string>& question) {
	stream >> question.type;
	getline(stream, question.question);
	getline(stream, question.answer);
	return stream;
}
istream& operator>>(istream& stream, Question<int>& question) {
	stream >> question.type;
	getline(stream, question.question);
	stream >> question.answer;
	return stream;
}