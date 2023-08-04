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
    vector<int> v1;
    //尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    print(v1);

    //尾删
    v1.pop_back();
    print(v1);

    //插入，第一个参数是迭代器
    v1.insert(v1.begin(), 100);
    print(v1);

    v1.insert(v1.begin(), 2, 1000);
    print(v1);

    //删除
    v1.erase(v1.begin());
    print(v1);

    //删除全部
    v1.erase(v1.begin(), v1.end());
    print(v1);

    //等同上面删除全部
    v1.clear();
}

int main() {
    test1();
}