#include <iostream>
using namespace std;

/**
 * https://www.bilibili.com/video/BV1et411b73Z?p=136&spm_id_from=pageDriver&vd_source=cfa545ca14ba2d7782dd4c30ae22638e
 * 多态：程序在编译期间并不知道运行哪个函数，只有在真正运行过程中才会去找需要运行的方法
 *
 * 多态分为两类：
 * 1.静态多态：函数重载 和运算符重载属于静态多态，复用函数名
 * 2.动态多态：派生类和虚函数实现运行时多态
 *
 * 静态多态和动态多态区别：
 * 1.静态多态的函数地址早绑定 - 编译阶段确定函数地址
 * 2.动态多态的函数地址晚绑定 - 运行阶段确定函数地址
 *
 * 多态原理：
 * virtual修饰speak()后，Animal中会有一个vfptr(虚函数指针)，指向一个vftable(虚函数表)，
 * vftable中会记录一个函数地址 &Animal::speak
 *
 * Cat继承了Animal，把所有东西都继承下来了一份，也复制了一份vftable。
 * 当Cat没有重写speak()时，Cat的虚函数表内部记录的也是 &Animal::speak
 * 当它重写了speak()，Cat的虚函数表内部会替换成 &Cat::speak
 *
 */
class Animal
{
public:
    //虚函数，实现地址动态绑定
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "小狗在说话" << endl;
    }
};

//动态多态满足条件:
//1.有继承关系
//2.子类重写父类的虚函数

//动态多态的使用：
//父类的指针或引用，指向子类对象
void doSpeak(Animal &animal)
{
    //如果想执行让猫说话，这个函数地址就不能提前绑定，需要在运行阶段进行绑定，使用virtual修饰该方法
    animal.speak();
}

void test1()
{
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
