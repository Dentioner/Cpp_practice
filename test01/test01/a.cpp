//student.cpp -- implementing the Student class
//version 00

#include <iostream>
#include "student.h"

using namespace std;

typedef class A
{
public:
	int a;
	A()
	{
		a = 20;
	}

	void plus()
	{
		a += 1;
	}

}A;

int main()
{
	cout << (1 ^ 2) << endl;
	cout << (1 ^ 3) << endl;
	cout << (1 ^ 4) << endl;
	cout << (2 ^ 3) << endl;
	cout << (2 ^ 4) << endl;
	cout << (3 ^ 4) << endl;
	cout << (1 ^ 2 ^ 3) << endl;
	cout << (1 ^ 2 ^ 4) << endl;
	return 0;
}
