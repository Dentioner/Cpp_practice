#include<iostream>

using std::string;
using std::cout;
using std::endl;
int main()
{
	string str("some string");
	for (auto c : str)
		cout << c << endl;

	return 0;
}