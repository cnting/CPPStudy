#include <iostream>

using namespace std;

#include "MyArray.hpp"
#include "ArrayList.hpp"

/**
 * 实现一个通用的数组类
 * 1.可以对内置数据类型以及自定义数据类型的数据进行存储
 * 2.将数组中数据存储到堆区
 * 3.构造函数中可以传入数组的容量
 * 4.提供对应的拷贝函数以及operator=防止浅拷贝
 * 5.提供尾插法和尾删法对数组中的数据进行增加和删除
 * 6.可以通过下标的方式访问数组中的元素
 * 7.可以获取数组中当前元素个数和数组的容量
 *
 *
 * 注意：如果使用了模板类，声明和实现必须写在一个文件中，所以这里搞成hpp
 */

void printArray(MyArray<int> &arr) {
    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr[i] << endl;
    }
}

void test1() {
    MyArray<int> arr1(5);

    for (int i = 0; i < 5; i++) {
        arr1.Push_Back(i);
    }
    cout << "arr1的打印输出:" << endl;
    printArray(arr1);

    cout << "arr1的容量:" << arr1.getCapacity() << endl;
    cout << "arr1的大小:" << arr1.getSize() << endl;

    MyArray<int> arr2(arr1);
    cout << "arr2的打印输出:" << endl;
    printArray(arr2);
    arr2.Pop_Back();

    cout << "arr2尾删后" << endl;
    cout << "arr2的容量:" << arr2.getCapacity() << endl;
    cout << "arr2的大小:" << arr2.getSize() << endl;


    MyArray<int> arr3(100);

    arr3 = arr1;
}

class Person {
public:
    Person() {};

    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;

};

void printPersonArray(MyArray<Person> &arr) {
    for (int i = 0; i < arr.getSize(); i++) {
        cout << "姓名:" << arr[i].m_Name << ",年龄:" << arr[i].m_Age << endl;
    }
}

void test2() {
    MyArray<Person> arr(10);
    Person p1("孙悟空", 100);
    Person p2("孙悟空1", 33);
    Person p3("孙悟空2", 44);
    Person p4("孙悟空3", 55);
    Person p5("孙悟空4", 77);

    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);

    printPersonArray(arr);

    cout << "arr的容量:" << arr.getCapacity() << endl;
    cout << "arr的大小:" << arr.getSize() << endl;
}
/**
 * 包含扩容机制
 */
void test3() {
    ArrayList<int> list;
    for (int i = 0; i < 100; i++) {
        list.add(i);
    }
    //测试拷贝构造
    ArrayList<int> list2 = list;

    for (int i = 0; i < list2.size(); i++) {
        cout << list2.get(i) << endl;
    }

    cout << "删除一个数后：" << endl;
    cout << "被删除的数：" << list.remove(50) << endl;
    cout << "总长度：" << list.size();
}

int main(int argc, char const *argv[]) {
//    test1();
//    test2();
    test3();
    return 0;
}
