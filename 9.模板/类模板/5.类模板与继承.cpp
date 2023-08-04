#include <iostream>

using namespace std;

//类模板与继承
template<class T>
class Base {
    T m;
};


//需要指定T
class Son : public Base<int> {

};

//如果想灵活指定父类中T类型，子类也需要变类模板
template<class T1, class T2>
class Son2 : public Base<T2> {
public:
    Son2() {
        cout << "T1的类型" << typeid(T1).name() << endl;
        cout << "T2的类型" << typeid(T2).name() << endl;
    }

    T1 obj;
};

void test1() {
    Son s1;
}

void test2() {
    Son2<int, char> s2;
}

int main(int argc, char const *argv[]) {
    test1();
    test2();
    return 0;
}
