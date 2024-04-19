#include  <iostream>
using namespace std;

void test(int* &arr)
{
    arr = new int[5];
    for(int i = 0; i < 5; i++)
        arr[i] = i + 1;
}

int main()
{
    int* arr;
    test(arr);

    for(int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    delete[] arr;
}