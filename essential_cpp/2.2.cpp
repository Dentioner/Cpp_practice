#include "common.h"

#define MAX_INDEX 209

inline int count_pentagonal(int n)
{
    return (n*(3*n-1))/2;
}

void get_num(vector<int>&pen)
{
    int size = 0;
    cout << "size:" << endl;
    while ((cin >> size && size > MAX_INDEX))
    {
        cout << "invalid input" << endl;
    }

    for(int index1 = 1; index1 <= size; index1++)
    {
        pen.push_back(count_pentagonal(index1));
    }
    
}

void print_num(vector<int>&pen)
{
    cout << "arr:" << endl;
    for(int index1 = 0; index1 < pen.size(); index1++)
    {
        cout << pen[index1] << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> pentagonal;
    get_num(pentagonal);
    print_num(pentagonal);

    return 0;
}