#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a = 10, b = 20;
    //地址传递
    swap(&a, &b);
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    return 0;
}
