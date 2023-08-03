#include <iostream>
using namespace std;
#include <string>
class MyPrint
{
public:
    void operator()(string test)
    {
        cout << test << endl;
    }
};
void MyPrint2(string test)
{
    cout << test << endl;
}
void test1()
{
    MyPrint myPrint;
    // 仿函数，在一个类中重载了()
    myPrint("hello world");
    // 普通函数
    MyPrint2("hello world");
}

class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};

void test2()
{
    MyAdd myadd;
    int result = myadd(100, 100);
    cout << result << endl;

    // 匿名函数对象
    cout << MyAdd()(100, 100) << endl;
}

int main(int argc, char const *argv[])
{
    // test1();
    test2();
    return 0;
}
