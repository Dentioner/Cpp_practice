#include<iostream>

using namespace std;

void exchange(int*& a, int*& b)
{
	int* c = a;
	a = b;
	b = c;
}

void exchange2(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	int a = 3, b = 7;
	int* pa = &a, * pb = &b;
	exchange(pa, pb);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "pa = " << *pa << endl;
	cout << "pb = " << *pb << endl;

	return 0;
}