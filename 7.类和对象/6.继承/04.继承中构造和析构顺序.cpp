#include <iostream>
using namespace std;

class Base1
{
public:
    Base1()
    {
        cout << "Base构造函数" << endl;
    }
    ~Base1()
    {
        cout << "Base析构函数" << endl;
    }
};

class Son1 : public Base1
{
public:
    Son1()
    {
        cout << "Son构造函数" << endl;
    }
    ~Son1()
    {
        cout << "Son析构函数" << endl;
    }
};

void test1()
{
    Son1 son;
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
