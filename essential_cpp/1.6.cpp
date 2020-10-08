#include <iostream>
#include <vector>

#define MAX 1000
using namespace std;


void read_array(int arr[])
{
    int counter = 0;
    int result = 0;
    cout << "enter:" << endl;
    while( counter < MAX && (cin >> arr[counter]))
    {
        counter++;
    }

    for(int index1 = 0; index1 < counter; index1++)
    {
        result += arr[index1];
    }

    cout << "\nresult:" << result << endl;
    // printf("result:%d\n", result);
}

void read_vector(vector<int> vec)
{
    int counter = 0;
    int result = 0;
    int temp;
    cout << "enter:" << endl;
    //while(cin >> vec[counter])
    while(cin >> temp)
    {
        vec.push_back(temp);
        // vec[counter] = temp;
        counter++;
    }

    for(int index1 = 0; index1 < counter; index1++)
    {
        result += vec[index1];
    }

    cout << "\nresult:" << result << endl;
}

int main()
{
    int arr[MAX];
    vector<int> vec;

    // read_array(arr);
    read_vector(vec);

    return 0;
}