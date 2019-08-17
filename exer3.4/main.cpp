#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2)
    cout << "=" <<endl;
    else if (s1 > s2)
    cout << "<" << endl;
    else
    cout << ">" <<endl;

    auto l1 = s1.size();
    auto l2 = s2.size();
    

    return 0;
}