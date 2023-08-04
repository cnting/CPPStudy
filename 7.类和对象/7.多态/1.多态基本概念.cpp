#include <iostream>
using namespace std;

/**
 * 多态分为两类：
 * 1.静态多态：函数重载 和运算符重载属于静态多态，复用函数名
 * 2.动态多态：派生类和虚函数实现运行时多态
 *
 * 静态多态和动态多态区别：
 * 1.静态多态的函数地址早绑定 - 编译阶段确定函数地址
 * 2.动态多态的函数地址晚绑定 - 运行阶段确定函数地址
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
