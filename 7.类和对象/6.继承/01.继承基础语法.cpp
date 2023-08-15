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
/**
 * https://www.bilibili.com/video/BV1et411b73Z?p=128&spm_id_from=pageDriver&vd_source=cfa545ca14ba2d7782dd4c30ae22638e
 * 类继承语法：
 * 继承方式 类名
 *
 * 1.父类中private的属性子类不能继承，也访问不到
 *
 * 2.如果继承方式是public
 * （1）父类中public的属性，在子类中还是public
 * （2）父类中protect的属性，在子类中还是protected
 *
 * 3.如果继承方式是protected
 * （1）父类中public和protected的属性，在子类中都是protected
 *
 * 4.如果继承方式是private
 * （1）父类中public和protected的属性，在子类中都是private
 */
class Son1 : public Base1
{
public:
    void func()
    {
        m_A = 10;
        m_B = 10;
        // m_C = 10; 不能访问
    }
};

void test1()
{
    Son1 s1;
    s1.m_A = 100;
    // s1.m_B = 100; 访问不到
}

int main(int argc, char const *argv[])
{
    return 0;
}
