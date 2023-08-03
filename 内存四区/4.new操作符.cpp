#include "iostream"

using namespace std;

//1.new基本语法
int *func() {
    //在堆区创建整型数据
    //new返回的是该数据类型的指针，10表示值
    int *p = new int(10);
    return p;
}

void test1() {
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    //堆区数据由程序员管理开辟和释放
    //释放使用 delete p
    delete p;

    //会报错，已经释放这块内存了
    //    cout << *p << endl;
}

//在堆区利用new开辟数组
void test2() {
    //10表示长度
    int *arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 100;
    }
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }
    //释放堆区数组，要加[]
    delete[] arr;
}

int main() {
    test1();
    test2();
}
