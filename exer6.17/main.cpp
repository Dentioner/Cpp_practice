#include<iostream>
#include<string>

using namespace std;

bool has_upper(const string str)
{
	for (auto c : str)
	{
		if (isupper(c))
			return true;
	}
	return false;
}



int main()
{
	string str;
	cin >> str;
	cout << has_upper(str) << endl;
	return 0;
}