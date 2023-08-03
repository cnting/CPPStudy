#include "iostream"
#include "vector"
#include "algorithm"
#include "numeric"

using namespace std;

/**
 * 求两个容器差集
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
    vTarget.resize(max(v1.size(), v2.size()));
    vector<int>::iterator itBegin = vTarget.begin();
    cout << "v1和v2的差集(v1中存在v2的都移除掉)" << endl;
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), itBegin);
    for_each(itBegin, itEnd, print);
    cout << endl;

    cout << "v2和v1的差集(v2中存在v1的都移除掉)" << endl;
    itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), itBegin);
    for_each(itBegin, itEnd, print);
}

int main() {
    test();
}