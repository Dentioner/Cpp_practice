#include<iostream>
#include<stdexcept>

using namespace std;

int main()
{
	int ival1, ival2;
	while (cin >> ival1 >> ival2)
	{
		try
		{
			if (ival2 == 0)
			{
				throw runtime_error("³ıÊıÎª0");
			}
			cout << ival1 / ival2 << endl;
		}
		catch(runtime_error err)
		{
			cout << err.what() << endl;
			cout << "continue?";
			char ch;
			cin >> ch;
			if (ch != 'y' && ch != 'Y')
				break;
		}
	}

	return 0;
}