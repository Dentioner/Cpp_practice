#include <iostream>
#include <string>

using namespace std;

int readline()
{
    string line;
    while (getline(cin, line))
        cout <<line <<endl;
    return 0;
}

int readword()
{
    string word;
    while(cin >> word)
        cout << word <<endl;
    return 0;
}

int main()
{
    readword();
    return 0;
}