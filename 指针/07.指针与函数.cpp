#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(int argc, char const *argv[])
{
    int a = 10, b = 20;
    swap(&a, &b);
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    return 0;
}
