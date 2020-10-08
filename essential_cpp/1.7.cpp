#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> vec;
    ifstream file;
    file.open("file.txt");
    string temp;
    int counter = 0;

    cout << "input:" << endl;

    while(file >> temp)
    {
        cout << temp << " ";
        vec.push_back(temp);
    }
    cout << endl;

    cout << "output:" << endl;

    sort(vec.begin(), vec.end());

    for(int index1 = 0; index1 < vec.size() ; index1++ )
    {
        cout << vec[index1] << " ";
    }

    cout << endl;
    
    return 0;
}