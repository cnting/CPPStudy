#include <iostream>
using namespace std;

class Base1
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son1 : public Base1
{
public:
   int m_D;
};

void test1()
{
    //父类中所有非静态成员属性都会被子类继承下去
    //父类中私有成员属性 是被编译器给隐藏了，因此子类访问不到，但确实继承了
    cout << "size of Son = "<< sizeof(Son1) << endl; //16
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
