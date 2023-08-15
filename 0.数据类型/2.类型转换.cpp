#include "iostream"

using namespace std;

/**
 * 类型转换：
 * 1.static_cast：静态转换，一般用来转换子父类
 * （1）用于基本数据类型转换
 * （2）把一种类型转换成另一种类型，用于类层次结构中基类和派生类直接指针或引用的转换
 *
 *
 * 2.const_cast：常量转换，用于修改常量的值
 *
 * 3.reinterpet_cast：强制类型转换，用于转换任意类型
 *
 * 4.dynamic_cast：动态转换。
 * （1）其他三种都是在编译时完成，dynamic_cast是在运行时完成
 * （2）更安全，转换成功返回类型，失败返回空
 */

class Person {
public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    string name;
    int age;
};

class Student : public Person {
public:
    Student(string name, int age) : Person(name, age) {
    }

};

void test1() {
    double num1 = 20.02;
    //直接转换
    int num2 = num1;
    cout << num2 << endl;

    //静态转换
    int num3 = static_cast<int>(num1);
    cout << num3 << endl;

    //把父类转子类
    Person *person = new Person("ct", 11);
    Student *student = static_cast<Student *>(person);
    cout << student->name << "," << student->age << endl;
}

void test2() {
    const Person *person = new Person("ct", 11);
    //person用const修饰，这么修改会报错
//    person->age = 24;

    //用这种方式改
    Person *p1 = const_cast<Person *>(person);
    p1->age = 30;
    p1->name = "aa";
    cout << person->name.c_str() << "," << person->age << endl;
}

void test3() {
    Person *person = new Person("ct", 11);
    //比如这个指针地址是从Android端传入，要转成具体类型的指针
    long mPtr = reinterpret_cast<long>(person);
    //将指针转成具体类型
    Student *student = reinterpret_cast<Student *>(mPtr);
    cout << student->name << "," << student->age << endl;

}


void test4() {
}

int main() {
//    test1();
//    test2();
//    test3();
    test4();
}

