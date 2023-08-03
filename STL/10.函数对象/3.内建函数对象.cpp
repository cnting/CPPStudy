#include "iostream"
#include "vector"
#include "algorithm"
#include "functional"

using namespace std;

/**
 * STL内建了一些函数对象
 * 1.算术仿函数
 * 2.关系仿函数
 * 3.逻辑仿函数
 */

//算术仿函数（加、减、乘、除、取反）
void test1() {
    //negate 一元仿函数（取反）
    negate<int> n;
    cout << "50取反:" << n(50) << endl;

    //plus 二元仿函数（加法）
    plus<int> p;
    cout << "10+20=" << p(10, 20) << endl;
}

class MyCompare {
public:
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};

//关系仿函数
void test2() {
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(20);
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    //降序
    //sort(v.begin(), v.end(), MyCompare());

    //greater<int>()直接实现了MyCompare的功能
    sort(v.begin(), v.end(), greater<int>());

    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

//逻辑仿函数（与、或、非），用的少，了解即可
void test3() {
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    for (vector<bool>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    //利用逻辑非 将容器v 搬运到 容器v2中，并执行取反操作
    vector<bool> v2;
    //要先扩容
    v2.resize(v.size());
    //transform搬运，logical_not取反
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());

    for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
//    test1();
//    test2();
    test3();
}