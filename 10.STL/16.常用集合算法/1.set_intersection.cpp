#include "iostream"
#include "vector"
#include "algorithm"
#include "numeric"

using namespace std;

/**
 * 求两个容器交集
 */
void print(int val) {
    cout << val << " ";
}

void test() {
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
        v2.push_back(i + 5);
    }
    vector<int> vTarget;
    //需要提前开辟空间
    vTarget.resize(min(v1.size(), v2.size()));
    vector<int>::iterator itBegin = vTarget.begin();
    //求交集，返回结束位置，要使用这个
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), itBegin);

    for_each(itBegin, itEnd, print);
}

int main() {
    test();
}