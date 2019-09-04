#include<iostream>

using namespace std;


int hanoi(int num)
{
	int step;
	if (num == 1)
		step = 1;
	else
		step = 2 * hanoi(num - 1) + 1;
	return step;
}

int main()
{

	int number;
	cin >> number;
	cout << "step : " << hanoi(number) << "\n" << endl;
	
	return 0;
}