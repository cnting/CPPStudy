#include <iostream>
using namespace std;
/**
 * https://www.bilibili.com/video/BV1et411b73Z?p=134&vd_source=cfa545ca14ba2d7782dd4c30ae22638e
 * 使用虚继承 解决SheepCamel里有两份 m_Age的问题
 *
 * 使用virtual后，Sheep和Camel都有一个vbptr(虚基类指针)，指向同一个(vbtable)虚基类表
 * vbtable中只有一份m_Age
 */
class Animal
{
public:
    int m_Age;
};
// 利用虚继承(virtual) 解决菱形继承的问题
// Animal类称为 虚基类
class Sheep : virtual public Animal
{
};

class Camel : virtual public Animal
{
};

class SheepCamel : public Sheep, public Camel
{
};

void test1()
{
    SheepCamel s;
    s.Sheep::m_Age = 19;
    s.Camel::m_Age = 20;
    // m_Age应该只有一份就好
    cout << "s.Sheep::m_Age = " << s.Sheep::m_Age << endl;
    cout << "s.Camel::m_Age = " << s.Camel::m_Age << endl;
    cout << "s.m_Age = " << s.m_Age << endl;
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
