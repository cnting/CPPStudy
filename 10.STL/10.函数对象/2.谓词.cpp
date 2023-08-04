#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/**
 * 谓词概念（Predicate就表示谓词）
 * 1.返回bool类型的仿函数称为谓词
 * 2.如果operator()接受一个参数，那么叫一元谓词
 * 3.如果operator()接受两个参数，那么叫二元谓词
 */

class GreaterFive {
public:
    //一元谓词：返回bool类型，接受一个参数
    bool operator()(int a) {
        return a > 5;
    }
};

void test1() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    //查找容器中 有没有大于5的数字
    //GreaterFive()是匿名函数对象
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end()) {
        cout << "未找到" << endl;
    } else {
        cout << "找到了大于5的数字为：" << *it << endl;
    }
}

class MyCompare {
public:
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};

void test2() {
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);

    sort(v.begin(), v.end());

    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    //使用函数对象，改变排序规则为降序
    sort(v.begin(), v.end(), MyCompare());

    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
//    test1();
    test2();
}