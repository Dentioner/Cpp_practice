#include<iostream>

using std::cin;
using std::cout;
using std::endl;

void test(int &i)
{
    i = 5;
    return;
}

void test0(int i)
{
    i = 5;
    return;
}

int main()
{
    int j = 6;
    cout << "j = " << j << endl;
    test0(j);
    cout << "j = " << j << endl;
    test(j);
    cout << "j = " << j << endl;
    return 0;
}