#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    cout << "size = " << v7.size() <<endl;
    for (auto c: v7)
        cout << c<< " ";
    cout <<endl;
    v1.push_back(1);
    cout << "size = " << v1.size() <<endl;
    for (auto c: v1)
        cout << c<< " ";
    cout <<endl;
    return 0;
}