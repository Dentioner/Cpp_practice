//student.cpp -- implementing the Student class
//version 00

#include <iostream>
#include "student.h"

using namespace std;

Student::Student() {
	cout << "����ѽ! ��ͬѧ,���ʲô����?" << endl;
}
Student::Student(std::string n, int chScore, int enScore, int mathScore) :name(n), ch(chScore), en(enScore), math(mathScore) {
	cout << "����ѽ! " << name << ",�ܸ��˼�����!" << endl;
}
Student::~Student() {
	cout << "�ټ�! " << name << "." << endl;
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
	cout << name << " ͬѧ�����ĳɼ�Ϊ" << ch << "�֣���ѧ�ɼ�Ϊ" << math << "�֣�Ӣ��ɼ�Ϊ" << en << "�֣�ƽ���ɼ�" << average << "��" << endl;
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
