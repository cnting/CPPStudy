#include "iostream"

using namespace std;

class Person {
public:
    //构造函数
    //1.没有返回值
    //2.函数名与类名相同
    //3.构造函数可以有参数，可以发生重载
    //4.创建对象时，构造函数会自动调用，且只调用一次
    Person() {
        cout << "Person构造函数调用" << endl;
    }

    //析构函数
    //1.没有返回值
    //2.函数名和类名相同，前面加~
    //3.析构函数不可以有参数，不可以重载
    //4.析构函数会自动调用，且只调用一次
    ~Person() {
        cout << "Person析构函数调用" << endl;
    }
};

void test1() {
    //栈上的数据，这个方法执行完会自动释放这个对象
    Person p1;
}

int main() {
    test1();
}