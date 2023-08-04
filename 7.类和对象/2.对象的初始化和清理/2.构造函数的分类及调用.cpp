#include "iostream"

using namespace std;

//两种分类方式：
//按参数分：有参构造和无参构造
//按类型分：普通构造和拷贝构造
class Person {
public:

    Person() {
        cout << "Person无参构造调用" << endl;
    }

    Person(int a) {
        age = a;
        cout << "Person有参构造调用" << endl;
    }

    //拷贝构造函数
    Person(const Person &p) {
        age = p.age;
        cout << "Person拷贝构造调用" << endl;
    }

    ~Person() {
        cout << "Person析构函数调用" << endl;
    }

    int age;
};

//三种调用方式：
void test1() {
    //1.括号法
//    Person p1;        //默认构造函数调用
//    Person p2(10); //有参构造调用
//    Person p3(p2);    //拷贝构造函数调用

    //注意事项1
    //调用默认故障函数时，不要加()
    //因为下面这行代码，编译器会认为是一个函数的声明
//    Person p4();  //不要这样写

    //2.显示法
    Person p1;
    Person p2 = Person(10);  //有参构造
    Person p3 = Person(p2);    //拷贝构造

    //注意事项2
    //不要利用拷贝构造函数 初始化匿名对象
    //编译器会认为下面写法等价于 Person (p3) === Person p3，重复定义了
//    Person(p3);  //会报错

    //3.隐式转换法
    Person p4 = 10;  //相当于 Person p4 = Person(10)
    Person p5 = p4;  //拷贝构造
}

int main() {
    test1();
}