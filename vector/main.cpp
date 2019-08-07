#include<vector>
#include<iostream>


using std::vector;
using std::cout;
using std::endl;
using std::cin;


vector<int> v2;
int main()
{
	vector<unsigned> scores(11, 0);
	unsigned grade;
	while (cin >> grade)
	{
		if (grade <= 100)
			++scores[grade / 10];
	}
	for (int i = 0; i < 11; i++)
		cout << scores[i] << ' ' ;
	cout << endl;
	return 0;
}