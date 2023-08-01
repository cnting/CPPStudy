#include <iostream>
using namespace std;

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
