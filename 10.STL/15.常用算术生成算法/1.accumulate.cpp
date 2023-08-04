#include "iostream"
#include "vector"
#include "algorithm"
#include "numeric"

using namespace std;

/**
 * 计算容器内元素总和
 */

void test() {
    vector<int> v;
    for (int i = 0; i <= 100; i++) {
        v.push_back(i);
    }
    //0是初始值
    int total = accumulate(v.begin(), v.end(), 0);
    cout << total << endl;
}

int main() {
    test();
}