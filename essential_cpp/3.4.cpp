#include "common.h"

inline bool odd(int a)
{
    return (a%2);
}

void iter()
{
    vector<int> input;
    istream_iterator<int> istart(cin);
    istream_iterator<int> ieof;
    copy(istart, ieof, back_inserter(input));

    vector<int>::iterator mid = partition(input.begin(), input.end(), odd);

    ofstream out_o("odd.txt");
    ofstream out_e("even.txt");

    ostream_iterator<int> os_o(out_o, " ");
    ostream_iterator<int> os_e(out_e, "\n");

    copy(input.begin(), mid, os_o);
    copy(mid, input.end(), os_e);

    return;
}

int main()
{
    iter();
    return 0;
}