#include<iostream>
#include<vector>
#include<deque>
#include<string>

using namespace std;

int main()
{
    string in;
    deque<string> d;
    while(cin >> in)
    {
        d.push_back(in);
    }

    for (auto b = d.begin(); b < d.end(); b++)
    {
        cout << *b <<endl;
    }
    cout << endl;
    return 0;
}