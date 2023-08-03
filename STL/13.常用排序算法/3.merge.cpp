#include "iostream"
#include "vector"
#include "algorithm"
#include "ctime"

using namespace std;

/**
 * 将两个容器合并到一起，这两个容器必须是有序的，且顺序是一致的
 */
void print(int val) {
    cout << val << " ";
}

void test() {
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
        v2.push_back(i + 1);
    }

    vector<int> vTarget;
    //注意这里
    vTarget.resize(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), print);
    cout << endl;
}

int main() {
    test();
}