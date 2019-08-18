#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    vector<int> v(begin(ia), end(ia));
    list<int> l(begin(ia), end(ia));

    vector<int>::iterator iv = v.begin();
    list<int>::iterator il = l.begin();

    for(auto i :ia)
    {
        cout << i << ' ';
    }
    cout << endl;
    while(iv != v.end())
    {
        if((*iv)%2)
            iv++;
        else
            iv = v.erase(iv);
    }

    while(il != l.end())
    {
        if((*il) %2)
            il = l.erase(il);
        else
            il++;
    }

    for(auto a:v)
    {
        cout<<a<<' ';
    }
    cout <<endl;
    for (auto b:l)
    {
        cout << b << ' ';

    }
    cout <<endl;    
    return 0;
}