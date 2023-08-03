#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

void print(vector<int> &v) {
    for (auto it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test1() {
    cout << "交换前:" << endl;
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    print(v1);

    vector<int> v2;
    for (int i = 10; i > 0; i--) {
        v2.push_back(i);
    }
    print(v2);

    cout << "交换后:" << endl;
    v1.swap(v2);
    print(v1);
    print(v2);
}

//实际用途：巧用swap可以收缩内存空间
void test2() {
    vector<int> v1;
    for (int i = 0; i < 100000; i++) {
        v1.push_back(i);
    }
    cout << "v1的容量:" << v1.capacity() << endl;
    cout << "v1的大小:" << v1.size() << endl;

    v1.resize(3);
    cout << "v1的容量:" << v1.capacity() << endl;  //容量没变
    cout << "v1的大小:" << v1.size() << endl;

    cout << "收缩后:" << endl;
    //巧用swap收缩
    //vector<int>(v1)是个匿名对象，按照v1使用的个数来初始化长度
    //swap()后v1就收缩了，那个匿名对象也会被自动回收
    vector<int>(v1).swap(v1);
    cout << "v1的容量:" << v1.capacity() << endl;
    cout << "v1的大小:" << v1.size() << endl;
}

int main() {
//    test1();
    test2();
}