#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student { //class declaration
private:
	std::string name;
	int ch;
	int en;
	int math;
	float average;
	void count() {
		average = (ch + en + math + 0.0F) / 3;
	}
public:
	Student();
	Student(std::string name, int chScore, int enScore, int mathScore);
	~Student();
	void setName(std::string name);
	void setChScore(int score);
	void setEnScore(int score);
	void setMathScore(int score);
	void show();
};

#endif
