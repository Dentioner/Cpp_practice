#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	vector<int> vint;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		vint.push_back(rand() % 1000);
	}
	cout << "the numbers are :" << endl;
	for (auto it = vint.cbegin(); it != vint.cend(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
	for (auto it = vint.begin(); it != vint.end(); it++)
	{
		*it *= 2;
		cout << *it << ' ';
	}
	cout << endl;

	return 0;
}