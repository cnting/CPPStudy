#include <iostream>
using namespace std;
/**
 * 函数传参时，可以利用引用的技术让形参修饰实参
 * 可以不同指针了
 */
// 1.值传递，不会改到main()里a和b
void swap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "swap1 a=" << a << ",b=" << b << endl;
}
// 2.地址传递，会改到main()里a和b
void swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "swap2 a=" << *a << ",b=" << *b << endl;
}

// 3.引用传递，会改到main()里a和b
void swap3(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "swap3 a=" << a << ",b=" << b << endl;
}

int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 20;
    swap1(a, b);
    cout << "a=" << a << ",b=" << b << endl;

    swap2(&a, &b);
    cout << "a=" << a << ",b=" << b << endl;

    swap3(a, b);
    cout << "a=" << a << ",b=" << b << endl;
    return 0;
}
