#include <iostream>
using namespace std;

void show(const int &val)
{
    val = 1000;
    cout << val << endl;
}
int main()
{
    int a = 10;
    show(a);
}