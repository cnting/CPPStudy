#include "iostream"
#include "set"

using namespace std;

/**
 * set容器修改排序规则
 * 利用仿函数，可以改变排序规则
 */
void print(set<int> &s) {
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

class MyCompare {
public:
    //仿函数
    //第一个()表示要重载的符号，第二个()表示函数体的参数列表
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};

void test1() {
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);
    print(s1);

    //指定排序规则为从大到小，要还没插数据前就设置
    set<int, MyCompare> s2;
    s2.insert(10);
    s2.insert(40);
    s2.insert(30);
    s2.insert(20);
    s2.insert(30);
    for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    test1();
}