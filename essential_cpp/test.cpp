#include "common.h"

/*
class odd
{
public:
    bool operator()(int a)
    {
        return (a%2);
    }
};
*/

inline bool odd(int a)
{
    return (a%2);
}


int main()
{
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> vec(arr, arr+10);
    vector<int>::iterator ans = stable_partition(vec.begin(), vec.end(), odd);
    for(int index1 = 0; index1 < vec.size(); index1++)
    {
        cout << vec[index1] << " ";
    }
    cout << endl;
    return 0;
}