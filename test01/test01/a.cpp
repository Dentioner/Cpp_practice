//student.cpp -- implementing the Student class
//version 00

#include <iostream>
#include "student.h"

using namespace std;

Student::Student() {
	cout << "您好呀! 新同学,你叫什么名字?" << endl;
}
Student::Student(std::string n, int chScore, int enScore, int mathScore) :name(n), ch(chScore), en(enScore), math(mathScore) {
	cout << "您好呀! " << name << ",很高兴见到你!" << endl;
}
Student::~Student() {
	cout << "再见! " << name << "." << endl;
}
void Student::setChScore(int score) {
	Student::ch = score;
}
void Student::setName(std::string n) {
	Student::name = n;
}
void Student::setEnScore(int score) {
	en = score;
}
void Student::setMathScore(int score) {
	math = score;
}
void Student::show() {
	Student::count();
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(1);
	cout << name << " 同学的语文成绩为" << ch << "分，数学成绩为" << math << "分，英语成绩为" << en << "分，平均成绩" << average << "分" << endl;
	cout.setf(orig, ios_base::floatfield);
}



int main()
{
	Student* s1, s2, s3("Jack", 90, 80, 70);
	s1 = new Student("Sam", 90, 95, 100);
	s1->show();

	s2 = Student("Sue", 85, 90, 95);
	s2.show();
	s3.show();

	s1 = new Student("Joe", 91, 92, 93);
	s1->show();
	delete s1;

	return 0;
}
