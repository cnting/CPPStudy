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

    //有参构造，这里给age和sex设置默认值
    Person(char *name) : age(20), sex(1) {
        this->name = name;
        cout << "Person有参构造1调用" << endl;
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
    char *name;
    int sex;
};

//三种调用方式：
void test1() {
    //1.括号法
//    Person p1;        //默认构造函数调用
//    Person p2(10); //有参构造调用
//    Person p3(p2);    //拷贝构造函数调用

    //注意事项1
    //调用默认构造函数时，不要加()
    //因为下面这行代码，编译器会认为是一个函数的声明
//    Person p4();  //不要这样写

    //2.显式法
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

void test2() {
    cout << "用new的方式创建" << endl;
    //用new的方式创建，有调用空参构造方法
    Person *p = new Person();
    p->age = 10;
    cout << "age:" << p->age << endl;

    cout << endl << "用malloc的方式创建" << endl;
    //用malloc方式创建，并没有调空参的构造方法
    Person *p1 = static_cast<Person *>(malloc(sizeof(Person)));
    p1->age = 20;
    cout << "age:" << p1->age << endl;
}
/**
 * 构造函数相互调用
 */
class Student {
public:
    //调用其他构造函数
    Student() : Student(10) {
        cout << "Student构造函数1" << endl;
    }

    Student(int age) : Student(age, "ct") {
        cout << "Student构造函数2" << endl;

    }

    Student(int age, char *name) {
        cout << "Student构造函数3" << endl;
        this->age = age;
        this->name = name;
    }

    int age;
    char *name;
};

void test3() {
    Student stu;
    cout << "name:" << stu.name << ",age:" << stu.age << endl;
}

int main() {
//    test1();
//    test2();
    test3();
}