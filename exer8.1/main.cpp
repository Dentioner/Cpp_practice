#include<iostream>
#include<stdexcept>

using namespace std;

istream& func(istream& is)
{
    int v;
    while(is >> v, !is.eof())
    {
        if(is.bad())
            throw runtime_error("IO stream error");
        if(is.fail())
        {
            cerr << "wrong data" << endl;
            is.clear();
            is.ignore(100, '\n');
            continue;
        }
        cout << v;
    }

    
    cout << endl;
    is.clear();
    return is;
}