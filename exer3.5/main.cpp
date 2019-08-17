#include <iostream>
#include <string>

using namespace std;

int main()
{
    char cont = 'y';
    string s, result;
    while(cin >> s)
    {
        result += s;
        cin >> cont;
        if (cont == 'y' || cont == 'Y')
        ;
        else
        break;
    }
    cout << result << endl;
    
    return 0;

}