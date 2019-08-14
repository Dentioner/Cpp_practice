#include<iostream>
#include<vector>

using namespace std;

vector<int> v1 = { 1, 2, 3, 4, 11, 6, 7, 8, 9 ,10 };

void neighbor()
{
	for (auto i = v1.begin(); (i+1) != v1.end(); i++)
	{
		decltype(i) j = i + 1;
		*i += *j;
	}
	return;
}


void headend()
{
	auto begin = v1.begin();
	auto end = v1.end();
	auto i = begin, j = end - 1;
	for (; i < j; i++, j--)
		* i += *j;

}
void print()
{
	for (auto i : v1)
		cout << i << ' ';
	cout << endl;
	return;
}



int main()
{
	print();
	//neighbor();
	headend();
	print();

	return 0;
}