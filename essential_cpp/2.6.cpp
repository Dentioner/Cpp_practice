#include "common.h"

template <typename elem>
elem my_max(elem a, elem b)
{
    return a > b? a: b;
}

template <typename elem>
elem my_max(vector<elem> &vec)
{
    return *max_element(vec.begin(), vec.end());
}

template <typename elem>
elem my_max(elem arr[], int size)
{
    return *max_element(arr, arr+size);
}

int main()
{
    string sarr[] = {"we", "were", "her", "pride", "of", "ten"};
    vector<string> svec(sarr, sarr+6);

    cout << my_max(my_max(svec), my_max(sarr, 6)) << endl;
    return 0;
}