#include <iostream>
using namespace std;

int main()
{
    // 1. const修饰指针--常量指针（记住前两个字：常量不能改）
    int a = 10;
    int b = 10;
    const int *p = &a;
    // 指针指向的值不可以改，指针的指向可以改
    //*p = 20;  //错误
    p = &b;

    // 2. const修饰常量--指针常量（记住前两个字：指针不能改）
    //指针的指向不可以改，指针指向的值可以改
    int *const p2 = &a;
    *p2 = 200;
    // p2 = &b;   //错误

    // 3. const修饰指针和常量
    //指针的指向 和 指针指向的值 都不可以改
    const int * const p3 = &a;
    // *p3 = 100; //错误
    // p3 = &b;   //错误

    return 0;
}
