#include <iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;
using func = int (*)(int, int);
//typedef int (*func)(int, int);
//int f(int, int);
//typedef decltype(f) func;


int myadd(int a, int b)
{
    return a+b;
}

int mysub(int a, int b)
{
    return a-b;
}

int mymult(int a, int b)
{
    return a*b;
}

int mydiv(int a, int b)
{
    return(b == 0?0:a/b);
}


int main()
{
    vector<func> fvec{myadd, mysub, mymult, mydiv};
    for(auto f:fvec)
    {
        cout << f(2, 4) << endl;
    }

    return 0;
}
