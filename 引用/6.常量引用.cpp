#include <iostream>
using namespace std;
//const修饰形参，防止修改
void show(const int &val)
{
//    val = 1000;
    cout << val << endl;
}
int main()
{
    int a = 10;
    show(a);
}