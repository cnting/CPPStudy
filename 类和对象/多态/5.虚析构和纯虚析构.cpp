#include <iostream>
using namespace std;
class Animal
{
public:
    Animal()
    {
        cout << "Animal构造函数" << endl;
    }
    //虚析构
    // virtual ~Animal()
    // {
    //     cout << "Animal析构函数" << endl;
    // }
    
    //纯虚析构，需要声明也需要实现
    //有了纯虚析构，这个类也属于抽象类
    virtual ~Animal() = 0;

    virtual void speak() = 0;
};

//纯虚析构，需要具体实现
Animal::~Animal(){
    cout << "Animal纯虚析构函数" << endl;
}
class Cat : public Animal
{
public:
    Cat(string name)
    {
        cout << "Cat构造函数" << endl;
        m_Name = new string(name);
    }
    void speak()
    {
        cout << *m_Name << "小猫在说话" << endl;
    }
    ~Cat()
    {
        if (m_Name != NULL)
        {
            cout << "Cat析构函数" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }

    string *m_Name;
};
void test1()
{
    Animal *animal = new Cat("Tom");
    animal->speak();
    //父类指针在析构时，不会调用子类中析构函数，导致子类会有内存泄漏
    delete animal;
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
