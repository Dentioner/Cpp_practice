#include<iostream>

using namespace std;

int add(initializer_list<int> il)
{
	int count = 0;
	for (auto a : il)
		count += a;
	return count;
}

int main()
{
	cout << add({ 1, 2, 3, 4, 5 }) << endl;

	return 0;
}