#include <iostream>
using namespace std;
/**
 * 函数传参时，可以利用引用的技术让形参修饰实参
 * 可以不用指针了
 *
 * 1.swap1()，是将实参的值复制给形参
 * 2.swap2()，是将实参的地址复制给形参
 * 3.swap3()，是给实参起了别名，实参和形参指向同一块内存地址（好像跟指针差不多）
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
