#include <iostream>
using namespace std;
class Base
{
public:
    // 纯虚函数
    virtual void func() = 0;
};

class Son : public Base
{
public:
    void func()
    {
        cout << "func函数" << endl;
    }
};
void test1()
{
    Base * base = new Son;
    base->func();
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
